#pragma execution_character_set("utf-8")

#include "color.h"

#include "engine.h"



#ifdef WIN64
	#define int __int64
#endif


STRUCT__ITEM__COLOR		* firstItemColor, * defaultItemColor;
STRUCT__OBJECT__COLOR	* DEBUG__localObjectColor;


int		totalAllocatedItemColor = 0;

void	DEBUG__activeItemColor(STRUCT__OBJECT__COLOR * objectColor)
{
	while  (objectColor) {
		DEBUG__activeItemColor(objectColor->child);

		//ASSERT(objectColor->itemColor == 0  ||  objectColor->itemColor->active == false  ||  objectColor->itemColor->deleted == false);
		if (objectColor->itemColor != 0 && objectColor->itemColor->active != false && objectColor->itemColor->deleted != false)
			return;

		objectColor = objectColor->next;
	}
}

void	deleteItemColor(STRUCT__ITEM__COLOR * itemColor)
{
	totalAllocatedItemColor--;

	//ASSERT(itemColor->active == false);
	if (itemColor->active != false)
		return;

	STRUCT__ITEM__COLOR	* prev = itemColor->prev,
						* next = itemColor->next;
	//ASSERT(next);
	if(next == NULL)
		return;

	if	(prev) {
		//ASSERT(prev->next == itemColor);
		if (prev->next != itemColor)
			return;
		prev->next = next;
	} else {
		firstItemColor = next;
	}

	if	(next) {
		//ASSERT(next->prev == itemColor);
		if (next->prev != itemColor)
			return;
		next->prev = prev;
	}

	itemColor->active = false;

#ifdef	_DEBUG
	itemColor->deleted = true;
	DEBUG__activeItemColor(DEBUG__localObjectColor);
#else
	delete  itemColor;
#endif
}

STRUCT__ITEM__COLOR		* newItemColor()
{
	totalAllocatedItemColor++;

	STRUCT__ITEM__COLOR	* itemColor = new STRUCT__ITEM__COLOR;

	itemColor->structType = STRUCT_TYPE_ITEM_COLOR;

	itemColor->transparency = -1;

	itemColor->surface.R = -1;
	itemColor->surface.G = -1;
	itemColor->surface.B = -1;
	itemColor->surface.A = -1;

	itemColor->diffuse.R = -1;
	itemColor->diffuse.G = -1;
	itemColor->diffuse.B = -1;
	itemColor->diffuse.A = -1;

	itemColor->specular.R = -1;
	itemColor->specular.G = -1;
	itemColor->specular.B = -1;
	itemColor->specular.A = -1;

	itemColor->next = firstItemColor;
	itemColor->prev = 0;

	firstItemColor = itemColor;
	if	(firstItemColor->next) {
		firstItemColor->next->prev = firstItemColor;
	}

	itemColor->active = false;
#ifdef	_DEBUG
	itemColor->deleted = false;
#endif

	return	itemColor;
}

__int64	rdfClassTransformation,
		rdfClassCollection,
		owlDataTypePropertyExpressID,
		owlObjectTypePropertyMatrix,
		owlObjectTypePropertyObject,
		owlObjectTypePropertyObjects;

void	initializeColor(__int64 owlModel)
{
	firstItemColor = 0;

	defaultItemColor = newItemColor();

	defaultItemColor->transparency = 1;

	defaultItemColor->surface.R = 0;
	defaultItemColor->surface.G = 1;
	defaultItemColor->surface.B = 0;
	defaultItemColor->surface.A = 0;
	defaultItemColor->diffuse.R = 0;
	defaultItemColor->diffuse.G = 0.8;
	defaultItemColor->diffuse.B = 0;
	defaultItemColor->diffuse.A = 0;
	defaultItemColor->specular.R = 0;
	defaultItemColor->specular.G = 0.8;
	defaultItemColor->specular.B = 0;
	defaultItemColor->specular.A = 0;

	defaultItemColor->active = true;

	rdfClassTransformation = GetClassByName(owlModel, "Transformation");
	rdfClassCollection = GetClassByName(owlModel, "Collection");

	owlDataTypePropertyExpressID = GetPropertyByName(owlModel, "expressID");

	owlObjectTypePropertyMatrix = GetPropertyByName(owlModel, "matrix");
	owlObjectTypePropertyObject = GetPropertyByName(owlModel, "object");
	owlObjectTypePropertyObjects = GetPropertyByName(owlModel, "objects");
}

STRUCT__OBJECT__COLOR	* newObjectColor(int ifcInstance)
{
	STRUCT__OBJECT__COLOR	* objectColor = new STRUCT__OBJECT__COLOR;

	if	(ifcInstance) {
		objectColor->expressID = internalGetP21Line(ifcInstance);
	} else {
		objectColor->expressID = -1;
	}

	objectColor->isPoint = false;
	objectColor->isEdge = false;
	objectColor->isShell = false;
	
	objectColor->itemColor = newItemColor();

	objectColor->child = 0;
	objectColor->next = 0;

	return	objectColor;
}


//
//
//	colour RGB
//
//


