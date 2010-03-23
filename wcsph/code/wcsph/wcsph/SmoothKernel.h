#pragma once
#include "mtxlib.h"
#include "math.h"
#define PAI    3.1415926

/**
���ദ��Smoothing Kernel�ļ���
����Ϊ���࣬����ʵ����������
*/
class SmoothKernel
{
public:
	SmoothKernel(void);
	virtual ~SmoothKernel(void);

public:
	virtual vector3 getValue(vector3 *r_i, vector3 *r_j, float h_size)=0;
	virtual vector3 getGrads(vector3 *r_i, vector3 *r_j, float h_size)=0;
	virtual vector3 getLaplacian(vector3 *r_i, vector3 *r_j, float h_size)=0;
};
