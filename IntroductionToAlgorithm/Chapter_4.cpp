#include "stdafx.h"
#include "Chapter_4.h"
#include "algorithm"



SubarrayFlag::SubarrayFlag(int lowidx, int highidx, int finditemval)
{
	this->LowIndex = lowidx;
	this->HighIndex = highidx;
	this->FindItemVal = finditemval;
}

SubarrayFlag* Find_Crossing_SubArray(vector<int> A, int startidx, int mididx, int endidx)
{
	int leftsum = INT_MIN;
	int sum = 0;
	int maxleft = mididx;
	for (int i = mididx; i >= startidx; i--)
	{
		sum += A[i];
		if (sum > leftsum)
		{
			leftsum = sum;
			maxleft = i;
		}
	}
	int rightsum = INT_MIN;
	sum = 0;
	int maxright = mididx + 1;
	for (int j = mididx + 1; j <= endidx; j++)
	{
		sum += A[j];
		if (sum > rightsum)
		{
			rightsum = sum;
			maxright = j;
		}
	}
	return new SubarrayFlag(maxleft, maxright, leftsum + rightsum);	
}

SubarrayFlag* FindMaxiMum_SubArray(vector<int> A, int startidx, int endidx)
{
	if (startidx == endidx)
	{
		return new SubarrayFlag(startidx, endidx, A[startidx]);
	}
	else
	{
		int mididx = (startidx + endidx) / 2;
		SubarrayFlag* leftSubArrayFlag = FindMaxiMum_SubArray(A, startidx, mididx);
		SubarrayFlag* rightSubArrayFlag = FindMaxiMum_SubArray(A, mididx + 1, endidx);
		SubarrayFlag* crossSubArrayFlag = Find_Crossing_SubArray(A, startidx, mididx, endidx);
		if (leftSubArrayFlag->FindItemVal >= rightSubArrayFlag->FindItemVal&&leftSubArrayFlag->FindItemVal >= crossSubArrayFlag->FindItemVal)
		{
			return leftSubArrayFlag;
		}
		else if (rightSubArrayFlag->FindItemVal >= leftSubArrayFlag->FindItemVal&&
			rightSubArrayFlag->FindItemVal >= crossSubArrayFlag->FindItemVal)
		{
			return rightSubArrayFlag;
		}
		else
		{
			return crossSubArrayFlag;
		}

	}

}

//生成随机矩阵
vector<vector<int>> genRandomSquareMatrix(int n,int par1,int par2)
{
	vector<vector<int>> result(n);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//result[i].push_back((rand() % n) * 12 + 6);
			result[i].push_back((rand() % n) * par1 + par2);
		}		
	}
	return result;
}
//矩阵相加
vector<vector<int>> addSquareMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> C(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			C[i].push_back(A[i][j] + B[i][j]);
		}
	}
	return C;
}
//打印矩阵
void printSquareMatrix(vector<vector<int>> A)
{
	cout << endl;
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "    ";
		}
		cout << endl;
	}
}
//打印矩阵
void printSquareMatrix(vector<vector<int>> A,int rowidx,int colidx,int n)
{
	cout << endl;
	for (int i = rowidx; i < rowidx+n; i++)
	{
		for (int j = colidx; j < colidx+n; j++)
		{
			cout << A[i][j] << "    ";
		}
		cout << endl;
	}
}

