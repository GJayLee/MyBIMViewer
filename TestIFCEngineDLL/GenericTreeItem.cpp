#pragma execution_character_set("utf-8")

#include "GenericTreeItem.h"
#include "generic.h"

#include <math.h>


#ifdef WIN64
	#define int __int64
#endif



#ifdef	_UNICODE
STRUCT__PROPERTY	* CreateIfcProperty(int ifcID, wchar_t * name, wchar_t * description)
#else
STRUCT__PROPERTY	* CreateIfcProperty(int ifcID, char * name, char * description)
#endif
{
	STRUCT__PROPERTY	* ifcProperty = new STRUCT__PROPERTY;

	ifcProperty->structType = STRUCT_TYPE_PROPERTY;
	ifcProperty->ifcID = ifcID;
	ifcProperty->name = __copy__(name);
	ifcProperty->description = __copy__(description);

	ifcProperty->nominalValue = 0;
	ifcProperty->lengthValue = 0;
	ifcProperty->areaValue = 0;
	ifcProperty->volumeValue = 0;
	ifcProperty->countValue = 0;
	ifcProperty->weigthValue = 0;
	ifcProperty->timeValue = 0;
	ifcProperty->unit = 0;

	//ifcProperty->hTreeItem = 0;
#ifdef	_UNICODE
	ifcProperty->nameBuffer = new wchar_t[512];
#else
	ifcProperty->nameBuffer = new char[512];
#endif
	ifcProperty->next = 0;

	return	ifcProperty;
}

#ifdef	_UNICODE
STRUCT__PROPERTY__SET	* CreateIfcPropertySet(int ifcID, wchar_t * name, wchar_t * description)
#else
STRUCT__PROPERTY__SET	* CreateIfcPropertySet(int ifcID, char * name, char * description)
#endif
{
	STRUCT__PROPERTY__SET	* ifcPropertySet = new STRUCT__PROPERTY__SET;

	ifcPropertySet->structType = STRUCT_TYPE_PROPERTY_SET;
	ifcPropertySet->ifcID = ifcID;
	ifcPropertySet->name = __copy__(name);
	ifcPropertySet->description = __copy__(description);

#ifdef	_UNICODE
	ifcPropertySet->nameBuffer = new wchar_t[512];
#else
	ifcPropertySet->nameBuffer = new char[512];
#endif

	ifcPropertySet->properties = 0;
	ifcPropertySet->next = 0;

	return	ifcPropertySet;
}

STRUCT__IFC__ITEM *CreateIfcItem(int ifcModel, STRUCT__IFC__ITEM * parent, int ifcID, wchar_t * ifcType, bool hide, wchar_t * globalId, wchar_t * name, wchar_t * description)
{
	STRUCT__IFC__ITEM	* ifcItem = new STRUCT__IFC__ITEM;

	ifcItem->structType = STRUCT_TYPE_IFC_ITEM;
	ifcItem->ifcType = __copy__(ifcType);
	ifcItem->globalId = __copy__(globalId);
	ifcItem->name = __copy__(name);

	ifcItem->propertySets = 0;
	ifcItem->propertySetsAvailableHasLoadedYet = false;

	ifcItem->parent = parent;
	ifcItem->child = 0;
	ifcItem->next = 0;

	ifcItem->itemColor = 0;
	ifcItem->objectColor = 0;

	ifcItem->ifcID = ifcID;

	if (parent) {
		STRUCT__IFC__ITEM	** ppIfcItem = &parent->child;
		while ((*ppIfcItem)) {
			ppIfcItem = &(*ppIfcItem)->next;
		}
		(*ppIfcItem) = ifcItem;
	}

	if (ifcItem->ifcID)
	{
		int R = 0, G = 0, B = 0, Rspec = 0, Gspec = 0, Bspec = 0;
		ifcItem->objectColor = getRGB_object(ifcModel, ifcItem);
	}

	return ifcItem;
}

//
//	Cleanup
//

void	RemoveColor(STRUCT__COLOR * color)
{
	//delete(color);
}

void	RemoveHeaderSet(STRUCT__HEADER__SET * headerSet)
{
	if	(headerSet->name) {
		delete(headerSet->name);
	}

	if	(headerSet->value) {
		delete(headerSet->value);
	}

	delete(headerSet->nameBuffer);

	delete(headerSet);
}

void	RemoveNestedHeaderSet(STRUCT__HEADER__SET * headerSet)
{
	while  (headerSet) {
		RemoveNestedHeaderSet(headerSet->child);

		STRUCT__HEADER__SET	* headerSetToRemove = headerSet;
		headerSet = headerSet->next;

		RemoveHeaderSet(headerSetToRemove);
	}
}

void	RemoveIfcProperty(STRUCT__PROPERTY * ifcProperty)
{
	if	(ifcProperty->name) {
		delete(ifcProperty->name);
	}
	if	(ifcProperty->description) {
		delete(ifcProperty->description);
	}

	if	(ifcProperty->nominalValue) {
		delete(ifcProperty->nominalValue);
	}
	if	(ifcProperty->areaValue) {
		delete(ifcProperty->areaValue);
	}
	if	(ifcProperty->unit) {
		delete(ifcProperty->unit);
	}

	delete(ifcProperty->nameBuffer);

	delete(ifcProperty);
}

void	RemoveNestedIfcProperty(STRUCT__PROPERTY * ifcProperty)
{
	while  (ifcProperty) {
		STRUCT__PROPERTY	* ifcPropertyToRemove = ifcProperty;
		ifcProperty = ifcProperty->next;

		RemoveIfcProperty(ifcPropertyToRemove);
	}
}

void	RemoveIfcPropertySet(STRUCT__PROPERTY__SET * ifcPropertySet)
{
	if	(ifcPropertySet->name) {
		delete(ifcPropertySet->name);
	}
	if	(ifcPropertySet->description) {
		delete(ifcPropertySet->description);
	}
	delete(ifcPropertySet->nameBuffer);

	delete(ifcPropertySet);
}

void	RemoveNestedIfcPropertySet(STRUCT__PROPERTY__SET * ifcPropertySet)
{
	while  (ifcPropertySet) {
		STRUCT__PROPERTY__SET	* ifcPropertySetToRemove = ifcPropertySet;
		ifcPropertySet = ifcPropertySet->next;

		RemoveIfcPropertySet(ifcPropertySetToRemove);
	}
}

void	RemoveIfcItem(STRUCT__IFC__ITEM * ifcItem)
{
	if	(ifcItem->ifcType) {
		delete	ifcItem->ifcType;
	}
	if	(ifcItem->globalId) {
		delete	ifcItem->globalId;
	}
	if	(ifcItem->name) {
		delete	ifcItem->name;
	}
	
	if	(ifcItem->itemColor) {
		//RemoveColor(ifcItem->itemColor);
	}

	if	(ifcItem->objectColor) {
		//RemoveColor(ifcItem->itemColor);
	}

	delete	ifcItem;
}

void	RemoveNestedIfcItem(STRUCT__IFC__ITEM * ifcItem)
{
	while  (ifcItem) {
		RemoveNestedIfcItem(ifcItem->child);

		STRUCT__IFC__ITEM	* ifcItemToRemove = ifcItem;
		ifcItem = ifcItem->next;

		RemoveIfcItem(ifcItemToRemove);
	}
}

#undef int 