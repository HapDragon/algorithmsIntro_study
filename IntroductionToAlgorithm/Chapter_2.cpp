//2.1插入排序函数


#include "stdafx.h"
#include "Chapter_2.h"
#include "algorithm"

void merge(vector<int>* A, int startidx, int mididx, int endidx)
{
	vector<int> L(mididx - startidx + 2);
	for (int i = startidx; i <= mididx; i++)
	{
		L[i - startidx] = (*A)[i];
	}
	L[mididx - startidx + 1] = INT_MAX;
	vector<int> R(endidx - mididx + 1);
	for (int i = mididx + 1; i <= endidx; i++)
	{
		R[i - mididx - 1] = (*A)[i];
	}
	R[endidx - mididx] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = startidx; k <= endidx; k++)
	{
		if (L[i] < R[j])
		{
			(*A)[k] = L[i];
			i++;
		}
		else
		{
			(*A)[k] = R[j];
			j++;
		}
	}

}

void Insertion_Sort(vector<int>* A)
{
	//sort(A->begin(), A->end());//使用sort方法排序
	for (vector<int>::size_type j = 1; j < A->size(); j++)
	{
		int key = (*A)[j];
		int i = j - 1;
		
		while (i >= 0 && (*A)[i] > key)
		{
			(*A)[i + 1] = (*A)[i];
			i = i - 1;
		}
		(*A)[i + 1] = key;
	}	
}

void Merge_Sort(vector<int>* A, int startidx, int endidx)
{
	if (startidx < endidx)
	{
		int mididx = (startidx + endidx) / 2;
		Merge_Sort(A, startidx, mididx);
		Merge_Sort(A, mididx + 1, endidx);
		merge(A, startidx, mididx, endidx);
	}
}


void MergeSort_MainManageHandle()
{
	vector<int> A;
	srand(time(0));
	for (int i = 0; i < 50; i++)
	{
		A.push_back(rand() % 100);
	}
	cout << endl << "原始数组：" << endl;
	for (vector<int>::size_type i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	Merge_Sort(&A, 0, A.size() - 1);
	cout << endl << "排序结果：" << endl;
	for (vector<int>::size_type i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
}
void InsertSort_MainManageHandle()
{
	vector<int> A;
	srand(time(0));
	for (int i = 0; i < 50; i++)
	{
		A.push_back(rand() % 100);
	}
	cout << endl << "原始数组：" << endl;
	for (vector<int>::size_type i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	Insertion_Sort(&A);
	cout << endl << "排序结果：" << endl;
	for (vector<int>::size_type i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
}
