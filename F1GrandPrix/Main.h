#pragma warning(disable:4996)
#pragma comment(lib, "glaux.lib")

#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <GL/gl.h>										
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <crtdbg.h>
#include <vector>
#include <stdio.h>
#include <math.h>

//// ------------------- 窗口参数
#define winWidth 800
#define winHeight 600
#define winDepth 16

//// ------------------- 定义滚轮操作  
#define  GLUT_WHEEL_UP 3           
#define  GLUT_WHEEL_DOWN 4

//// ------------------- 定义模型参数
#define MAX_TEXTURES 100
#define MAX_MODEL 10


#endif