#include "cGame.h"

extern GLfloat xr;
extern GLfloat yr;
extern GLfloat tx;
extern GLfloat ty;
extern GLfloat s;


cGame::cGame() {}

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

	gothicLoader.Init("williams.3DS", 0);
}

void cGame::DisplayFunc()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//glRotatef(30, 1, 0, 0);

	//glRotatef(90, 0, 1, 0);

	glRotatef(xr, 1, 0, 0);
	glRotatef(yr, 0, 1, 0);

	glTranslatef(tx, ty, 0);

	glScalef(0.04, 0.04, 0.04);//½øÐÐËõ·Å

	gothicLoader.show3ds(0, 0, 0, 0, 1);

	glPopMatrix();

	glutSwapBuffers();							

}