void	getRGB_colourRGB(int SurfaceColourInstance, STRUCT__COLOR__COMPONENT * colorComponent)
{
	double red = 0, green = 0, blue = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(SurfaceColourInstance, (char *) L"Red", sdaiREAL, &red);
	sdaiGetAttrBN(SurfaceColourInstance, (char *) L"Green", sdaiREAL, &green);
	sdaiGetAttrBN(SurfaceColourInstance, (char *) L"Blue", sdaiREAL, &blue);
#else
	sdaiGetAttrBN(SurfaceColourInstance, "Red", sdaiREAL, &red);
	sdaiGetAttrBN(SurfaceColourInstance, "Green", sdaiREAL, &green);
	sdaiGetAttrBN(SurfaceColourInstance, "Blue", sdaiREAL, &blue);
#endif

	colorComponent->R = red;
	colorComponent->G = green;
	colorComponent->B = blue;
}

void	getRGB_surfaceStyle(int model, int surfaceStyleInstance, STRUCT__ITEM__COLOR * itemColor)
{
	int		* styles_set = 0, styles_cnt, i = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(surfaceStyleInstance, (char *) L"Styles", sdaiAGGR, &styles_set);
#else
	sdaiGetAttrBN(surfaceStyleInstance, "Styles", sdaiAGGR, &styles_set);
#endif
	styles_cnt = sdaiGetMemberCount(styles_set);
	while (i < styles_cnt)
	{
		int	surfaceStyleRenderingInstance = 0, SurfaceColourInstance = 0, SpecularColourInstance = 0, DiffuseColourInstance = 0;
		engiGetAggrElement(styles_set, i, sdaiINSTANCE, &surfaceStyleRenderingInstance);
#ifdef	_UNICODE
		int	surfaceStyleRenderingEntity = sdaiGetEntity(model, (char *) L"IFCSURFACESTYLERENDERING");
#else
		int	surfaceStyleRenderingEntity = sdaiGetEntity(model, "IFCSURFACESTYLERENDERING");
#endif
		//ASSERT(sdaiGetInstanceType(surfaceStyleRenderingInstance) == surfaceStyleRenderingEntity);
		if (sdaiGetInstanceType(surfaceStyleRenderingInstance) != surfaceStyleRenderingEntity)
			return;

		itemColor->transparency = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"Transparency", sdaiREAL, &itemColor->transparency);
#else
		sdaiGetAttrBN(surfaceStyleRenderingInstance, "Transparency", sdaiREAL, &itemColor->transparency);
#endif
		itemColor->transparency = 1 - itemColor->transparency;

#ifdef	_UNICODE
		sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"SurfaceColour", sdaiINSTANCE, &SurfaceColourInstance);
#else
		sdaiGetAttrBN(surfaceStyleRenderingInstance, "SurfaceColour", sdaiINSTANCE, &SurfaceColourInstance);
#endif
		if (SurfaceColourInstance != 0)
		{
			getRGB_colourRGB(SurfaceColourInstance, &itemColor->surface);
		} else {
			//ASSERT(false);
			return;
		}

#ifdef	_UNICODE
		sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"DiffuseColour", sdaiINSTANCE, &DiffuseColourInstance);
#else
		sdaiGetAttrBN(surfaceStyleRenderingInstance, "DiffuseColour", sdaiINSTANCE, &DiffuseColourInstance);
#endif
		if (DiffuseColourInstance != 0)
		{
			getRGB_colourRGB(DiffuseColourInstance, &itemColor->diffuse);
		} else {
			int	ADB = 0;
#ifdef	_UNICODE
			sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"DiffuseColour", sdaiADB, &ADB);
#else
			sdaiGetAttrBN(surfaceStyleRenderingInstance, "DiffuseColour", sdaiADB, &ADB);
#endif
			if (ADB) {
				double	value = 0;
				sdaiGetADBValue((void *) ADB, sdaiREAL, &value);
				itemColor->diffuse.R = value * itemColor->surface.R;
				itemColor->diffuse.G = value * itemColor->surface.G;
				itemColor->diffuse.B = value * itemColor->surface.B;
			}
		}

#ifdef	_UNICODE
		sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"SpecularColour", sdaiINSTANCE, &SpecularColourInstance);
#else
		sdaiGetAttrBN(surfaceStyleRenderingInstance, "SpecularColour", sdaiINSTANCE, &SpecularColourInstance);
#endif
		if (SpecularColourInstance != 0)
		{
			getRGB_colourRGB(SpecularColourInstance, &itemColor->specular);
		} else {
			int	ADB = 0;
#ifdef	_UNICODE
			sdaiGetAttrBN(surfaceStyleRenderingInstance, (char *) L"SpecularColour", sdaiADB, &ADB);
#else
			sdaiGetAttrBN(surfaceStyleRenderingInstance, "SpecularColour", sdaiADB, &ADB);
#endif
			if (ADB) {
				double	value = 0;
				sdaiGetADBValue((void *) ADB, sdaiREAL, &value);
				itemColor->specular.R = value * itemColor->surface.R;
				itemColor->specular.G = value * itemColor->surface.G;
				itemColor->specular.B = value * itemColor->surface.B;
			}
		}

		i++;
	}
}

void	getRGB_presentationStyleAssignment(int model, int presentationStyleAssignmentInstance, STRUCT__ITEM__COLOR * itemColor)
{
	int * styles_set = 0, styles_cnt, i = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(presentationStyleAssignmentInstance, (char *) L"Styles", sdaiAGGR, &styles_set);
#else
	sdaiGetAttrBN(presentationStyleAssignmentInstance, "Styles", sdaiAGGR, &styles_set);
#endif
	styles_cnt = sdaiGetMemberCount(styles_set);
	while (i < styles_cnt)
	{
		int surfaceStyleInstance = 0;
		engiGetAggrElement(styles_set, i, sdaiINSTANCE, &surfaceStyleInstance);
		if (surfaceStyleInstance != 0)
		{
			getRGB_surfaceStyle(model, surfaceStyleInstance, itemColor);
		}
		i++;
	}
}

