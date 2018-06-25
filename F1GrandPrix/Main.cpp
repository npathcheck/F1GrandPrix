
#include "main.h"
#include "cGame.h"

// 禁用控制台窗口
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

cGame Game;

void Init()
{
	Game.Init();
}

void DisplayFunc()
{
	Game.DisplayFunc();
}



int main(int argc, char** argv)
{

	// 初始化 GLUT 库
	glutInit(&argc, argv);

	// 设置初始显示模式为RGB颜色模式，使用双缓存和深度缓存
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	// 设置窗口的大小
	glutInitWindowSize(winWidth, winHeight);

	// 设置窗口的初始位置居中
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - winWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - winHeight) / 2);

	// 设置窗口的标题
	glutCreateWindow("F1方程式");

	// 自定义初始化
	Init();

	glutDisplayFunc(DisplayFunc);			// 绘图事件

	//glutMouseFunc(MouseFunc);				// 鼠标事件

	//glutMotionFunc(MotionFunc);			// 鼠标移动事件

	//glutSpecialFunc(SpecialFunc);			// 特殊键盘事件

	//glutReshapeFunc(ReshapeFunc);			// 窗口大小重绘事件

	glutMainLoop();							// 进入GLUT事件处理循环

	return 0;
}