
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
	glutCreateWindow("F1����ʽ");

	// �Զ����ʼ��
	Init();

	glutDisplayFunc(DisplayFunc);			// ��ͼ�¼�

	//glutMouseFunc(MouseFunc);				// ����¼�

	//glutMotionFunc(MotionFunc);			// ����ƶ��¼�

	//glutSpecialFunc(SpecialFunc);			// ��������¼�

	//glutReshapeFunc(ReshapeFunc);			// ���ڴ�С�ػ��¼�

	glutMainLoop();							// ����GLUT�¼�����ѭ��

	return 0;
}