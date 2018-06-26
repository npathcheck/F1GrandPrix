
#include "main.h"
#include "cGame.h"

// 禁用控制台窗口
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

cGame Game;

GLfloat reflection[4] = { 0.5, 0.5, 1, 1 };
GLfloat shine[] = { 50 };
GLfloat diffuse[] = { 0.85, 0.65, 0.2 };

GLfloat position1[] = { 10, 0, 8, 0 };
GLfloat light1[] = { 1, 1, 1, 1 };
GLfloat ambient1[] = { 0.3, 0.3, 0.8, 1.0 };

GLfloat position2[] = { -100, 0, 8, 1 };
GLfloat light2[] = { 1, 1, 1, 1 };
GLfloat ambient2[] = { 0.6, 0.5, 0.8, 1.0 };

GLfloat Model_Ambient[] = { 0.2 , 0.2 , 0.2 , 1.0 };

GLfloat s = 1;
int mousestate = 0;
GLfloat Oldx = 0;
GLfloat Oldy = 0;
GLfloat xr = 0;
GLfloat yr = 0;
GLfloat tx = 0;
GLfloat ty = 0;


void Init()
{
	Game.Init();
}

void DisplayFunc()
{
	Game.DisplayFunc();
}

void ReshapeFunc(int w, int h) {
	glViewport(0, 0, w, h);//设置视口
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void my_init(void) {

	glMaterialfv(GL_FRONT, GL_SPECULAR, reflection);//设置环境光颜色
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);//设置镜面指数
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);//设置漫反射光颜色

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Model_Ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, position1);//设置光源位置
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light1);//设置漫反射成分
	glLightfv(GL_LIGHT0, GL_SPECULAR, light1);//设置镜面反射成分
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);//设置环境光
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.);


	glLightfv(GL_LIGHT1, GL_POSITION, position2);//设置光源位置
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light2);//设置漫反射成分
	glLightfv(GL_LIGHT1, GL_SPECULAR, light2);//设置镜面反射成分
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);//设置环境光
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.); //

	glClearColor(0, 0, 0, 0);//设定背景为黑色
	glClearDepth(10);//深度清除
	glEnable(GL_LIGHTING);//开启光照
	glEnable(GL_LIGHT0);//启动光源0
	glEnable(GL_LIGHT1);//启动光源1
	glEnable(GL_DEPTH_TEST);//开启深度缓冲
	glShadeModel(GL_SMOOTH);//平滑模式
}

void MotionFunc(int x, int y) {
	if (mousestate) {//根据鼠标位置进行旋转
		yr += x - Oldx;
		printf("旋转的yr为：%d", yr);
		glutPostRedisplay();
		Oldx = x;
		xr += y - Oldy;
		printf("旋转的yr为：%d", xr);
		glutPostRedisplay();
		Oldy = y;
	}
}

void MouseFunc(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mousestate = 1;//根据鼠标位置进行旋转
		Oldx = x;
		Oldy = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mousestate = 0;
	}
	if (state == GLUT_UP && button == 3) {
		s -= 0.01;//鼠标滚轮向下滚，茶壶缩小
		printf("当前的s为%f", s);
	}
	if (state == GLUT_UP && button == 4) {
		s += 0.01;//鼠标滚轮向上滚，茶壶放大
		printf("当前的s为%f", s);
	}
	glutPostRedisplay();
}

void SpecialFunc(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		ty += 0.5;//如果方向键向上按下， 向上移动
	}
	if (key == GLUT_KEY_DOWN) {
		ty -= 0.5;//如果方向键向下按下， 向下移动
	}
	if (key == GLUT_KEY_LEFT) {
		tx -= 0.5;//如果方向键向左按下， 向左移动
	}
	if (key == GLUT_KEY_RIGHT) {
		tx += 0.5;//如果方向键向右按下， 向移右动
	}
	glutPostRedisplay();
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
	glutCreateWindow("OpenGL");

	// 自定义初始化
	Init();

	my_init();

	glutDisplayFunc(DisplayFunc);			// 绘图事件

	glutMouseFunc(MouseFunc);				// 鼠标事件

	glutMotionFunc(MotionFunc);			// 鼠标移动事件

	glutSpecialFunc(SpecialFunc);			// 特殊键盘事件

	glutReshapeFunc(ReshapeFunc);			// 窗口大小重绘事件

	glutMainLoop();							// 进入GLUT事件处理循环

	return 0;
}