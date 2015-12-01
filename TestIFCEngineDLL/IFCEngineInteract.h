#pragma once
#pragma execution_character_set("utf-8")

#include<unordered_map>
#include<engine.h>
#include<ifcengine.h>
#include<tchar.h>

#include"stringFunction.h"
#include"generic.h"
#include"color.h"
#include"GenericTreeItem.h"
#include"unit.h"

using namespace std;

extern wchar_t *ifcFileName = 0, *ifcSchemaName_IFC2X3 = 0, *xmlSettings_IFC2x3 = 0;

extern STRUCT__IFC__ITEM *baseIfcItem = 0;
unordered_map<int, int> allIfcObjects;

bool firstItemWithGeometryPassed;

bool findIfcItemByGlobalID(wchar_t *wstr, const char* globalID)
{
	if (wstr == NULL)
		return false;

	int len = wcslen(wstr) + 1;
	//声明cstr的长度
	char *cstr = (char*)malloc(sizeof(char)*len);
	if (cstr == NULL)
	{
		cout << "Fail!" << endl;
		return false;
	}
	//初始化化cstr为空
	memset(cstr, 0, len);
	int nlength = wcslen(wstr);
	//获取转换后的长度
	int nbytes = WideCharToMultiByte(0, 0, wstr, nlength, NULL, 0, NULL, NULL);
	if (nbytes > len)
		nbytes = len;
	//转换Unicode字符为ascii字符
	WideCharToMultiByte(0, 0, wstr, nlength, cstr, nbytes, NULL, NULL);

	if (strcmp(cstr, globalID) == 0)
	{
		free(cstr);
		return true;
	}
	else
	{
		free(cstr);
		return false;
	}
}

STRUCT__IFC__ITEM	* GetIfcItem(STRUCT__IFC__ITEM * ifcItem, int ifcID)
{
	return	(STRUCT__IFC__ITEM *)allIfcObjects[ifcID];
}

STRUCT__IFC__ITEM	* GetIveIfcItem(STRUCT__IFC__ITEM * ifcItem, STRUCT__IFC__ITEM * iveIfcItem, const char* globalID)
{
	while (ifcItem)
	{
		//如窗是由多个组件组成，IFCID为0，globalID为NULL
		if (ifcItem->globalId == NULL)
		{
			if (ifcItem->ifcID == 0)
			{
				if (findIfcItemByGlobalID(ifcItem->globalId, globalID))
					iveIfcItem = ifcItem->parent;
			}
			/*else
			{
			if (strcmp(Wchar2char(ifcItem->globalId), globalID) == 0)
			iveIfcItem = ifcItem;
			}*/
		}
		else
		{
			if (findIfcItemByGlobalID(ifcItem->globalId, globalID))
				iveIfcItem = ifcItem;
		}

		iveIfcItem = GetIveIfcItem(ifcItem->child, iveIfcItem, globalID);
		ifcItem = ifcItem->next;
	}

	return iveIfcItem;
}

void RetrieveObjects(int ifcModel, wchar_t * ObjectName, bool hide)
{
	int i, *ifcObjectUnstances, noIfcObjectInstances;
	ifcObjectUnstances = sdaiGetEntityExtentBN(ifcModel, (char*)ObjectName);
	noIfcObjectInstances = sdaiGetMemberCount(ifcObjectUnstances);
	if (noIfcObjectInstances)
	{
		STRUCT__IFC__ITEM	** ppLastIfcItem = &baseIfcItem;
		while ((*ppLastIfcItem)) {
			ppLastIfcItem = &(*ppLastIfcItem)->next;
		}
		(*ppLastIfcItem) = CreateIfcItem(ifcModel, 0, 0, 0, hide, ObjectName, 0, 0);

		for (i = 0; i < noIfcObjectInstances; ++i)
		{
			wchar_t* globalId = 0, *name = 0, *description = 0;
			int ifcObjectInstance = 0;
			engiGetAggrElement(ifcObjectUnstances, i, sdaiINSTANCE, &ifcObjectInstance);

			sdaiGetAttrBN(ifcObjectInstance, (char*)L"GlobalId", sdaiUNICODE, &globalId);
			sdaiGetAttrBN(ifcObjectInstance, (char*)L"Name", sdaiUNICODE, &name);
			sdaiGetAttrBN(ifcObjectInstance, (char*)L"Description", sdaiUNICODE, &description);

			STRUCT__IFC__ITEM *ifcItem = CreateIfcItem(ifcModel, (*ppLastIfcItem), ifcObjectInstance, ObjectName, hide, globalId, name, description);

			allIfcObjects[ifcObjectInstance] = (int)ifcItem;
		}
	}
}

double	fabs__(double x)
{
	if (x < 0) {
		return	-x;
	}
	else {
		return	x;
	}
}