void getRGB_styledItem(int model, int ifcStyledItemInstance, STRUCT__ITEM__COLOR * itemColor)
{
	int * styles_set = 0, styles_cnt, i = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcStyledItemInstance, (char *) L"Styles", sdaiAGGR, &styles_set);
#else
	sdaiGetAttrBN(ifcStyledItemInstance, "Styles", sdaiAGGR, &styles_set);
#endif
	styles_cnt = sdaiGetMemberCount(styles_set);
	while (i < styles_cnt)
	{
		int presentationStyleAssignmentInstance = 0;
		engiGetAggrElement(styles_set, i, sdaiINSTANCE, &presentationStyleAssignmentInstance);
		if (presentationStyleAssignmentInstance != 0)
		{
			getRGB_presentationStyleAssignment(model, presentationStyleAssignmentInstance, itemColor);
		}
		i++;
	}
}

void	getRGB_shapeRepresentation(int model, int ifcShapeRepresentationInstance, STRUCT__OBJECT__COLOR ** ppObjectColor);

void	searchDeeper(int model, int geometryInstance, STRUCT__OBJECT__COLOR ** ppObjectColor, STRUCT__ITEM__COLOR * itemColor)
{
	int styledItemInstance = 0;

#ifdef	_UNICODE
	sdaiGetAttrBN(geometryInstance, (char *) L"StyledByItem", sdaiINSTANCE, &styledItemInstance);
#else
	sdaiGetAttrBN(geometryInstance, "StyledByItem", sdaiINSTANCE, &styledItemInstance);
#endif
	if (styledItemInstance != 0)
	{
		getRGB_styledItem(model, styledItemInstance, itemColor);
		if (itemColor->surface.R >= 0)
		{
			return;
		}
	}

#ifdef	_UNICODE
	int	booleanClippingResultEntity = sdaiGetEntity(model, (char *) L"IFCBOOLEANCLIPPINGRESULT"),
		booleanResultEntity = sdaiGetEntity(model, (char *) L"IFCBOOLEANRESULT"),
		mappedItemEntity = sdaiGetEntity(model, (char *) L"IFCMAPPEDITEM"),
		shellBasedSurfaceModelEntity = sdaiGetEntity(model, (char *) L"IFCSHELLBASEDSURFACEMODEL");
#else
	int	booleanClippingResultEntity = sdaiGetEntity(model, "IFCBOOLEANCLIPPINGRESULT"),
		booleanResultEntity = sdaiGetEntity(model, "IFCBOOLEANRESULT"),
		mappedItemEntity = sdaiGetEntity(model, "IFCMAPPEDITEM"),
		shellBasedSurfaceModelEntity = sdaiGetEntity(model, "IFCSHELLBASEDSURFACEMODEL");
#endif
	if	(sdaiGetInstanceType(geometryInstance) == booleanResultEntity  ||  sdaiGetInstanceType(geometryInstance) == booleanClippingResultEntity) {
		int	geometryChildInstance = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(geometryInstance, (char *) L"FirstOperand", sdaiINSTANCE, &geometryChildInstance);
#else
		sdaiGetAttrBN(geometryInstance, "FirstOperand", sdaiINSTANCE, &geometryChildInstance);
#endif
		if	(geometryChildInstance) {
			searchDeeper(model, geometryChildInstance, ppObjectColor, itemColor);
		}
	} else if	(sdaiGetInstanceType(geometryInstance) == mappedItemEntity) {
		int	representationMapInstance = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(geometryInstance, (char *) L"MappingSource", sdaiINSTANCE, &representationMapInstance);
#else
		sdaiGetAttrBN(geometryInstance, "MappingSource", sdaiINSTANCE, &representationMapInstance);
#endif
		int	shapeRepresentationInstance = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(representationMapInstance, (char *) L"MappedRepresentation", sdaiINSTANCE, &shapeRepresentationInstance);
#else
		sdaiGetAttrBN(representationMapInstance, "MappedRepresentation", sdaiINSTANCE, &shapeRepresentationInstance);
#endif

		if	(shapeRepresentationInstance) {
			//ASSERT((*ppObjectColor)->child == 0);
			if ((*ppObjectColor)->child != 0)
				return;
			getRGB_shapeRepresentation(model, shapeRepresentationInstance, &(*ppObjectColor)->child);
		}
	} else if  (sdaiGetInstanceType(geometryInstance) == shellBasedSurfaceModelEntity) {
		int	* geometryChildAggr = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(geometryInstance, (char *) L"SbsmBoundary", sdaiAGGR, &geometryChildAggr);
#else
		sdaiGetAttrBN(geometryInstance, "SbsmBoundary", sdaiAGGR, &geometryChildAggr);
#endif
		STRUCT__OBJECT__COLOR	** ppSubObjectColor = &(*ppObjectColor)->child;

		int		cnt = sdaiGetMemberCount(geometryChildAggr), i = 0;
		while  (i < cnt) {
			int	geometryChildInstance = 0;
			engiGetAggrElement(geometryChildAggr, i, sdaiINSTANCE, &geometryChildInstance);
			if	(geometryChildInstance) {
				//ASSERT((*ppSubObjectColor) == 0);
				if ((*ppSubObjectColor) != 0)
					return;
				(*ppSubObjectColor) = newObjectColor(geometryChildInstance);

				searchDeeper(model, geometryChildInstance, ppSubObjectColor, (*ppSubObjectColor)->itemColor);
				ppSubObjectColor = &(*ppSubObjectColor)->next;
			}
			i++;
		}
	}
}