//普通矩阵相乘算法
vector<vector<int>> Square_Matrix_Multiply(vector<vector<int>> A, vector<vector<int>> B)
{	
	int n = A.size();
	vector<vector<int>> result(n);
	for (int i = 0; i < n; i++)
	{		
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			result[i].push_back(sum);
		}
	}
	return result;
}
//colnum_A=rownum_B 结果数组行数为rownum_A,列数为colnum_B
vector<vector<int>> square_Matrix_Multiply_Recursive(vector<vector<int>> A, vector<vector<int>> B,
	int startrowidx_A, int startcolidx_A,
	int startrowidx_B, int startcolidx_B,
	int rownum_A,int colnum_A,int colnum_B)
{
	
	vector<vector<int>> C(rownum_A);
	if (rownum_A == 1&&colnum_B==1)
	{
		C[0].push_back(0);
		for (int i = 0; i < colnum_A; i++)
		{
			C[0][0] += A[startrowidx_A][startcolidx_A + i] * B[startrowidx_B + i][startcolidx_B];
		}		
	}
	else
	{
		int midrownum_A = rownum_A / 2;
		int midcolnum_A = colnum_A / 2;
		int midcolnum_B = colnum_B / 2;

		//C11=A11B11+A12B21
		vector<vector<int>> c11 = addSquareMatrix(
			square_Matrix_Multiply_Recursive(A, B,//A11B11
			startrowidx_A, startcolidx_A,
			startrowidx_B, startcolidx_B,
			midrownum_A,midcolnum_A,midcolnum_B), 
			square_Matrix_Multiply_Recursive(A, B,//A12B21
			startrowidx_A, startcolidx_A + midcolnum_A,
			startrowidx_B + midcolnum_A, startcolidx_B,
			midrownum_A,colnum_A-midcolnum_A,midcolnum_B));//A11B11+A12B21
		//C12=A11B12+A12B22
		vector<vector<int>> c12 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A,
			startrowidx_B, startcolidx_B + midcolnum_B,
			midrownum_A,midcolnum_A,colnum_B-midcolnum_B), 
			square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A + midcolnum_A,
			startrowidx_B + midcolnum_A, startcolidx_B + midcolnum_B,
			midrownum_A,colnum_A-midcolnum_A,colnum_B-midcolnum_B));
		//C21=A21B11+A22B21
		vector<vector<int>> c21 = addSquareMatrix(
			square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A+midrownum_A, startcolidx_A,
			startcolidx_A, startcolidx_B,
			rownum_A-midrownum_A,midcolnum_A,midcolnum_B), 
			square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A + midrownum_A, startcolidx_A + midcolnum_A,
			startrowidx_B + midcolnum_A, startcolidx_B,
			rownum_A-midrownum_A,colnum_A-midcolnum_A,midcolnum_B));
		//C22=A21B12+A22B22
		vector<vector<int>> c22 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A + midrownum_A, startcolidx_A,
			startrowidx_B, startcolidx_B + midcolnum_B,
			rownum_A-midrownum_A,midcolnum_A,colnum_B-midcolnum_B), 
			square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A + midrownum_A, startcolidx_A + midcolnum_A,
			startrowidx_B + midcolnum_A, startcolidx_B + midcolnum_B,
			rownum_A-midrownum_A,colnum_A-midcolnum_A,colnum_B-midcolnum_B));

		for (int i = 0; i < rownum_A; i++)
			for (int j = 0; j < colnum_B; j++)
				C[i].push_back(i < midrownum_A ? (j < midcolnum_B ? c11[i][j] : c12[i][j - midcolnum_B]) : (j < midcolnum_B ? c21[i - midrownum_A][j] : c22[i - midrownum_A][j - midcolnum_B]));

	}
	/*cout << "C矩阵：";
	printSquareMatrix(C);*/
	return C;
}
	

