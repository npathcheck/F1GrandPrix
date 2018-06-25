
#ifndef __CGAME_H__
#define __CGAME_H__

#include "main.h"
#include "cLoad3DS.h"

class cGame
{
public:
	cGame();
	~cGame();
	void Init();
	void DisplayFunc();
	void DisplayFunc_Draw();

private:
	cLoad3DS g_Load3ds;
	t3DModel g_3DModel;
	UINT g_Texture[MAX_TEXTURES] = { 0 };
};




#endif