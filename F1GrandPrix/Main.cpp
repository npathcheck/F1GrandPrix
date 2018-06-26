#include "main.h"
#include "cGame.h"

// ���ÿ���̨����
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

void MouseFunc(int button, int state, int x, int y)
{
	Game.MouseFunc(button, state, x, y);
}

void MotionFunc(int x, int y)
{
	Game.MotionFunc(x, y);
}

void SpecialFunc(int key, int x, int y)
{
	Game.SpecialFunc(key, x, y);
}

void ReshapeFunc(int w, int h)
{
	Game.ReshapeFunc(w, h);
}


int main(int argc, char** argv)
{

	// ��ʼ�� GLUT ��
	glutInit(&argc, argv);

	// ���ó�ʼ��ʾģʽΪRGB��ɫģʽ��ʹ��˫�������Ȼ���
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	// ���ô��ڵĴ�С
	glutInitWindowSize(winWidth, winHeight);

	// ���ô��ڵĳ�ʼλ�þ���
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - winWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - winHeight) / 2);

	// ���ô��ڵı���
	glutCreateWindow("OpenGL");

	// �Զ����ʼ��
	Init();

	glutDisplayFunc(DisplayFunc);			// ��ͼ�¼�

	glutMouseFunc(MouseFunc);				// ����¼�

	glutMotionFunc(MotionFunc);				// ����ƶ��¼�

	glutSpecialFunc(SpecialFunc);			// ��������¼�

	glutReshapeFunc(ReshapeFunc);			// ���ڴ�С�ػ��¼�

	glutMainLoop();							// ����GLUT�¼�����ѭ��

	return 0;
}