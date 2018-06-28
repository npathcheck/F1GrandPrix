
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

	//// ------------------- 定义模型
	CLoad3DS gothicLoader;
	t3DModel gothicModel;

	//// ------------------- 初始化光源
	void InitLight();
	void InitMaterialProperty();
	void InitLightSource();
	void InitLightingModel();

	//// ------------------- 定义材质属性 material property
	GLfloat mat_AMBIENT[4]   = { 0.2f, 0.2f, 0.2f, 1.0f };				// 材质的环境颜色 
	GLfloat mat_DIFFUSE[4]   = { 0.8f, 0.8f, 0.8f, 1.0f };				// 材质的散射颜色
	GLfloat mat_SPECULAR[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };				// 材质的镜面颜色
	GLfloat mat_SHININESS[1] = { 50.0f };								// 材质的镜面反射指数

	//// ------------------- 定义光源 light source
	GLfloat light_AMBIENT[4]  = { 0.2f, 0.2f, 0.2f, 1.0f };				// 光源的环境光属性
	GLfloat light_DIFFUSE[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };				// 光源的散射光属性
	GLfloat light_SPECULAR[4] = { 1.0f, 1.0f, 1.0f, 1.0f };				// 光源的镜面反射光属性
	GLfloat light_POSITION[4] = { 1.0f, 1.0f, 1.0f, 0.0f };				// 光源的位置属性

	//// ------------------- 定义光照模型 lighting model
	GLfloat light_Model_Ambient[4] = { 0.2f , 0.2f , 0.2f , 1.0f };		// 光照模型


	//// ------------------- 鼠标交互
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