
#ifndef __cLoad3DS_H__
#define __cLoad3DS_H__

#include "main.h"

//  ������(Primary Chunk)��λ���ļ��Ŀ�ʼ
#define PRIMARY       0x4D4D

//  ����(Main Chunks)
#define OBJECTINFO    0x3D3D				// �������İ汾��
#define VERSION       0x0002				// .3ds�ļ��İ汾
#define EDITKEYFRAME  0xB000				// ���йؼ�֡��Ϣ��ͷ��

//  ����Ĵμ�����
#define MATERIAL	  0xAFFF				// ����������Ϣ
#define OBJECT		  0x4000				// ���������桢�������Ϣ

//  ���ʵĴμ�����
#define MATNAME       0xA000				// �����������
#define MATDIFFUSE    0xA020				// ����/���ʵ���ɫ
#define MATMAP        0xA200				// �²��ʵ�ͷ��
#define MATMAPFILE    0xA300				// ����������ļ���

#define OBJECT_MESH   0x4100				// �µ��������

//  ����Ĵμ�����
#define OBJECT_VERTICES     0x4110			// ���󶥵�
#define OBJECT_FACES		0x4120			// �������
#define OBJECT_MATERIAL		0x4130			// ����Ĳ���
#define OBJECT_UV			0x4140			// �����UV��������

// ����2D���࣬���ڱ���ģ�͵�UV��������
class CVector2
{
public:
	float x, y;
};

// ����3D����࣬���ڱ���ģ���еĶ���
class CVector3
{
public:
	float x, y, z;
};

//  ��ṹ��
struct tFace
{
	int vertIndex[3];			// ��������
	int coordIndex[3];			// ������������
};

// �±�ṹ��
struct tIndices
{
	unsigned short a, b, c, bVisible;
};

// ����Ϣ�ṹ��
struct tChunk
{
	unsigned short int ID;					// ���ID		
	unsigned int length;					// ��ĳ���
	unsigned int bytesRead;					// ��Ҫ���Ŀ����ݵ��ֽ���
};

//  ������Ϣ�ṹ��
struct tMaterialInfo
{
	char  strName[255];					// ��������
	char  strFile[255];					// �����������ӳ�䣬���ʾ�����ļ�����
	unsigned char color[3];				// �����RGB��ɫ
	int   texureId;						// ����ID
	float uTile;						// u �ظ�
	float vTile;						// v �ظ�
	float uOffset;						// u ����ƫ��
	float vOffset;						// v ����ƫ��
};

//  ������Ϣ�ṹ��
struct t3DObject
{
	int  numOfVerts;			// ģ���ж������Ŀ
	int  numOfFaces;			// ģ���������Ŀ
	int  numTexVertex;			// ģ���������������Ŀ
	int  materialID;			// ����ID
	bool bHasTexture;			// �Ƿ��������ӳ��
	char strName[255];			// ���������
	CVector3  *pVerts;			// ����Ķ���
	CVector3  *pNormals;		// ����ķ�����
	CVector2  *pTexVerts;		// ����UV����
	tFace *pFaces;				// ���������Ϣ
};

//  ģ����Ϣ�ṹ��
struct t3DModel
{
	int numOfObjects;							// ģ���ж������Ŀ
	int numOfMaterials;							// ģ���в��ʵ���Ŀ
	std::vector<tMaterialInfo> pMaterials;		// ����������Ϣ
	std::vector<t3DObject> pObject;				// ģ���ж���������Ϣ
};



// cLoad3DS�ദ�����е�װ�����
class cLoad3DS
{
public:
	// ��ʼ�����ݳ�Ա
	cLoad3DS();								
	// װ��3ds�ļ���ģ�ͽṹ��
	bool Import3DS(t3DModel *pModel, char *strFileName);
	// ��������
	void CreateTexture(UINT textureArray[], LPSTR strFileName, int textureID);

private:
	// ��һ���ַ���
	int GetString(char *);
	// ��һ����
	void ReadChunk(tChunk *);
	// ����һ����
	void ProcessNextChunk(t3DModel *pModel, tChunk *);
	// ����һ�������
	void ProcessNextObjectChunk(t3DModel *pModel, t3DObject *pObject, tChunk *);
	// ����һ�����ʿ�
	void ProcessNextMaterialChunk(t3DModel *pModel, tChunk *);
	// ��������ɫ��RGBֵ
	void ReadColorChunk(tMaterialInfo *pMaterial, tChunk *pChunk);
	// ������Ķ���
	void ReadVertices(t3DObject *pObject, tChunk *);
	// �����������Ϣ
	void ReadVertexIndices(t3DObject *pObject, tChunk *);
	// ���������������
	void ReadUVCoordinates(t3DObject *pObject, tChunk *);
	// ���������Ĳ�������
	void ReadObjectMaterial(t3DModel *pModel, t3DObject *pObject, tChunk *pPreviousChunk);
	// ������󶥵�ķ�����
	void ComputeNormals(t3DModel *pModel);
	// �ر��ļ����ͷ��ڴ�ռ�
	void CleanUp();

	// �ļ�ָ��
	FILE *m_FilePointer;
	// ��ָ�� 
	tChunk *m_CurrentChunk;
	tChunk *m_TempChunk;
};


#endif