vector<vector<int>> square_Matrix_Multiply_Recursive(vector<vector<int>> A, vector<vector<int>> B, 
	int startrowidx_A, int startcolidx_A,
	int startrowidx_B,int startcolidx_B,
	int n)
{
	//std::cout << std::endl << "计算部分矩阵相乘结果：rowidxA="<<startrowidx_A<<",colidxA="<<startcolidx_A<<",rowidxB="<<startrowidx_B<<",colidxB="<<startcolidx_B<<",n="<<n << std::endl;
	//cout << "A矩阵：";
	//printSquareMatrix(A,startrowidx_A,startcolidx_A,n);
	//cout << "B矩阵：";
	//printSquareMatrix(B,startrowidx_B,startcolidx_B,n);
	vector<vector<int>> C(n);
	if (n == 1)
	{
		C[0].push_back(A[startrowidx_A][startcolidx_A]*B[startrowidx_B][startcolidx_B]);
	}
	else
	{
		int midn = n / 2;
		//C11=A11B11+A12B21
		vector<vector<int>> c11 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A,
			startrowidx_B, startcolidx_B,
			midn), square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A + midn,
			startrowidx_B + midn, startcolidx_B,
			n - midn));//A11B11+A12B21
		//C12=A11B12+A12B22
		vector<vector<int>> c12 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A,
			startrowidx_B, startcolidx_B+midn,
			n-midn), square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A + midn,
			startrowidx_B + midn, startcolidx_B+midn,
			n - midn));
		//C21=A21B11+A22B21
		vector<vector<int>> c21 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A, startcolidx_A+midn,
			startrowidx_B, startcolidx_B,
			n - midn), square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A+midn, startcolidx_A + midn,
			startrowidx_B + midn, startcolidx_B,
			n - midn));
		//C22=A21B12+A22B22
		vector<vector<int>> c22 = addSquareMatrix(square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A+midn, startcolidx_A,
			startrowidx_B, startcolidx_B+midn,
			n - midn), square_Matrix_Multiply_Recursive(A, B,
			startrowidx_A + midn, startcolidx_A + midn,
			startrowidx_B + midn, startcolidx_B+midn,
			n - midn));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i].push_back(i < midn ? (j < midn ? c11[i][j] : c12[i][j - midn]) : (j < midn ? c21[i - midn][j] : c22[i - midn][j - midn]));

	}
	/*cout << "C矩阵：";
	printSquareMatrix(C);*/
	return C;
}

//普通递归矩阵相乘算法
vector<vector<int>> Square_Matrix_Multiply_Recursive(vector<vector<int>> A, vector<vector<int>> B)
{
	//vector<vector<int>> result = square_Matrix_Multiply_Recursive(A, B, 0, 0, 0, 0, A.size());
	vector<vector<int>> result = square_Matrix_Multiply_Recursive(A, B, 0, 0, 0, 0, A.size(), A[0].size(), B[0].size());
	return result;
}



void FindMaxiMubSubArray_MainManageHandle()
{
	vector<int> A;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		A.push_back((rand() % 100) - 50);
	}
	std::cout << std::endl << "原始数组：" << std::endl;
	for (vector<int>::size_type i = 0; i < A.size(); i++)
	{
		std::cout << A[i] << " ";
	}
	SubarrayFlag* findmaxmumsubarray = FindMaxiMum_SubArray(A, 0, A.size() - 1);
	std::cout << std::endl << "找到的和最大子数组：" << std::endl;
	for (int k = findmaxmumsubarray->LowIndex; k <= findmaxmumsubarray->HighIndex; k++)
	{
		std::cout << A[k] << ",";
	}

	std::cout << std::endl << "最大子数组和：" << findmaxmumsubarray->FindItemVal << endl << endl;

}

void Square_Matrix_Multiply_MainManageHandle()
{
	vector<vector<int>> A = genRandomSquareMatrix(6,1,1);
	vector<vector<int>> B = genRandomSquareMatrix(6,2,5);
	cout << "A矩阵：";
	printSquareMatrix(A);
	cout << "B矩阵：";
	printSquareMatrix(B);
	vector<vector<int>> C = Square_Matrix_Multiply(A, B);
	cout << "叉乘结果矩阵：";
	printSquareMatrix(C);
	
}
void Square_Matrix_Multiply_Recursive_MainManageHandle()
{
	vector<vector<int>> A = genRandomSquareMatrix(3, 1, 1);
	vector<vector<int>> B = genRandomSquareMatrix(3, 2, 3);
	cout << "A矩阵：";
	printSquareMatrix(A);
	cout << "B矩阵：";
	printSquareMatrix(B);
	vector<vector<int>> C = Square_Matrix_Multiply_Recursive(A, B);
	cout << "二分递归叉乘结果矩阵：";
	printSquareMatrix(C);
	vector<vector<int>> C1 = Square_Matrix_Multiply(A, B);
	cout << "普通叉乘结果矩阵：";
	printSquareMatrix(C1);
}