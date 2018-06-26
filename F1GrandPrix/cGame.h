
#ifndef __CGAME_H__
#define __CGAME_H__

#include "main.h"
#include "3DS.H"

class cGame
{
public:
	cGame();
	~cGame();
	void Init();
	void DisplayFunc();

private:
	CLoad3DS gothicLoader;
	t3DModel gothicModel;
};




#endif