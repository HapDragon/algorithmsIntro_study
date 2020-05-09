// IntroductionToAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Chapter_2.h"
#include "Chapter_4.h"

void showindex()
{
	cout << endl << "------------------------------------------" << endl;
	cout << "请输入算法序号：" << endl;
	cout << "1：插入排序" << endl;
	cout << "2：归并排序" << endl;
	cout << "3：查询和最大子数组" << endl;
	cout << "4：普通矩阵相乘" << endl;
	cout << "5：二分递归矩阵相乘" << endl;
	cout << "0：退出" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	showindex();
	int  algorithmnum = -1;	
	 
	std::cin >> algorithmnum;
	while (algorithmnum != 0)
	{
		switch (algorithmnum)
		{
		case 1:
			InsertSort_MainManageHandle();
			break;
		case 2:
			MergeSort_MainManageHandle();
			break;
		case 3:
			FindMaxiMubSubArray_MainManageHandle();
			break;
		case 4:
			Square_Matrix_Multiply_MainManageHandle();
			break;
		case 5:
			Square_Matrix_Multiply_Recursive_MainManageHandle();
			break;
		default:
			break;
		}
		showindex();
		cin >> algorithmnum;
	}	
	
	return 0;
}



