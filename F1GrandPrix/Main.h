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


//// ------------------- 模型文件
#define fileName "williams.3ds"

//// ------------------- 窗口参数
#define winWidth 800
#define winHeight 600
#define winDepth 16

//// ------------------- 定义滚轮操作  
#define  GLUT_WHEEL_UP 3           
#define  GLUT_WHEEL_DOWN 4

//// ------------------- 定义纹理 
#define MAX_TEXTURES 100


#endif