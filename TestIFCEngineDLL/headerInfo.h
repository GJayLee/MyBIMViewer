#if _MSC_VER > 1000
#pragma once
#pragma execution_character_set("utf-8")
#endif // _MSC_VER > 1000



#include"ifcengine.h"



#ifdef WIN64
	#define int __int64
#endif



typedef struct STRUCT__HEADER__SET {
	int								structType;

#ifdef	_UNICODE
	wchar_t							* name;
	wchar_t							* value;
#else
	char							* name;
	char							* value;
#endif

	//HTREEITEM						hTreeItem;
#ifdef	_UNICODE
	wchar_t							* nameBuffer;
#else
	char							* nameBuffer;
#endif

	STRUCT__HEADER__SET				* child;
	STRUCT__HEADER__SET				* next;
}	STRUCT__HEADER__SET;



STRUCT__HEADER__SET	* GetHeaderInfo(int ifcModel);



#undef int