void	getRGB_shapeRepresentation(int model, int ifcShapeRepresentationInstance, STRUCT__OBJECT__COLOR ** ppObjectColor)
{
#ifdef	_UNICODE
	wchar_t * pRepresentationIdentifier = 0, * RepresentationType = 0;
	sdaiGetAttrBN(ifcShapeRepresentationInstance, (char *) L"RepresentationIdentifier", sdaiUNICODE, &pRepresentationIdentifier);
	sdaiGetAttrBN(ifcShapeRepresentationInstance, (char *) L"RepresentationType", sdaiUNICODE, &RepresentationType);
#else
	char	* pRepresentationIdentifier = 0, * RepresentationType = 0;
	sdaiGetAttrBN(ifcShapeRepresentationInstance, "RepresentationIdentifier", sdaiSTRING, &pRepresentationIdentifier);
	sdaiGetAttrBN(ifcShapeRepresentationInstance, "RepresentationType", sdaiSTRING, &RepresentationType);
#endif

#ifdef	_UNICODE
	if ( (Equals(pRepresentationIdentifier, L"Body")  ||  Equals(pRepresentationIdentifier, L"Mesh")  ||  Equals(pRepresentationIdentifier, L"Facetation"))  &&
		 !Equals(RepresentationType, L"BoundingBox") )
#else
	if ( (Equals(pRepresentationIdentifier, "Body")  ||  Equals(pRepresentationIdentifier, "Mesh")  ||  Equals(pRepresentationIdentifier, "Facetation"))  &&
		 !Equals(RepresentationType, "BoundingBox") )
#endif
	{
		int * geometry_set = 0, geometry_cnt, i = 0;
#ifdef	_UNICODE
		sdaiGetAttrBN(ifcShapeRepresentationInstance, (char *) L"Items", sdaiAGGR, &geometry_set);
#else
		sdaiGetAttrBN(ifcShapeRepresentationInstance, "Items", sdaiAGGR, &geometry_set);
#endif
		geometry_cnt = sdaiGetMemberCount(geometry_set);
//		i = geometry_cnt;
//		while (i > 0) {
//			i--;
		i = 0;
		while (i < geometry_cnt) {
			int geometryInstance = 0, styledItemInstance = 0;
			engiGetAggrElement(geometry_set, i, sdaiINSTANCE, &geometryInstance);

			//ASSERT((*ppObjectColor) == 0);
			if ((*ppObjectColor) != 0)
				return;
			(*ppObjectColor) = newObjectColor(geometryInstance);
			
#ifdef	_UNICODE
			sdaiGetAttrBN(geometryInstance, (char *) L"StyledByItem", sdaiINSTANCE, &styledItemInstance);
#else
			sdaiGetAttrBN(geometryInstance, "StyledByItem", sdaiINSTANCE, &styledItemInstance);
#endif
			if (styledItemInstance != 0)
			{
//int expressID = internalGetP21Line(geometryInstance);
				getRGB_styledItem(model, styledItemInstance, (*ppObjectColor)->itemColor);
			} else {
				searchDeeper(model, geometryInstance, ppObjectColor, (*ppObjectColor)->itemColor);
			}

			ppObjectColor = &(*ppObjectColor)->next;
			i++;
		}
	}
}

void getRGB_productDefinitionShape(int model, int ifcObjectInstance, STRUCT__OBJECT__COLOR ** ppObjectColor)
{
	int * representations_set = NULL, representations_cnt, i = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcObjectInstance, (char *) L"Representations", sdaiAGGR, &representations_set);
#else
	sdaiGetAttrBN(ifcObjectInstance, "Representations", sdaiAGGR, &representations_set);
#endif
	representations_cnt = sdaiGetMemberCount(representations_set);
	while (i < representations_cnt)
	{
		int ifcShapeRepresentation = 0;
		engiGetAggrElement(representations_set, i, sdaiINSTANCE, &ifcShapeRepresentation);
		if (ifcShapeRepresentation != 0)
		{
			getRGB_shapeRepresentation(model, ifcShapeRepresentation, ppObjectColor);
		}
		i++;
	}
}

void	minimizeItemColorItems(STRUCT__OBJECT__COLOR * objectColor, STRUCT__ITEM__COLOR ** ppItemColor, bool * pUnique, bool * pDefaultColorIsUsed);

STRUCT__OBJECT__COLOR	* getRGB_object(int ifcModel, STRUCT__IFC__ITEM * ifcItem)
{
STRUCT__OBJECT__COLOR	* objectColor = 0, ** ppObjectColor = &objectColor;
STRUCT__ITEM__COLOR		* returnedItemColor = 0;

	int ifcProductRepresentationInstance = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcItem->ifcID, (char *) L"Representation", sdaiINSTANCE, &ifcProductRepresentationInstance);
#else
	sdaiGetAttrBN(ifcItem->ifcID, "Representation", sdaiINSTANCE, &ifcProductRepresentationInstance);
