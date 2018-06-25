
#ifndef __cLoad3DS_H__
#define __cLoad3DS_H__

#include "main.h"

//  基本块(Primary Chunk)，位于文件的开始
#define PRIMARY       0x4D4D

//  主块(Main Chunks)
#define OBJECTINFO    0x3D3D				// 网格对象的版本号
#define VERSION       0x0002				// .3ds文件的版本
#define EDITKEYFRAME  0xB000				// 所有关键帧信息的头部

//  对象的次级定义
#define MATERIAL	  0xAFFF				// 保存纹理信息
#define OBJECT		  0x4000				// 保存对象的面、顶点等信息

//  材质的次级定义
#define MATNAME       0xA000				// 保存材质名称
#define MATDIFFUSE    0xA020				// 对象/材质的颜色
#define MATMAP        0xA200				// 新材质的头部
#define MATMAPFILE    0xA300				// 保存纹理的文件名

#define OBJECT_MESH   0x4100				// 新的网格对象

//  网格的次级定义
#define OBJECT_VERTICES     0x4110			// 对象顶点
#define OBJECT_FACES		0x4120			// 对象的面
#define OBJECT_MATERIAL		0x4130			// 对象的材质
#define OBJECT_UV			0x4140			// 对象的UV纹理坐标

// 定义2D点类，用于保存模型的UV纹理坐标
class CVector2
{
public:
	float x, y;
};

// 定义3D点的类，用于保存模型中的顶点
class CVector3
{
public:
	float x, y, z;
};

//  面结构体
struct tFace
{
	int vertIndex[3];			// 顶点索引
	int coordIndex[3];			// 纹理坐标索引
};

// 下标结构体
struct tIndices
{
	unsigned short a, b, c, bVisible;
};

// 块信息结构体
struct tChunk
{
	unsigned short int ID;					// 块的ID		
	unsigned int length;					// 块的长度
	unsigned int bytesRead;					// 需要读的块数据的字节数
};

//  材质信息结构体
struct tMaterialInfo
{
	char  strName[255];					// 纹理名称
	char  strFile[255];					// 如果存在纹理映射，则表示纹理文件名称
	unsigned char color[3];				// 对象的RGB颜色
	int   texureId;						// 纹理ID
	float uTile;						// u 重复
	float vTile;						// v 重复
	float uOffset;						// u 纹理偏移
	float vOffset;						// v 纹理偏移
};

//  对象信息结构体
struct t3DObject
{
	int  numOfVerts;			// 模型中顶点的数目
	int  numOfFaces;			// 模型中面的数目
	int  numTexVertex;			// 模型中纹理坐标的数目
	int  materialID;			// 纹理ID
	bool bHasTexture;			// 是否具有纹理映射
	char strName[255];			// 对象的名称
	CVector3  *pVerts;			// 对象的顶点
	CVector3  *pNormals;		// 对象的法向量
	CVector2  *pTexVerts;		// 纹理UV坐标
	tFace *pFaces;				// 对象的面信息
};

//  模型信息结构体
struct t3DModel
{
	int numOfObjects;							// 模型中对象的数目
	int numOfMaterials;							// 模型中材质的数目
	std::vector<tMaterialInfo> pMaterials;		// 材质链表信息
	std::vector<t3DObject> pObject;				// 模型中对象链表信息
};



// cLoad3DS类处理所有的装入代码
class cLoad3DS
{
public:
	// 初始化数据成员
	cLoad3DS();								
	// 装入3ds文件到模型结构中
	bool Import3DS(t3DModel *pModel, char *strFileName);
	// 载入纹理
	void CreateTexture(UINT textureArray[], LPSTR strFileName, int textureID);

private:
	// 读一个字符串
	int GetString(char *);
	// 读一个块
	void ReadChunk(tChunk *);
	// 读下一个块
	void ProcessNextChunk(t3DModel *pModel, tChunk *);
	// 读下一个对象块
	void ProcessNextObjectChunk(t3DModel *pModel, t3DObject *pObject, tChunk *);
	// 读下一个材质块
	void ProcessNextMaterialChunk(t3DModel *pModel, tChunk *);
	// 读对象颜色的RGB值
	void ReadColorChunk(tMaterialInfo *pMaterial, tChunk *pChunk);
	// 读对象的顶点
	void ReadVertices(t3DObject *pObject, tChunk *);
	// 读对象的面信息
	void ReadVertexIndices(t3DObject *pObject, tChunk *);
	// 读对象的纹理坐标
	void ReadUVCoordinates(t3DObject *pObject, tChunk *);
	// 读赋予对象的材质名称
	void ReadObjectMaterial(t3DModel *pModel, t3DObject *pObject, tChunk *pPreviousChunk);
	// 计算对象顶点的法向量
	void ComputeNormals(t3DModel *pModel);
	// 关闭文件，释放内存空间
	void CleanUp();

	// 文件指针
	FILE *m_FilePointer;
	// 块指针 
	tChunk *m_CurrentChunk;
	tChunk *m_TempChunk;
};


#endif

