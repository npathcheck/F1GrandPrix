#include "cGame.h"

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
	
	glLoadIdentity();

	glPushMatrix();

	gothicLoader.show3ds(0, 0, 0, 0, 1);

	glPopMatrix();

	glutSwapBuffers();							

}
