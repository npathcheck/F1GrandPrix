#include "cGame.h"

cGame::cGame() {}

cGame::~cGame() {}

void cGame::Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// 设置背景颜色为黑色

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除颜色缓存和深度缓存

	glShadeModel(GL_SMOOTH);							// 设置着色方式为GL_SMOOTH

	g_Load3ds.Import3DS(&g_3DModel, fileName);			// 将3ds文件装入到模型结构体中

														// 遍历所有的材质
	for (int i = 0; i < g_3DModel.numOfMaterials; i++)
	{
		// 判断是否是一个文件名
		if (strlen(g_3DModel.pMaterials[i].strFile) > 0)
		{
			//  使用纹理文件名称来装入位图
			g_Load3ds.CreateTexture(g_Texture, g_3DModel.pMaterials[i].strFile, i);
		}

		// 设置材质的纹理ID
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
	
	glutSwapBuffers();							// 交换缓冲区

}


void cGame::DisplayFunc_Draw()
{
	// 遍历模型中所有的对象
	for (int i = 0; i < g_3DModel.numOfObjects; i++)
	{
		// 如果对象的大小小于0，则退出
		if (g_3DModel.pObject.size() <= 0) break;

		// 获得当前显示的对象
		t3DObject *pObject = &g_3DModel.pObject[i];

		// 判断该对象是否有纹理映射
		if (pObject->bHasTexture) {

			// 打开纹理映射
			glEnable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
			glBindTexture(GL_TEXTURE_2D, g_Texture[pObject->materialID]);
		}
		else {

			// 关闭纹理映射
			glDisable(GL_TEXTURE_2D);
			glColor3ub(255, 255, 255);
		}

		// 开始以GL_TRIANGLES模式绘制
		glBegin(GL_TRIANGLES);
		// 遍历所有的面
		for (int j = 0; j < pObject->numOfFaces; j++)
		{
			// 遍历三角形的所有点
			for (int whichVertex = 0; whichVertex < 3; whichVertex++)
			{
				// 获得面对每个点的索引
				int index = pObject->pFaces[j].vertIndex[whichVertex];

				// 给出法向量
				glNormal3f(pObject->pNormals[index].x, pObject->pNormals[index].y, pObject->pNormals[index].z);

				// 如果对象具有纹理
				if (pObject->bHasTexture) {

					// 确定是否有UVW纹理坐标
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
		// 绘制结束
		glEnd();
	}										
}