#endif
	if (ifcProductRepresentationInstance != 0)
	{
		getRGB_productDefinitionShape(ifcModel, ifcProductRepresentationInstance, ppObjectColor);
	}
	
	if	(objectColor) {
		bool	unique = true, defaultColorIsUsed = false;
		STRUCT__ITEM__COLOR	* itemColor = 0;
		DEBUG__localObjectColor = objectColor;
		minimizeItemColorItems(objectColor, &itemColor, &unique, &defaultColorIsUsed);

		if	(unique) {
			returnedItemColor = itemColor;
		} else {
			returnedItemColor = 0;
		}

		if	(defaultColorIsUsed) {
			//
			//	Color not found, check if we can find colors via propertySets
			//
			STRUCT__PROPERTY__SET	* propertySet = ifcItem->propertySets;
			while  (propertySet) {
#ifdef	_UNICODE
				if	(Equals(propertySet->name, L"Pset_Draughting")) {
#else
				if	(Equals(propertySet->name, "Pset_Draughting")) {
#endif
	///			color->surface.R = 0;
	///			color->surface.G = 0;
	///			color->surface.B = 0;
	///			color->surface.A = 1;
					STRUCT__PROPERTY	* _property = propertySet->properties;
					while  (_property) {
#ifdef	_UNICODE
						if	(Equals(_property->name, L"Red")) {
							int	value = _wtoi(_property->nominalValue);
#else
						if	(Equals(_property->name, "Red")) {
							int	value = atoi(_property->nominalValue);
#endif
			///				color->surface.R = (double) value / 256;
						}
#ifdef	_UNICODE
						if	(Equals(_property->name, L"Green")) {
							int	value = _wtoi(_property->nominalValue);
#else
						if	(Equals(_property->name, "Green")) {
							int	value = atoi(_property->nominalValue);
#endif
			///				color->surface.G = (double) value / 256;
					}
#ifdef	_UNICODE
						if	(Equals(_property->name, L"Blue")) {
							int	value = _wtoi(_property->nominalValue);
#else
						if	(Equals(_property->name, "Blue")) {
							int	value = atoi(_property->nominalValue);
#endif
				///			color->surface.B = (double) value / 256;
						}
						_property = _property->next;
					}
				}
				propertySet = propertySet->next;
			}
		}
	}

	if	(returnedItemColor) {
		ifcItem->itemColor = returnedItemColor;
		return	0;
	} else {
		ifcItem->itemColor = 0;
		return	objectColor;
	}
}

void	minimizeItemColorItems(STRUCT__OBJECT__COLOR * objectColor, STRUCT__ITEM__COLOR ** ppItemColor, bool * pUnique, bool * pDefaultColorIsUsed)
{
	while  (objectColor) {
		//
		//	Check nested child object (i.e. Mapped Items)
		//
		if	(objectColor->child) {
			//ASSERT(objectColor->itemColor->surface.R == -1);
			if (objectColor->itemColor->surface.R != -1)
				return;
			//ASSERT(objectColor->itemColor->active == false);
			if (objectColor->itemColor->active != false)
				return;
			deleteItemColor(objectColor->itemColor);
			objectColor->itemColor = 0;
			minimizeItemColorItems(objectColor->child, ppItemColor, pUnique, pDefaultColorIsUsed);
		}

		//
		//	Complete Color
		//
		STRUCT__ITEM__COLOR	* itemColor = objectColor->itemColor;
		if	(itemColor) {
			if	(itemColor->surface.R == -1) {
				objectColor->itemColor = defaultItemColor;
				deleteItemColor(itemColor);
			} else {
				if	(itemColor->diffuse.R == -1) {
					itemColor->diffuse.R = itemColor->surface.R;
					itemColor->diffuse.G = itemColor->surface.G;
					itemColor->diffuse.B = itemColor->surface.B;
					itemColor->diffuse.A = itemColor->surface.A;
				}
				if	(itemColor->specular.R == -1) {
					itemColor->specular.R = itemColor->surface.R;
					itemColor->specular.G = itemColor->surface.G;
					itemColor->specular.B = itemColor->surface.B;
					itemColor->specular.A = itemColor->surface.A;
				}
			}
		} else {
			//ASSERT(objectColor->child);
			if (objectColor->child != NULL)
				return;
		}

		//
		//	Merge the same colors
		//
		itemColor = objectColor->itemColor;
		if	(itemColor  &&  itemColor != defaultItemColor) {
			bool	adjusted = false;
			//ASSERT(itemColor->active == false);
			if (itemColor->active != false)
				return;
			STRUCT__ITEM__COLOR	* itemColorLoop = firstItemColor;
			while  (itemColorLoop  &&  itemColorLoop->next) {
				if	( (itemColorLoop->active)  &&
					  (itemColor->transparency == itemColorLoop->transparency)  &&
					  (itemColor->surface.R == itemColorLoop->surface.R)  &&
					  (itemColor->surface.G == itemColorLoop->surface.G)  &&
					  (itemColor->surface.B == itemColorLoop->surface.B)  &&
					  (itemColor->surface.A == itemColorLoop->surface.A)  &&
					  (itemColor->diffuse.R == itemColorLoop->diffuse.R)  &&
					  (itemColor->diffuse.G == itemColorLoop->diffuse.G)  &&
					  (itemColor->diffuse.B == itemColorLoop->diffuse.B)  &&
					  (itemColor->diffuse.A == itemColorLoop->diffuse.A)  &&
					  (itemColor->specular.R == itemColorLoop->specular.R)  &&
					  (itemColor->specular.G == itemColorLoop->specular.G)  &&
					  (itemColor->specular.B == itemColorLoop->specular.B)  &&
					  (itemColor->specular.A == itemColorLoop->specular.A) ) {
					objectColor->itemColor = itemColorLoop;
					deleteItemColor(itemColor);
					itemColorLoop = 0;
					adjusted = true;
				} else {
					itemColorLoop = itemColorLoop->next;
				}
			}

			if	(adjusted) {
				//ASSERT(objectColor->itemColor->active);
				if (!objectColor->itemColor->active)
					return;
			} else {
				//ASSERT(objectColor->itemColor->active == false);
				if (objectColor->itemColor->active != false)
					return;
				objectColor->itemColor->active = true;
			}

			//ASSERT(itemColorLoop == 0  ||  (itemColorLoop == defaultItemColor  &&  itemColorLoop->next == 0));
			if (itemColorLoop != 0 && (itemColorLoop != defaultItemColor  ||  itemColorLoop->next != 0))
				return;
		}
		
		//
		//	Assign default color in case of no color and no children
		//
		if	(objectColor->itemColor == 0  &&  objectColor->child == 0) {
			objectColor->itemColor = defaultItemColor;
		}

		//
		//	Check if unique
		//
		itemColor = objectColor->itemColor;
		if	((*ppItemColor)) {
			if	((*ppItemColor) != itemColor) {
				if	(itemColor == 0  &&  objectColor->child) {
				} else {
					(*pUnique) = false;
				}
			}
		} else {
			//ASSERT((*pUnique) == true);
			if ((*pUnique) != true)
				return;
			(*ppItemColor) = itemColor;
		}
		
		if	(itemColor == defaultItemColor) {
			(*pDefaultColorIsUsed) = true;
		}

		objectColor = objectColor->next;
	}
}

void	completeItemColorItems()
{
	STRUCT__ITEM__COLOR	* itemColor = firstItemColor;
	while  (itemColor) {
		//ASSERT(itemColor->active);
		if (!itemColor->active)
			return;

		itemColor->mtrl.Ambient.r = (float) itemColor->surface.R;
		itemColor->mtrl.Ambient.g = (float) itemColor->surface.G;
		itemColor->mtrl.Ambient.b = (float) itemColor->surface.B;
		itemColor->mtrl.Ambient.a = (float) itemColor->transparency;
		itemColor->mtrl.Diffuse.r = (float) itemColor->diffuse.R;
		itemColor->mtrl.Diffuse.g = (float) itemColor->diffuse.G;
		itemColor->mtrl.Diffuse.b = (float) itemColor->diffuse.B;
		itemColor->mtrl.Diffuse.a = (float) itemColor->transparency;
		itemColor->mtrl.Specular.r = (float) itemColor->specular.R;
		itemColor->mtrl.Specular.g = (float) itemColor->specular.G;
		itemColor->mtrl.Specular.b = (float) itemColor->specular.B;
		itemColor->mtrl.Specular.a = (float) itemColor->transparency;
		itemColor->mtrl.Emissive.r = (float) itemColor->surface.R / 2;
		itemColor->mtrl.Emissive.g = (float) itemColor->surface.G / 2;
		itemColor->mtrl.Emissive.b = (float) itemColor->surface.B / 2;
		itemColor->mtrl.Emissive.a = (float) itemColor->transparency / 2;
		itemColor->mtrl.Power = 0.5;

		itemColor = itemColor->next;
	}
}

__int64	owlInstanceBase;

void	reCreateGeometry(__int64 owlModel, __int64 owlInstance, STRUCT__IFC__ITEM ** ppIfcSubItem, STRUCT__ITEM__COLOR * itemColor, __int64 transformationOwlInstance)
{
	__int64	noVertices = 0, noIndices = 0;

	SetObjectTypeProperty(transformationOwlInstance, owlObjectTypePropertyObject, &owlInstance, 1);

	CalculateInstance(owlInstanceBase, &noVertices, &noIndices, 0);
	
	if	(noVertices  &&  noIndices) {
		while  ((*ppIfcSubItem)) {
			ppIfcSubItem = &(*ppIfcSubItem)->next;
		}
		(*ppIfcSubItem) = new STRUCT__IFC__ITEM;
		STRUCT__IFC__ITEM	* ifcSubItem = (*ppIfcSubItem);

		//ifcSubItem->hideChildren = false;

		ifcSubItem->structType = STRUCT_TYPE_IFC_ITEM;

		ifcSubItem->ifcID = 0;
		//ifcSubItem->treeItemGeometry = 0;
		//ifcSubItem->treeItemProperties = 0;

		ifcSubItem->itemColor = itemColor;
		//ifcSubItem->isSub = true;

		ifcSubItem->parent = 0;
		ifcSubItem->child = 0;
		//ifcSubItem->subChild = 0;
		ifcSubItem->next = 0;

		ifcSubItem->globalId = 0;
		ifcSubItem->name = 0;
		//ifcSubItem->description = 0;
		ifcSubItem->ifcType = 0;

		/*ifcSubItem->indicesForFaces = 0;
		ifcSubItem->noPrimitivesForFaces = 0;

		ifcSubItem->indicesForLinesWireFrame = 0;
		ifcSubItem->noPrimitivesForWireFrame = 0;*/

		//ifcSubItem->indexOffsetForFaces = 0;
		//ifcSubItem->vertexOffsetForFaces = 0;

		//ifcSubItem->noVertices = (int)noVertices;
		//ifcSubItem->vertices = new float[(int)noVertices * 6];    //    <x, y, z>
		//int	* indices = new int[(int)noIndices];
		//
		//UpdateInstanceVertexBuffer(owlInstanceBase, ifcSubItem->vertices);
		//UpdateInstanceIndexBuffer(owlInstanceBase, indices);

		//ifcSubItem->noPrimitivesForWireFrame = 0;
		////ASSERT(ifcSubItem->indicesForLinesWireFrame == 0);
		//if (ifcSubItem->indicesForLinesWireFrame != 0)
		//	return;
		//int	* indicesForLinesWireFrame = new int[2*(int)noIndices];

		//ifcSubItem->noVertices = (int)noVertices;
		////ASSERT(ifcSubItem->indicesForFaces == 0);
		//if (ifcSubItem->indicesForFaces != 0)
		//	return;
		//int	* indicesForFaces = new int[(int)noIndices];

		//__int64	faceCnt = GetConceptualFaceCnt(owlInstanceBase);
		//for  (__int64 j = 0; j < faceCnt; j++) {
		//	__int64	startIndexTriangles = 0, noIndicesTrangles = 0, startIndexFacesPolygons = 0, noIndicesFacesPolygons = 0;
		//	GetConceptualFaceEx(owlInstanceBase, j, &startIndexTriangles, &noIndicesTrangles, 0, 0, 0, 0, &startIndexFacesPolygons, &noIndicesFacesPolygons, 0, 0);

		//	int	i = 0;
		//	while  (i < noIndicesTrangles) {
		//		indicesForFaces[ifcSubItem->noPrimitivesForFaces * 3 + i] = indices[startIndexTriangles + i];
		//		i++;
		//	}
		//	ifcSubItem->noPrimitivesForFaces += (int)noIndicesTrangles/3;

		//	i = 0;
		//	int	lastItem = -1;
		//	while  (i < noIndicesFacesPolygons) {
		//		if	(lastItem >= 0  &&  indices[startIndexFacesPolygons+i] >= 0) {
		//			indicesForLinesWireFrame[2*ifcSubItem->noPrimitivesForWireFrame + 0] = lastItem;
		//			indicesForLinesWireFrame[2*ifcSubItem->noPrimitivesForWireFrame + 1] = indices[startIndexFacesPolygons+i];
		//			ifcSubItem->noPrimitivesForWireFrame++;
		//		}
		//		lastItem = indices[startIndexFacesPolygons+i];
		//		i++;
		//	}
		//}
		//ifcSubItem->indicesForFaces = new int[3 * ifcSubItem->noPrimitivesForFaces];
		//ifcSubItem->indicesForLinesWireFrame = new int[2 * ifcSubItem->noPrimitivesForWireFrame];
		//	
		//memcpy(ifcSubItem->indicesForFaces, indicesForFaces, 3 * ifcSubItem->noPrimitivesForFaces * sizeof(int));
		//memcpy(ifcSubItem->indicesForLinesWireFrame, indicesForLinesWireFrame, 2 * ifcSubItem->noPrimitivesForWireFrame * sizeof(int));
	}
}

void	walkThroughGeometry__object(__int64 owlModel, __int64 owlInstance, STRUCT__IFC__ITEM ** ppIfcSubItem, STRUCT__OBJECT__COLOR ** ppObjectColor, int depth, __int64 transformationOwlInstance)
{
	__int64	* owlInstanceExpressID = 0, expressIDCard = 0;
	GetDataTypeProperty(owlInstance, owlDataTypePropertyExpressID, (void **) &owlInstanceExpressID, &expressIDCard);
	if	(expressIDCard == 1) {
		__int64	expressID = owlInstanceExpressID[0];
		while  ((*ppObjectColor)  &&  (*ppObjectColor)->expressID != expressID) {
			ppObjectColor = &(*ppObjectColor)->next;
		}
		if	((*ppObjectColor)) {
			//ASSERT((*ppObjectColor)->expressID == expressID);
			if ((*ppObjectColor)->expressID != expressID)
				return;
			if	((*ppObjectColor)->child) {
				if	(GetInstanceClass(owlInstance) == rdfClassTransformation) {
					__int64	* owlInstanceObject = 0, objectCard = 0;
					GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObject, &owlInstanceObject, &objectCard);
					if	(objectCard == 1) {

						__int64	* owlInstanceMatrix = 0, matrixCard = 0;
						GetObjectTypeProperty(owlInstance, owlObjectTypePropertyMatrix, &owlInstanceMatrix, &matrixCard);

						__int64	subTransformationOwlInstance = CreateInstance(rdfClassTransformation, 0);
						SetObjectTypeProperty(transformationOwlInstance, owlObjectTypePropertyObject, &subTransformationOwlInstance, 1);
						if	(matrixCard == 1) {
							SetObjectTypeProperty(subTransformationOwlInstance, owlObjectTypePropertyMatrix, owlInstanceMatrix, 1);
						} else {
							//ASSERT(false);
							return;
						}

						walkThroughGeometry__object(owlModel, owlInstanceObject[0], ppIfcSubItem, &(*ppObjectColor)->child, depth+1, subTransformationOwlInstance);
					} else {
						//ASSERT(false);
						return;
					}
				} else if  (GetInstanceClass(owlInstance) == rdfClassCollection) {
					STRUCT__OBJECT__COLOR	** ppObjectColorChild = &(*ppObjectColor)->child;
					__int64	* owlInstanceObjects = 0, objectsCard = 0;
					GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObjects, &owlInstanceObjects, &objectsCard);
					int	i = 0;
					while  (i < objectsCard) {
						walkThroughGeometry__object(owlModel, owlInstanceObjects[i], ppIfcSubItem, ppObjectColorChild, depth+1, transformationOwlInstance);
						i++;
					}
				} else {
					//ASSERT(false);
					return;
				}
			} else {
				//
				//	Now recreate the geometry for this object
				//
				reCreateGeometry(owlModel, owlInstance, ppIfcSubItem, (*ppObjectColor)->itemColor, transformationOwlInstance);
			}
			ppObjectColor = &(*ppObjectColor)->next;
		} else {
/////////////////////////////			ASSERT(false);
		}
	} else {
		//ASSERT(depth);
		if (!depth)
			return;
		if	(GetInstanceClass(owlInstance) == rdfClassTransformation) {
			__int64	* owlInstanceObject = 0, objectCard = 0;
			GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObject, &owlInstanceObject, &objectCard);

			__int64	* owlInstanceMatrix = 0, matrixCard = 0;
			GetObjectTypeProperty(owlInstance, owlObjectTypePropertyMatrix, &owlInstanceMatrix, &matrixCard);

			__int64	subTransformationOwlInstance = CreateInstance(rdfClassTransformation, 0);
			SetObjectTypeProperty(transformationOwlInstance, owlObjectTypePropertyObject, &subTransformationOwlInstance, 1);
			if	(matrixCard == 1) {
				SetObjectTypeProperty(subTransformationOwlInstance, owlObjectTypePropertyMatrix, owlInstanceMatrix, 1);
			} else {
				//ASSERT(false);
				return;
			}

			if	(objectCard == 1) {
				walkThroughGeometry__object(owlModel, owlInstanceObject[0], ppIfcSubItem, ppObjectColor, depth+1, subTransformationOwlInstance);
			} else {
				//ASSERT(false);
				return;
			}
		} else if  (GetInstanceClass(owlInstance) == rdfClassCollection) {
			__int64	* owlInstanceObjects = 0, objectsCard = 0;
			GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObjects, &owlInstanceObjects, &objectsCard);
			int	i = 0;
			while  (i < objectsCard) {
				walkThroughGeometry__object(owlModel, owlInstanceObjects[i], ppIfcSubItem, ppObjectColor, depth+1, transformationOwlInstance);
				i++;
			}
		} else {
			//ASSERT(false);
			return;
		}
	}
}

