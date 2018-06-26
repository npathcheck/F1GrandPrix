
#include "main.h"
#include "cGame.h"

// ���ÿ���̨����
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
	glViewport(0, 0, w, h);//�����ӿ�
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void my_init(void) {

	glMaterialfv(GL_FRONT, GL_SPECULAR, reflection);//���û�������ɫ
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);//���þ���ָ��
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);//�������������ɫ

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Model_Ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, position1);//���ù�Դλ��
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light1);//����������ɷ�
	glLightfv(GL_LIGHT0, GL_SPECULAR, light1);//���þ��淴��ɷ�
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);//���û�����
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.);


	glLightfv(GL_LIGHT1, GL_POSITION, position2);//���ù�Դλ��
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light2);//����������ɷ�
	glLightfv(GL_LIGHT1, GL_SPECULAR, light2);//���þ��淴��ɷ�
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2);//���û�����
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.); //

	glClearColor(0, 0, 0, 0);//�趨����Ϊ��ɫ
	glClearDepth(10);//������
	glEnable(GL_LIGHTING);//��������
	glEnable(GL_LIGHT0);//������Դ0
	glEnable(GL_LIGHT1);//������Դ1
	glEnable(GL_DEPTH_TEST);//������Ȼ���
	glShadeModel(GL_SMOOTH);//ƽ��ģʽ
}

void MotionFunc(int x, int y) {
	if (mousestate) {//�������λ�ý�����ת
		yr += x - Oldx;
		printf("��ת��yrΪ��%d", yr);
		glutPostRedisplay();
		Oldx = x;
		xr += y - Oldy;
		printf("��ת��yrΪ��%d", xr);
		glutPostRedisplay();
		Oldy = y;
	}
}

void MouseFunc(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mousestate = 1;//�������λ�ý�����ת
		Oldx = x;
		Oldy = y;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mousestate = 0;
	}
	if (state == GLUT_UP && button == 3) {
		s -= 0.01;//���������¹��������С
		printf("��ǰ��sΪ%f", s);
	}
	if (state == GLUT_UP && button == 4) {
		s += 0.01;//���������Ϲ�������Ŵ�
		printf("��ǰ��sΪ%f", s);
	}
	glutPostRedisplay();
}

void SpecialFunc(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		ty += 0.5;//�����������ϰ��£� �����ƶ�
	}
	if (key == GLUT_KEY_DOWN) {
		ty -= 0.5;//�����������°��£� �����ƶ�
	}
	if (key == GLUT_KEY_LEFT) {
		tx -= 0.5;//�������������£� �����ƶ�
	}
	if (key == GLUT_KEY_RIGHT) {
		tx += 0.5;//�����������Ұ��£� �����Ҷ�
	}
	glutPostRedisplay();
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

	my_init();

	glutDisplayFunc(DisplayFunc);			// ��ͼ�¼�

	glutMouseFunc(MouseFunc);				// ����¼�

	glutMotionFunc(MotionFunc);			// ����ƶ��¼�

	glutSpecialFunc(SpecialFunc);			// ��������¼�

	glutReshapeFunc(ReshapeFunc);			// ���ڴ�С�ػ��¼�

	glutMainLoop();							// ����GLUT�¼�����ѭ��

	return 0;
}