//
//  Author:  Peter Bonsma
//  $Date: 1999-12-31 23:59:59 +0000 (Wed, 31 Jan 1999) $
//  $Revision: 3999 $
//  Project: IFC Engine DLL
//
//  In case of use of the DLL:
//  be aware of license fee for use of this DLL when used commercially
//  more info for commercial use:  peter.bonsma@rdf.bg
//

#pragma once

#ifdef _WINDOWS
	#if defined(WIN64) || defined(__LP64__)
		#define int __int64
	#else
		#define int __int32
	#endif
	#define int64_t __int64
#else
	#include <stdint.h>

	#if defined(WIN64) || defined(__LP64__)
		#define int int64_t
	#else
		#define int int32_t
	#endif
#endif

#ifdef _WINDOWS
	#ifdef _USRDLL
		#define DECL __declspec(dllexport) 
	#else
		#define DECL __declspec(dllimport) 
	#endif
	#define STDC __stdcall
#else
	#define DECL /*nothing*/
	#define STDC /*nothing*/
#endif


#ifdef __cplusplus
	extern "C" {
#endif


#define		sdaiADB					1
#define		sdaiAGGR				sdaiADB + 1
#define		sdaiBINARY				sdaiAGGR + 1
#define		sdaiBOOLEAN				sdaiBINARY + 1
#define		sdaiENUM				sdaiBOOLEAN + 1
#define		sdaiINSTANCE			sdaiENUM + 1
#define		sdaiINTEGER				sdaiINSTANCE + 1
#define		sdaiLOGICAL				sdaiINTEGER + 1
#define		sdaiREAL				sdaiLOGICAL + 1
#define		sdaiSTRING				sdaiREAL + 1
#define		sdaiUNICODE				sdaiSTRING + 1
#define		sdaiEXPRESSSTRING		sdaiUNICODE + 1
#define		engiGLOBALID			sdaiEXPRESSSTRING + 1


/*	Note on sdaiSTRING and sdaiUNICODE

	sdaiUNICODE
		this will convert all internal strings from/too unicode, the internal representation and what is written to the IFC file is mapped
			"\" will be converted into "\\" to enable basic parses to still interpret file paths
			"'" will be converted to \X1\hh\X0\ or \X2\00hh\X0\ to prevent basic interpreters to read files with strings containing these characters

	sdaiSTRING
		this will leave all information as is in the IFC file, the rules are that char's ( int ) 32 to 126 (inclusive) will be kept
		all other strings will be converted to \X1\hh\X0\ or \X2\00hh\X0\		*/


#define		sdaiARRAY				1
#define		sdaiLIST				2
#define		sdaiSET					3
#define		sdaiBAG					4

typedef	int				* SdaiAggr;
typedef	void			* SdaiAttr;
typedef	int				SdaiInstance;
typedef	int				SdaiInteger;
typedef	int				SdaiModel;
typedef	int				SdaiPrimitiveType;
typedef	int				* SdaiSet;
typedef	char			* SdaiString;



//
//  Calls for File IO
//
void	DECL STDC	sdaiCloseModel(
										int			model
									);

int		DECL STDC	sdaiCreateModelBN(
										int			repository,
										char		* fileName,
										char		* schemaName
									);

int		DECL STDC	sdaiCreateModelBNUnicode(
										int			repository,
										void		* fileName,
										void		* schemaName
									);

int		DECL STDC	sdaiOpenModelBN(
										int			repository,
										char		* fileName,
										char		* schemaName
									);

int		DECL STDC	sdaiOpenModelBNUnicode(
										int			repository,
										void		* fileName,
										void		* schemaName
									);

void	DECL STDC	sdaiSaveModelBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiSaveModelBNUnicode(
										int			model,
										void		* fileName
									);

void	DECL STDC	sdaiSaveModelAsXmlBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiSaveModelAsXmlBNUnicode(
										int			model,
										void		* fileName
									);

void	DECL STDC	sdaiSaveModelAsSimpleXmlBN(
										int			model,
										char		* fileName
									);

void	DECL STDC	sdaiSaveModelAsSimpleXmlBNUnicode(
										int			model,
										void		* fileName
									);

//
//  Schema Reading
//
int		DECL STDC	sdaiGetEntity(
										int			model,
										char		* entityName
									);

void	DECL STDC	engiGetEntityArgumentName(
										int			entity,
										int			index,
										int			valueType,
										char		** argumentName
									);

void	DECL STDC	engiGetEntityArgumentType(
										int			entity,
										int			index,
										int			* argumentType
									);

int		DECL STDC	engiGetEntityCount(
										int			model
									);

int		DECL STDC	engiGetEntityElement(
										int			model,
										int			index
									);

int		DECL * STDC	sdaiGetEntityExtent(
										int			model,
										int			entity
									);

int		DECL * STDC	sdaiGetEntityExtentBN(
										int			model,
										char		* entityName
									);

void	DECL STDC	engiGetEntityName(
										int			entity,
										int			valueType,
										char		** entityName
									);

int		DECL STDC	engiGetEntityNoArguments(
										int			entity
									);

int		DECL STDC	engiGetEntityParent(
										int			entity
									);

//
//  Instance Header
//
int		DECL STDC	GetSPFFHeaderItem(
										int			model,
										int			itemIndex,
										int			itemSubIndex,
										int			valueType,
										char		** value
									);

void	DECL STDC	SetSPFFHeader(
										int			model,
										char		* description,
										char		* implementationLevel,
										char		* name,
										char		* timeStamp,
										char		* author,
										char		* organization,
										char		* preprocessorVersion,
										char		* originatingSystem,
										char		* authorization,
										char		* fileSchema
									);

int		DECL STDC	SetSPFFHeaderItem(
										int			model,
										int			itemIndex,
										int			itemSubIndex,
										int			valueType,
										char		* value
									);

//
//  Instance Reading
//
int		DECL STDC	sdaiGetADBType(
										void		* ADB
									);

char	DECL * STDC	sdaiGetADBTypePath(
										void		* ADB,
										int			typeNameNumber
									);

void	DECL STDC	sdaiGetADBTypePathx(
										void		* ADB,
										int			typeNameNumber,
										char		** result
									);

void	DECL STDC	sdaiGetADBValue(
										void		* ADB,
										int			valueType,
										void		* value
									);

void	DECL * STDC	engiGetAggrElement(
										int			* aggregate,
										int			elementIndex,
										int			valueType,
										void		* value
									);

void	DECL STDC	engiGetAggrType(
										int			* aggregate,
										int			* aggragateType
									);

void	DECL * STDC	sdaiGetAttr(
										int			instance,
										void		* attribute,
										int			valueType,
										void		* value
									);

void	DECL * STDC	sdaiGetAttrBN(
										int			instance,
										char		* attributeName,
										int			valueType,
										void		* value
									);

void	DECL * STDC	sdaiGetAttrDefinition(
										int			entity,
										char		* attributeName
									);

int		DECL STDC	sdaiGetInstanceType(
										int			instance
									);

int		DECL STDC	sdaiGetMemberCount(
										int			* aggregate
									);

int		DECL STDC	sdaiIsKindOf(
										int			instance,
										int			entity
									);

//
//  Instance Writing
//
void	DECL STDC	sdaiAppend(
										int			list,
										int			valueType,
										void		* value
									);

void	DECL * STDC	sdaiCreateADB(
										int			valueType,
										void		* value
									);

int		DECL * STDC	sdaiCreateAggr(
										int			instance,
										void		* attribute
									);

int		DECL * STDC	sdaiCreateAggrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	sdaiCreateInstance(
										int			model,
										int			entity
									);

int		DECL STDC	sdaiCreateInstanceBN(
										int			model,
										char		* entityName
									);

void	DECL STDC	sdaiDeleteInstance(
										int			instance
									);

void	DECL STDC	sdaiPutADBTypePath(
										void		* ADB,
										int			pathCount,
										char		* path
									);

void	DECL STDC	sdaiPutAttr(
										int			instance,
										void		* attribute,
										int			valueType,
										void		* value
									);

void	DECL STDC	sdaiPutAttrBN(
										int			instance,
										char		* attributeName,
										int			valueType,
										void		* value
									);

void	DECL STDC	engiSetComment(
										int			instance,
										char		* comment
									);

//
//  Controling Calls
//
void	DECL STDC	circleSegments(
										int			circles,
										int			smallCircles
									);

void	DECL STDC	cleanMemory(
										int			model,
										int			mode
									);

int		DECL STDC	internalGetP21Line(
										int			instance
									);

int		DECL STDC	internalGetInstanceFromP21Line(
										int			model,
										int			P21Line
									);

int		DECL STDC	setStringUnicode(
										int			unicode
									);

//
//  Geometry Interaction
//
int		DECL STDC	initializeModellingInstance(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale,
										int			instance
									);

int		DECL STDC	finalizeModelling(
										int			model,
										float		* vertices,
										int			* indices,
										int			FVF
									);

int		DECL STDC	getInstanceInModelling(
										int			model,
										int			instance,
										int			mode,
										int			* startVertex,
										int			* startIndex,
										int			* primitiveCount
									);

void	DECL STDC	setVertexOffset(
										int			model,
										double		x,
										double		y,
										double		z
									);

void	DECL STDC	setFilter(
										int			model,
										int			setting,
										int			mask
									);

void	DECL STDC	setFormat(
										int			model,
										int			setting,
										int			mask
									);

int		DECL STDC	getConceptualFaceCnt(
										int			instance
									);

int		DECL STDC	getConceptualFaceEx(
										int			instance,
										int			index,
										int			* startIndexTriangles,
										int			* noIndicesTriangles,
										int			* startIndexLines,
										int			* noIndicesLines,
										int			* startIndexPoints,
										int			* noIndicesPoints,
										int			* startIndexFacesPolygons,
										int			* noIndicesFacesPolygons,
										int			* startIndexConceptualFacePolygons,
										int			* noIndicesConceptualFacePolygons
									);

//
//  Not documented API calls
//
int		DECL * STDC	xxxxGetEntityAndSubTypesExtent(
										int			model,
										int			entity
									);

int		DECL * STDC	xxxxGetEntityAndSubTypesExtentBN(
										int			model,
										char		* entityName
									);

int		DECL * STDC	xxxxGetInstancesUsing(
										int			instance
									);

int		DECL STDC	xxxxDeleteFromAggregation(
										int			instance,
										int			* aggregate,
										int			elementIndex
									);

void	DECL * STDC	xxxxGetAttrDefinitionByValue(
										int			instance,
										void		* value
									);

void	DECL STDC	xxxxGetAttrNameByIndex(
										int			instance,
										int			index,
										char		** name
									);

int		DECL STDC	xxxxOpenModelByStream(
										int			repository,
										void		* callback,
										char		* schemaName
									);

void	DECL * STDC	engiGetAggrElement_I(
										int			* aggregate,
										int			elementIndex,
										int			valueType,
										void		* value
									);

int		DECL STDC	engiGetInstanceMetaInfo(
										int			* instance,
										int			* localId,
										char		** entityName,
										char		** entityNameUC
									);

void	DECL STDC	engiGetEntityProperty(
										int			entity,
										int			index,
										char		** propertyName,
										int			* optional,
										int			* type,
										int			* _array,
										int			* set,
										int			* list,
										int			* bag,
										int			* min,
										int			* max,
										int			* referenceEntity,
										int			* inverse
									);

int		DECL STDC	engiGetInstanceLocalId(
										int			instance
									);

void	DECL STDC	engiGetInstanceClassInfoEx(
										int			instance,
										void		** classInfo
									);

char	DECL * STDC	engiGetInstanceClassInfo(
										int			instance
									);

char	DECL * STDC	engiGetInstanceClassInfoUC(
										int			instance
									);

void	DECL STDC	sdaiBeginning(
										int			iterator
									);

int		DECL STDC	sdaiCreateInstanceEI(
										int			model,
										int			entity,
										int			express_id
									);

int		DECL STDC	sdaiCreateInstanceBNEI(
										int			model,
										char		* entityName,
										int			express_id
									);

void	DECL * STDC	sdaiCreateIterator(
										int			* aggregate
									);

void	DECL STDC	sdaiDeleteIterator(
										int			iterator
									);

void	DECL STDC	sdaiEnd(
										int			iterator
									);

int		DECL STDC	sdaiErrorQuery(
									);

void	DECL * STDC	sdaiGetAggrByIterator(
										int			iterator,
										int			valueType,
										void		* value
									);

int		DECL STDC	sdaiIsInstanceOf(
										int			instance,
										int			entity
									);

int		DECL STDC	sdaiIsInstanceOfBN(
										int			instance,
										char		* entityName
									);

int		DECL STDC	sdaiNext(
										int			iterator
									);

void	DECL STDC	sdaiPrepend(
										int			list,
										int			valueType,
										void		* value
									);

int		DECL STDC	sdaiPrevious(
										int			iterator
									);

void	DECL STDC	sdaiPutAggrByIterator(
										int			iterator,
										int			valueType,
										void		* value
									);

int		DECL STDC	sdaiTestAttr(
										int			instance,
										void		* attribute
									);

int		DECL STDC	sdaiTestAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	engiGetAttrType(
										int			instance,
										void		* attribute
									);

int		DECL STDC	engiGetAttrTypeBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	initializeModelling(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale
									);

int		DECL STDC	initializeModellingInstanceEx(
										int			model,
										int			* noVertices,
										int			* noIndices,
										double		scale,
										int			instance,
										int			instanceList
									);

void	DECL STDC	exportModellingAsOWL(
										int			model,
										char		* fileName
									);

void	DECL STDC	owlGetModel(
										int			model,
										int64_t		* owlModel
									);

void	DECL STDC	owlGetInstance(
										int			model,
										int			instance,
										int64_t		* owlInstance
									);

void	DECL STDC	owlBuildInstance(
										int			model,
										int			instance,
										int64_t		* owlInstance
									);

void	DECL STDC	owlBuildInstances(
										int			model,
										int			instance,
										int64_t		* owlInstanceComplete,
										int64_t		* owlInstanceSolids,
										int64_t		* owlInstanceVoids
									);

void	DECL STDC	owlGetMappedItem(
										int			model,
										int			instance,
										int64_t		* owlInstance,
										double		* transformationMatrix
									);

int		DECL STDC	getInstanceDerivedPropertiesInModelling(
										int			model,
										int			instance,
										double		* height,
										double		* width,
										double		* thickness
									);

int		DECL STDC	getInstanceDerivedBoundingBox(
										int			model,
										int			instance,
										double		* Ox,
										double		* Oy,
										double		* Oz,
										double		* Vx,
										double		* Vy,
										double		* Vz
									);

int		DECL STDC	getInstanceDerivedTransformationMatrix(
										int			model,
										int			instance,
										double		* _11,
										double		* _12,
										double		* _13,
										double		* _14,
										double		* _21,
										double		* _22,
										double		* _23,
										double		* _24,
										double		* _31,
										double		* _32,
										double		* _33,
										double		* _34,
										double		* _41,
										double		* _42,
										double		* _43,
										double		* _44
									);

int		DECL STDC	getTimeStamp(
										int			model
									);

char	DECL * STDC	getChangedData(
										int			model,
										int			* timeStamp
									);

void	DECL STDC	setChangedData(
										int			model,
										int			* timeStamp,
										char		* changedData
									);

void	DECL * STDC	internalGetBoundingBox(
										int			model,
										int			instance
									);

void	DECL * STDC	internalGetCenter(
										int			model,
										int			instance
									);

void	DECL STDC	internalSetLink(
										int			instance,
										char		* attributeName,
										int			linked_id
									);

void	DECL STDC	internalAddAggrLink(
										int			list,
										int			linked_id
									);

char	DECL * STDC	sdaiGetStringAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	sdaiGetInstanceAttrBN(
										int			instance,
										char		* attributeName
									);

int		DECL STDC	sdaiGetAggregationAttrBN(
										int			instance,
										char		* attributeName
									);

void	DECL STDC	engiGetNotReferedAggr(
										int			model,
										int			* value
									);

void	DECL STDC	engiGetAttributeAggr(
										int			instance,
										int			* value
									);

void	DECL STDC	engiGetAggrUnknownElement(
										int			* aggregate,
										int			elementIndex,
										int			* valueType,
										void		* value
									);

int		DECL * STDC	sdaiFindInstanceUsers(
										int			instance,
										int			* domain,
										int			* resultList
									);

int		DECL * STDC	sdaiFindInstanceUsedIn(
										int			instance,
										int			* domain,
										int			* resultList
									);

int		DECL STDC	sdaiplusGetAggregationType(
										int			instance,
										int			* aggregation
									);

int		DECL STDC	iterateOverInstances(
										int			model,
										int			instance,
										int			* entity,
										void		* entityName
									);

int		DECL STDC	iterateOverProperties(
										int			entity,
										int			index
									);

void	DECL STDC	createGeometryConversion(
										int			instance,
										int64_t		* owlInstance
									);

#ifdef __cplusplus
	}
#endif

#undef DECL
#undef STDC
#undef int
