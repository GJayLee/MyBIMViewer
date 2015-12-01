#pragma execution_character_set("utf-8")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include"generic.h"
#include"ifcengine.h"
#include"d3d9.h"



#ifdef WIN64
	#define int __int64
#endif



typedef struct STRUCT__COLOR__COMPONENT {
	double							R;
	double							G;
	double							B;
	double							A;
}	STRUCT__COLOR__COMPONENT;

typedef struct STRUCT__ITEM__COLOR {
	int								structType;
	bool							active;
	bool							deleted;
//#ifdef	_DEBUG
//	bool							deleted;
//#endif

	double							transparency;

	STRUCT__COLOR__COMPONENT		surface;

	STRUCT__COLOR__COMPONENT		diffuse;
	STRUCT__COLOR__COMPONENT		specular;

	D3DMATERIAL9					mtrl;

	STRUCT__ITEM__COLOR				* next;
	STRUCT__ITEM__COLOR				* prev;
}	STRUCT__ITEM__COLOR;

typedef struct STRUCT__OBJECT__COLOR {
	bool							isPoint;
	bool							isEdge;
	bool							isShell;

	__int64							expressID;
	STRUCT__ITEM__COLOR				* itemColor;

	STRUCT__OBJECT__COLOR			* child;
	STRUCT__OBJECT__COLOR			* next;
}	STRUCT__OBJECT__COLOR;



void	initializeColor(__int64 owlModel);
void	completeItemColorItems();

STRUCT__OBJECT__COLOR	* getRGB_object(int ifcModel, STRUCT__IFC__ITEM * ifcItem);

STRUCT__IFC__ITEM	* newSubGeometry(__int64 owlModel, __int64 owlInstance, STRUCT__OBJECT__COLOR * objectColor);



#undef int