void	walkThroughGeometry__collection(__int64 owlModel, __int64 owlInstance, STRUCT__IFC__ITEM ** ppIfcSubItem, STRUCT__OBJECT__COLOR ** ppObjectColor, __int64 transformationOwlInstance)
{
	if	(GetInstanceClass(owlInstance) == rdfClassCollection) {
		__int64	* owlInstanceObjects = 0, objectsCard = 0;
		GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObjects, &owlInstanceObjects, &objectsCard);
		int	i = 0;
		while  (i < objectsCard) {
			walkThroughGeometry__collection(owlModel, owlInstanceObjects[i], ppIfcSubItem, ppObjectColor, transformationOwlInstance);
			i++;
		}
	} else {
		walkThroughGeometry__object(owlModel, owlInstance, ppIfcSubItem, ppObjectColor, 0, transformationOwlInstance);
	}
}

void	walkThroughGeometry__transformation(__int64 owlModel, __int64 owlInstance, STRUCT__IFC__ITEM ** ppIfcSubItem, STRUCT__OBJECT__COLOR ** ppObjectColor)
{
	//ASSERT(GetInstanceClass(owlInstance) == rdfClassTransformation);
	if (GetInstanceClass(owlInstance) != rdfClassTransformation)
		return;

	owlInstanceBase = CreateInstance(rdfClassTransformation, 0);

	__int64	* owlInstanceMatrix = 0, matrixCard = 0;
	GetObjectTypeProperty(owlInstance, owlObjectTypePropertyMatrix, &owlInstanceMatrix, &matrixCard);
	if	(matrixCard == 1) {
		SetObjectTypeProperty(owlInstanceBase, owlObjectTypePropertyMatrix, owlInstanceMatrix, 1);
	} else {
		//ASSERT(false);
		return;
	}

	__int64	* owlInstanceObject = 0, objectCard = 0;
	GetObjectTypeProperty(owlInstance, owlObjectTypePropertyObject, &owlInstanceObject, &objectCard);
	if	(objectCard == 1) {
		walkThroughGeometry__collection(owlModel, owlInstanceObject[0], ppIfcSubItem, ppObjectColor, owlInstanceBase);
	} else {
		//ASSERT(false);
		return;
	}
}

STRUCT__IFC__ITEM	* newSubGeometry(__int64 owlModel, __int64 owlInstance, STRUCT__OBJECT__COLOR * objectColor)
{
	STRUCT__IFC__ITEM	* ifcSubItem = 0;

	if	(objectColor) {
		STRUCT__OBJECT__COLOR	* loopObjectColor = objectColor;
		walkThroughGeometry__transformation(owlModel, owlInstance, &ifcSubItem, &loopObjectColor);
	}

	return	ifcSubItem;
}



#undef int 