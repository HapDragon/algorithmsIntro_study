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

//查询和最大子数组
void FindMaxiMubSubArray_MainManageHandle();
//矩阵相乘普通算法
void Square_Matrix_Multiply_MainManageHandle();
//矩阵相乘递归算法
void Square_Matrix_Multiply_Recursive_MainManageHandle();


