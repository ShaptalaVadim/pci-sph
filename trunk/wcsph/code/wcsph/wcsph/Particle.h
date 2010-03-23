/**
* Copyright (c) 2001,SJTU
* All rights reserved.
*
* @file Particle.h
* @date 2009/07/01
* @author SJTU_SPH_group
*/

#ifndef PARTICLE_H
#define PARTICLE_H
#include "mtxlib.h"

/**
* @brief ���������
**/
class Particle{
public:
	vector3 pos;			//����λ��
	vector3 velocity;		//�����ٶ�
	vector3 acceleration;	//���Ӽ��ٶ�
	float density;			//�����ܶ�
	float pressure;			//The pressure of the particle
	float mass;				//��������
	float r,g,b;			//������ɫ
	bool isSurface;			//�����Ƿ��Ǳ߽��

	Particle();
	
	~Particle();

};



#endif