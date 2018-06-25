#include "cGame.h"

cGame::cGame() {}

cGame::~cGame() {}

void cGame::Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// ���ñ�����ɫΪ��ɫ

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// �����ɫ�������Ȼ���

	glShadeModel(GL_SMOOTH);							// ������ɫ��ʽΪGL_SMOOTH

	g_Load3ds.Import3DS(&g_3DModel, fileName);			// ��3ds�ļ�װ�뵽ģ�ͽṹ����

														// �������еĲ���
	for (int i = 0; i < g_3DModel.numOfMaterials; i++)
	{
		// �ж��Ƿ���һ���ļ���
		if (strlen(g_3DModel.pMaterials[i].strFile) > 0)
		{
			//  ʹ�������ļ�������װ��λͼ
			g_Load3ds.CreateTexture(g_Texture, g_3DModel.pMaterials[i].strFile, i);
		}

		// ���ò��ʵ�����ID
		g_3DModel.pMaterials[i].texureId = i;
	}

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
}

void cGame::DisplayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	DisplayFunc_Draw();
	
	glutSwapBuffers();							// ����������

}


void cGame::DisplayFunc_Draw()
{
	// ����ģ�������еĶ���
	for (int i = 0; i < g_3DModel.numOfObjects; i++)
	{
		// �������Ĵ�СС��0�����˳�
		if (g_3DModel.pObject.size() <= 0) break;

		// ��õ�ǰ��ʾ�Ķ���
		t3DObject *pObject = &g_3DModel.pObject[i];

		// �жϸö����Ƿ�������ӳ��
		if (pObject->bHasTexture) {

			// ������ӳ��
			glEnable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		}
		else {

			// �ر�����ӳ��
			glDisable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
		}

		// ��ʼ��GL_TRIANGLESģʽ����
		glBegin(GL_TRIANGLES);
		// �������е���
		for (int j = 0; j < pObject->numOfFaces; j++)
		{
			// ���������ε����е�
			for (int whichVertex = 0; whichVertex < 3; whichVertex++)
			{
				// ������ÿ���������
				int index = pObject->pFaces[j].vertIndex[whichVertex];

				// ����������
				glNormal3f(pObject->pNormals[index].x, pObject->pNormals[index].y, pObject->pNormals[index].z);

				// ��������������
				if (pObject->bHasTexture) {

					// ȷ���Ƿ���UVW��������
					if (pObject->pTexVerts) {
						glTexCoord2f(pObject->pTexVerts[index].x, pObject->pTexVerts[index].y);
					}
				}
				else {

					if (g_3DModel.pMaterials.size() && pObject->materialID >= 0)
					{
						BYTE *pColor = g_3DModel.pMaterials[pObject->materialID].color;
						glColor3ub(pColor[0], pColor[1], pColor[2]);
					}
				}
				glVertex3f(pObject->pVerts[index].x, pObject->pVerts[index].y, pObject->pVerts[index].z);
			}
		}
		// ���ƽ���
		glEnd();
	}										
}
