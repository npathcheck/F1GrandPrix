
#ifndef __CGAME_H__
#define __CGAME_H__

#include "main.h"
#include "3DS.H"

class cGame
{
public:
	cGame();
	~cGame();
	void Init();
	void DisplayFunc();
	void MouseFunc(int button, int state, int x, int y);
	void MotionFunc(int x, int y);
	void SpecialFunc(int key, int x, int y);
	void ReshapeFunc(int w, int h);

private:

	//// ------------------- ����ģ��
	CLoad3DS gothicLoader;
	t3DModel gothicModel;

	//// ------------------- ��ʼ����Դ
	void InitLight();
	void InitMaterialProperty();
	void InitLightSource();
	void InitLightingModel();

	//// ------------------- ����������� material property
	GLfloat mat_AMBIENT[4]   = { 0.2f, 0.2f, 0.2f, 1.0f };				// ���ʵĻ�����ɫ 
	GLfloat mat_DIFFUSE[4]   = { 0.8f, 0.8f, 0.8f, 1.0f };				// ���ʵ�ɢ����ɫ
	GLfloat mat_SPECULAR[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };				// ���ʵľ�����ɫ
	GLfloat mat_SHININESS[1] = { 50.0f };								// ���ʵľ��淴��ָ��

	//// ------------------- �����Դ light source
	GLfloat light_AMBIENT[4]  = { 0.2f, 0.2f, 0.2f, 1.0f };				// ��Դ�Ļ���������
	GLfloat light_DIFFUSE[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };				// ��Դ��ɢ�������
	GLfloat light_SPECULAR[4] = { 1.0f, 1.0f, 1.0f, 1.0f };				// ��Դ�ľ��淴�������
	GLfloat light_POSITION[4] = { 1.0f, 1.0f, 1.0f, 0.0f };				// ��Դ��λ������

	//// ------------------- �������ģ�� lighting model
	GLfloat light_Model_Ambient[4] = { 0.2f , 0.2f , 0.2f , 1.0f };		// ����ģ��


	//// ------------------- ��꽻��
	bool   mouseDown = false;
	GLfloat previousX = 0.0f;
	GLfloat previousY = 0.0f;
	GLfloat rotateX = 0.0f;
	GLfloat rotateY = 0.0f;
	GLfloat moveY = 0.0f;
	GLfloat moveZ = 0.0f;
	GLfloat scale = 1.0f;
};




#endif