#if _MSC_VER > 1000
#pragma once
#pragma execution_character_set("utf-8")
#endif // _MSC_VER > 1000



#include "color.h"
#include "headerInfo.h"

#include "d3d9types.h"



#ifdef WIN64
	#define int __int64
#endif



#define		ITEM_CHECKED						0
#define		ITEM_PARTLY_CHECKED					1
#define		ITEM_UNCHECKED						2
#define		ITEM_PROPERTY_SET					3
#define		ITEM_PROPERTY						4
#define		ITEM_NONE							5
#define		ITEM_UNKNOWN						6
#define		ITEM_CHECKED_TO_ADJUST				10
#define		ITEM_UNCHECKED_TO_ADJUST			12

#define		TYPE_IFCOBJECT_NON_VISIBLE			100
#define		TYPE_IFCOBJECT_VISIBLE				101
#define		TYPE_IFCOBJECT_PROPERTY				102
#define		TYPE_IFCOBJECT_PROPERTYSET			103
#define		TYPE_IFCOBJECT_UNKNOWN				104



static int flagbit0  = 1;          // 2^^0    0000.0000..0000.0001
static int flagbit1  = 2;          // 2^^1    0000.0000..0000.0010
static int flagbit2  = 4;          // 2^^2    0000.0000..0000.0100
static int flagbit3  = 8;          // 2^^3    0000.0000..0000.1000

static int flagbit4  = 16;         // 2^^4    0000.0000..0001.0000
static int flagbit5  = 32;         // 2^^5    0000.0000..0010.0000
static int flagbit6  = 64;         // 2^^6    0000.0000..0100.0000
static int flagbit7  = 128;        // 2^^7    0000.0000..1000.0000

static int flagbit8  = 256;        // 2^^8    0000.0001..0000.0000
static int flagbit9  = 512;        // 2^^9    0000.0010..0000.0000
static int flagbit10 = 1024;       // 2^^10   0000.0100..0000.0000
static int flagbit11 = 2048;       // 2^^11   0000.1000..0000.0000

static int flagbit12 = 4096;       // 2^^12   0001.0000..0000.0000
static int flagbit13 = 8192;       // 2^^13   0010.0000..0000.0000
static int flagbit14 = 16384;      // 2^^14   0100.0000..0000.0000
static int flagbit15 = 32768;      // 2^^15   1000.0000..0000.0000


#ifdef	_UNICODE
wchar_t							* __copy__(wchar_t * txt);
#else
char							* __copy__(char * txt);
#endif

STRUCT__COLOR					* CreateColor();
#ifdef	_UNICODE
STRUCT__HEADER__SET				* CreateHeaderSet(STRUCT__HEADER__SET * parent, wchar_t * name, wchar_t * value);
STRUCT__PROPERTY				* CreateIfcProperty(int ifcID, wchar_t * name, wchar_t * description);
STRUCT__PROPERTY__SET			* CreateIfcPropertySet(int ifcID, wchar_t * name, wchar_t * description);
STRUCT__IFC__ITEM				* CreateIfcItem(int ifcModel, STRUCT__IFC__ITEM * parent, int ifcID, wchar_t * ifcType, bool hide, wchar_t * globalId, wchar_t * name, wchar_t * description);
#else
STRUCT__HEADER__SET				* CreateHeaderSet(STRUCT__HEADER__SET * parent, char * name, char * value);
STRUCT__PROPERTY				* CreateIfcProperty(int ifcID, char * name, char * description);
STRUCT__PROPERTY__SET			* CreateIfcPropertySet(int ifcID, char * name, char * description);
STRUCT__IFC__ITEM				* CreateIfcItem(int ifcModel, STRUCT__IFC__ITEM * parent, int ifcID, char * ifcType, bool hide, char * globalId, char * name, char * description);
STRUCT__SELECTABLE__TREEITEM	* CreateTreeItem(STRUCT__SELECTABLE__TREEITEM * parent, int ifcID, char * ifcType, char * globalId, char * name, char * description);
#endif

void							RemoveColor(STRUCT__COLOR * color);
void							RemoveNestedHeaderSet(STRUCT__HEADER__SET * headerSet);
void							RemoveNestedIfcItem(STRUCT__IFC__ITEM * ifcItem);


#undef int 