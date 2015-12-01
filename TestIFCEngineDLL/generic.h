#if _MSC_VER > 1000
#pragma once
#pragma execution_character_set("utf-8")
#endif // _MSC_VER > 1000

//#include<CommCtrl.h>

#ifdef _MSC_VER
//
//	Need to surpress warning due to a known issue in Visual Studio 2010
//
//#pragma warning (push)
//#pragma warning (disable : 4005)
//#include	<stdint.h>
//#pragma warning (pop)
//#else
//#include	<stdint.h>
#endif


#ifdef WIN64
	#define int __int64
#endif



#define		STRUCT_TYPE_ITEM_COLOR				200
#define		STRUCT_TYPE_OBJECT_COLOR			201
#define		STRUCT_TYPE_HEADER_SET				202
#define		STRUCT_TYPE_PROPERTY				203
#define		STRUCT_TYPE_PROPERTY_SET			204
#define		STRUCT_TYPE_IFC_ITEM				205
#define		STRUCT_TYPE_SELECTABLE_TREEITEM		206



struct STRUCT__COLOR;							//		color
struct STRUCT__HEADER__SET;						//		headerInfo
struct STRUCT__SIUNIT;


struct STRUCT__ITEM__COLOR;
struct STRUCT__OBJECT__COLOR;


typedef struct VECTOR3 {
	double							x;
	double							y;
	double							z;
}	VECTOR3;

typedef struct STRUCT__BASE {
	int								structType;
}	STRUCT_BASE;

typedef struct STRUCT__PROPERTY {
	int								structType;
	int								ifcID;

#ifdef	_UNICODE
	wchar_t							* name;
	wchar_t							* description;
#else
	char							* name;
	char							* description;
#endif

#ifdef	_UNICODE
	wchar_t							* nominalValue;
	wchar_t							* lengthValue;
	wchar_t							* areaValue;
	wchar_t							* volumeValue;
	wchar_t							* countValue;
	wchar_t							* weigthValue;
	wchar_t							* timeValue;
	wchar_t							* unit;
#else
	char							* nominalValue;
	char							* lengthValue;
	char							* areaValue;
	char							* volumeValue;
	char							* countValue;
	char							* weigthValue;
	char							* timeValue;
	char							* unit;
#endif

#ifdef	_UNICODE
	wchar_t							* nameBuffer;
#else
	char							* nameBuffer;
#endif

	STRUCT__PROPERTY				* next;
}	STRUCT__PROPERTY;

typedef struct STRUCT__PROPERTY__SET {
	int								structType;
	int								ifcID;

#ifdef	_UNICODE
	wchar_t							* name;
	wchar_t							* description;
#else
	char							* name;
	char							* description;
#endif
	
	STRUCT__PROPERTY				* properties;

#ifdef	_UNICODE
	wchar_t							* nameBuffer;
#else
	char							* nameBuffer;
#endif

	STRUCT__PROPERTY__SET			* next;
}	STRUCT__PROPERTY__SET;

typedef struct STRUCT__IFC__ITEM {
	int								structType;
	int								ifcID;

#ifdef	_UNICODE
	wchar_t							* globalId;
	wchar_t							* ifcType;
	wchar_t							* name;
#else
	char							* globalId;
	char							* ifcType;
	char							* name;
	char							* description;
#endif

	STRUCT__PROPERTY__SET			* propertySets;
	bool							propertySetsAvailableHasLoadedYet;

	STRUCT__IFC__ITEM				* parent;
	STRUCT__IFC__ITEM				* child;
	STRUCT__IFC__ITEM				* next;

	STRUCT__ITEM__COLOR				* itemColor;
	STRUCT__OBJECT__COLOR			* objectColor;

	STRUCT__SIUNIT					* units;

}	STRUCT__IFC__ITEM;

#ifdef	_UNICODE
bool	Equals(wchar_t * txtI, wchar_t * txtII);
#else
bool	Equals(char * txtI, char * txtII);
#endif

bool	EqualsC(char * txtI, char * txtII);

#ifdef	_UNICODE
wchar_t	* __copy__(wchar_t * txt);
#else
char	* __copy__(char * txt);
#endif

double	__abs__(double value);



#undef int