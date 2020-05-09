// IntroductionToAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Chapter_2.h"
#include "Chapter_4.h"

void showindex()
{
	cout << endl << "------------------------------------------" << endl;
	cout << "�������㷨��ţ�" << endl;
	cout << "1����������" << endl;
	cout << "2���鲢����" << endl;
	cout << "3����ѯ�����������" << endl;
	cout << "4����ͨ�������" << endl;
	cout << "5�����ֵݹ�������" << endl;
	cout << "0���˳�" << endl;
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



