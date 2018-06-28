#include "main.h"
#include "cGame.h"

cGame::cGame() 
{
	gothicModel.numOfMaterials = 0;
	gothicModel.numOfObjects = 0;
}

cGame::~cGame() {}

void cGame::Init()
{
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)winWidth / (GLfloat)winHeight, 0.1f, 3000.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	InitLight();

	gothicLoader.Init("williams.3DS", 0);

}

void cGame::InitLight()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// ���ñ�����ɫΪ��ɫ

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����ɫ�������Ȼ���

	glShadeModel(GL_SMOOTH);							// ������ɫ��ʽΪGL_SMOOTH

	InitMaterialProperty();								// ��ʼ����������

	InitLightSource();									// ��ʼ����Դ����

	InitLightingModel();								// ��ʼ������ģ��

	glEnable(GL_LIGHTING);								// ���ù���

	glEnable(GL_LIGHT0);								// ����ָ����Դ��0�Ź�Դ

	glEnable(GL_DEPTH_TEST);							// ������Ȼ�����ԣ�һ������3D��ͼ
}

void cGame::InitMaterialProperty()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_AMBIENT);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_SPECULAR);

	glMaterialfv(GL_FRONT, GL_SHININESS, mat_SHININESS);
}


void cGame::InitLightSource()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_AMBIENT);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_DIFFUSE);

	glLightfv(GL_LIGHT0, GL_SPECULAR, light_SPECULAR);

	glLightfv(GL_LIGHT0, GL_POSITION, light_POSITION);
}


void cGame::InitLightingModel()
{
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_Model_Ambient);
}

void cGame::DisplayFunc()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glRotatef(rotateX, 1.0f, 0.0f, 0.0f);					// ��ת
	glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, moveY, 0.0f);						// ƽ��
	glTranslatef(0.0f, 0.0f, moveZ);

	glScalef(scale, scale, scale);							// ����

	gothicLoader.show3ds(0, 0, 0, 0, 0.01);

	glPopMatrix();

	glutSwapBuffers();

}

void cGame::MouseFunc(int button, int state, int x, int y)
{
	// �����������¼�
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		previousX = x;
		previousY = y;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		mouseDown = false;

	// �������¼�
	if (state == GLUT_UP && button == GLUT_WHEEL_UP)
		scale += 0.1;

	if (state == GLUT_UP && button == GLUT_WHEEL_DOWN)
		scale -= 0.1;

	// ���ص���������������¼���,��ʾ�������Զ�������,��Ļ�ᱻ�ػ�
	glutPostRedisplay();

}

void cGame::MotionFunc(int x, int y)
{
	if (mouseDown)
	{
		rotateY += x - previousX;
		glutPostRedisplay();
		previousX = x;

		rotateX += y - previousY;
		glutPostRedisplay();
		previousY = y;
	}
}

void cGame::SpecialFunc(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		moveZ += 0.01;
		break;
	case GLUT_KEY_RIGHT:
		moveZ -= 0.01;
		break;
	case GLUT_KEY_UP:
		moveY += 0.01;
		break;
	case GLUT_KEY_DOWN:
		moveY -= 0.01;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void cGame::ReshapeFunc(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w / (GLfloat)h, 1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
}