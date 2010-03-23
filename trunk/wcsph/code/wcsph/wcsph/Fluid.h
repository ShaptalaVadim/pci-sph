/**
* Copyright (c) 2001,SJTU
* All rights reserved.
*
* @file Particle.h
* @date 2009/07/01
* @author SJTU_SPH_group
*/

#ifndef FLUID_H
#define FLUID_H

#include<Vector>
#include"Particle.h"
#include "mtxlib.h"
#include "SmoothKernel.h"
#include "Poly6SmoothKernel.h"
#include "SpikySmoothKernel.h"
#include "ViscositySmoothKernel.h"

#define CELL_SIZE 10	//���ֵ�cell����Ϊ10*10*10
#define INIT_NUM 500	//��ʼ����������
#define MIN_DENSITY 0.01 //������С���ܶ�
/**
* @brief ����ϵͳ
**/
class Fluid{
public:
	std::vector<Particle*> particles;								//��������
	int neighbors[INIT_NUM][INIT_NUM];								//All the neighbors information,NEED TO UPDATE IN THE FUTURE
	std::vector<Particle*> cell[CELL_SIZE][CELL_SIZE][CELL_SIZE];		//��¼ÿ��cell������
	float worldSize;												//������С							
	float particleSize;												//���Ƶ����Ӵ�С
	float jumpFactor;												//����ǽ�ڷ�����ϵ��
	float viscosityFactor;											//ճ��ϵ��
	float pressureFactor;											//ѹǿϵ��
	float densityRest;												//ʣ���ܶȵĵ�������
	float surfaceFactor;											//��������ϵ��
	float surfaceThreshold;											//�������ֵ
	float viscosity_h;												//ճ�������÷�Χ
	float pressure_h;												//ѹǿ���÷�Χ
	float surface_h;												//�����������÷�Χ
	float density_h;												//�����ܶȷ�Χ
	float k_value;                                                  //The value of k when computing pressure
	float s_density;														//The standard density value

	SmoothKernel* skp;											//��ʾsmoothkernel��ָ��
	Poly6SmoothKernel* pskp;
	SpikySmoothKernel* sskp;
	ViscositySmoothKernel* vskp;

	Fluid();
	~Fluid();
	
	void init();		//��ʼ��
	void render(int t);		//��Ⱦ
	void updateDensity();
	void updateCell();
	void initNeighbors();   //�ҵ����е����Χ����
	void caculateNextFrame(int t);
	void addParticles(std::vector<Particle*> newParticles);

	vector3 getPressure(Particle * particle);
	vector3 getViscosity(Particle * particle);
	vector3 getSurface(Particle * particle);
	vector3 getExternalForce();

};

#endif