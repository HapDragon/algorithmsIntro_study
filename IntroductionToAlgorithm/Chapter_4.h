#pragma once
#include "stdafx.h"

#include <vector>
#include <climits>
#include <ctime>
using namespace std;


struct SubarrayFlag
{
	int LowIndex;
	int HighIndex;
	int FindItemVal;
	SubarrayFlag(int lowidx, int highidx, int finditemval);
};

//��ѯ�����������
void FindMaxiMubSubArray_MainManageHandle();
//���������ͨ�㷨
void Square_Matrix_Multiply_MainManageHandle();
//������˵ݹ��㷨
void Square_Matrix_Multiply_Recursive_MainManageHandle();


