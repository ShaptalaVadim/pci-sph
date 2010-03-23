// �ڴ˴����ó���Ҫ��ĸ���ͷ�ļ�:
#include "BasicWindow.h"
#include "Texture.h"
#include "Fluid.h"

// �ڴ˴��������Ҫ��Ŀ⵽��������:
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

// �ڴ˴�����ȫ�ֱ���:
GL_Window*	OGL_window;
Keys*		OGL_keys;

// �ڴ˴������û�����:
Fluid* fluid;
int timestep;

BOOL Initialize(GL_Window* window, Keys* keys)						// ��ʼ������
{
	// ����ȫ�ֱ���
	OGL_window	= window;
	OGL_keys	= keys;
	fluid = new Fluid();
	timestep = 1000;

	// �ڴ˴���ʼ�����Ƴ���
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);							// ����Ϊ��ɫ
	glClearDepth(1.0f);												// ������Ȼ���
	glEnable(GL_DEPTH_TEST);//glDisable(GL_DEPTH_TEST);										// �ر���Ȳ���
	glShadeModel(GL_SMOOTH);										// �����������ƽ����ʽ
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);				// �ϸ��͸�Ӽ���	

	return TRUE;													// ��ʼ���ɹ�����TRUE
}

void DrawSceneGL(void)												// ���Ƴ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// �����ɫ����Ȼ���
	glLoadIdentity();												// ���õ�ǰ����

	// �ڴ˴���Ӵ�����л���:
	glTranslatef(-5.0f,-5.0f,-30.0f);
	fluid->render(timestep);

	glFlush();														// ˢ��GL�������
}

void Update()														// �ڴ˴����¶���Ϣ�Ķ���
{
	if (OGL_keys->keyDown[VK_ESCAPE] == TRUE)						// �ж�ESC���Ƿ���
	{
		TerminateApplication(OGL_window);							// �������� 	   
	}

	if (OGL_keys->keyDown[VK_F1] == TRUE)							// �ж�F1�Ƿ���
	{
		PostMessage(OGL_window->hWnd, WM_TOGGLEFULLSCREEN, 0, 0);	// ��ȫ��/����ģʽ���л�
	}
}

void Deinitialize(void)												// �ڴ˴����˳�ǰɨβ����
{

}