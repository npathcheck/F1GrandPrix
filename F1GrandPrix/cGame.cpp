#include "cGame.h"

cGame::cGame() {}

cGame::~cGame() {}

void cGame::Init()
{
	glViewport(0, 0, winWidth, winHeight);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(54.0f, (GLfloat)winWidth / (GLfloat)winHeight, 0.1f, 3000.0f);
	
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();					
}

void cGame::DisplayFunc()
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glutSwapBuffers();							

}
