//
//  Author:  Peter Bonsma
//  $Date: 1999-12-31 23:59:59 +0000 (Wed, 31 Jan 1999) $
//  $Revision: 3999 $
//  Project: Geometry Kernel
//
//  In case of use of the DLL:
//  be aware of license fee for use of this DLL when used commercially
//  more info for commercial use:  peter.bonsma@rdf.bg
//

#pragma once

#ifdef _WINDOWS
	#define int32_t __int32
	#define int64_t __int64
#else
	#include	<stdint.h>
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

#define		OBJECTTYPEPROPERTY_TYPE				1
#define		DATATYPEPROPERTY_TYPE_BOOLEAN 		2
#define		DATATYPEPROPERTY_TYPE_CHAR			3
#define		DATATYPEPROPERTY_TYPE_INTEGER		4
#define		DATATYPEPROPERTY_TYPE_DOUBLE		5



//
//		GetClassByName
//				int64_t				model						IN
//				char				* owlClassName				IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to the class as stored inside.
//		When the class does not exist yet and the name is unique
//		the class will be created on the fly and the handle will be returned.
//		When the name is not unique and given to an instance, objectTypeProperty
//		or dataTypeProperty 0 will be returned.
//
int64_t		DECL STDC	GetClassByName(
									int64_t			model,
									const char		* owlClassName
								);

//
//		GetPropertyByName
//				int64_t				model						IN
//				char				* rdfPropertyName			IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to the objectTypeProperty or dataTypeProperty as stored inside.
//		When the property does not exist yet and the name is unique
//		the property will be created on the fly and the handle will be returned.
//		When the name is not unique and given to a class or instance 0 will be returned.
//
int64_t		DECL STDC	GetPropertyByName(
									int64_t			model,
									const char		* rdfPropertyName
								);


//
//		GetPropertyByNameAndType
//				int64_t				model						IN
//				char				* rdfPropertyName			IN
//				int64_t				rdfPropertyType				IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to the dataTypeProperty as stored inside with the requested
//		propertyType. When the property does not exist yet and the name is unique
//		the property will be created on the fly and the handle will be returned.
//		When the name is not unique and given to a property of a different type,
//		a class or instance 0 will be returned.
//
int64_t		DECL STDC	GetPropertyByNameAndType(
									int64_t			model,
									const char		* rdfPropertyName,
									int64_t			rdfPropertyType
								);

//
//		GetNameOfProperty
//				int64_t				rdfProperty					IN
//				char				** name						IN/OUT
//
//		Returns the name of the property, if the class does not exist it returns NULL.
//
void		DECL STDC	GetNameOfProperty(
									int64_t			rdfProperty,
									char			** name
								);

//
//		SetNameOfProperty
//				int64_t				rdfProperty					IN
//				char				* name						IN
//
//				int64_t				returns						OUT
//
//		Sets/updates the name of the property, if no error it returns 0.
//		In case property does not exist it returns 1, when name cannot be updated 2.
//
int64_t		DECL STDC	SetNameOfProperty(
									int64_t			rdfProperty,
									const char		* name
								);

//
//		GetNameOfClass
//				int64_t				owlClass					IN
//				char				** name						IN/OUT
//
//		Returns the name of the class, if the class does not exist it returns NULL.
//
void		DECL STDC	GetNameOfClass(
									int64_t			owlClass,
									char			** name
								);

//
//		SetNameOfClass
//				int64_t				owlClass					IN
//				char				* name						IN
//
//				int64_t				returns						OUT
//
//		Sets/updates the name of the class, if no error it returns 0.
//		In case class does not exist it returns 1, when name cannot be updated 2.
//
int64_t		DECL STDC	SetNameOfClass(
									int64_t			owlClass,
									const char		* name
								);

//
//		GetNameOfInstance
//				int64_t				owlInstance					IN
//				char				** name						IN/OUT
//
//		Returns the name of the instance, if the instance does not exist it returns NULL.
//
void		DECL STDC	GetNameOfInstance(
									int64_t			owlInstance,
									char			** name
								);
//
//		SetNameOfInstance
//				int64_t				owlInstance					IN
//				char				* name						IN
//
//				int64_t				returns						OUT
//
//		Sets/updates the name of the instance, if no error it returns 0.
//		In case instance does not exist it returns 1, when name cannot be updated 2.
//
int64_t		DECL STDC	SetNameOfInstance(
									int64_t			owlInstance,
									const char		* name
								);

//
//		GetInstancePropertyByIterator
//				int64_t				owlInstance					IN
//				int64_t				rdfProperty					IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to the objectTypeProperty or dataTypeProperty connected to
//		the instance, this property can also contain a value, but for example also
//		the knowledge about cardinality restrictions in the context of this instance's class
//		and the exact cardinality in context of its instance.
//
int64_t		DECL STDC	GetInstancePropertyByIterator(
									int64_t			owlInstance,
									int64_t			rdfProperty
								);

int64_t		DECL STDC	GetInstanceInverseReferencesByIterator(
									int64_t			owlInstance,
									int64_t			referencingOwlInstance
								);

//
//		CreateProperty
//				int64_t				model						IN
//				int64_t				rdfPropertyType			IN
//				const char			* rdfPropertyName			IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to an on the fly created property.
//		If the model input is zero or not a model handle 0 will be returned,
//
int64_t		DECL STDC	CreateProperty(
									int64_t			model,
									int64_t			rdfPropertyType,
									const char		* rdfPropertyName
								);

//
//		CreateInstance
//				int64_t				owlClass					IN
//				char				* owlInstanceName			IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to an on the fly created instance.
//		If the _class input is zero or not a class handle 0 will be returned,
//
int64_t		DECL STDC	CreateInstance(
									int64_t			owlClass,
									const char		* owlInstanceName
								);

//
//		GetClassesByIterator
//				int64_t				model						IN
//				int64_t				owlClass					IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to an class.
//		If input class is zero, the handle will point to the first relevant class.
//		If all classes are past (or no relevant classes are found), the function will return 0.
//
int64_t		DECL STDC	GetClassesByIterator(
									int64_t			model,
									int64_t			owlClass
								);

//
//		SetParent
//				int64_t				owlClass					IN
//				int64_t				parentOwlClass				IN
//				int64_t				setting						IN
//
void		DECL STDC	SetClassParent(
									int64_t			owlClass,
									int64_t			parentOwlClass,
									int64_t			setting
								);

//
//		IsGeomertyType
//				int64_t				owlClass					IN
//
//				int64_t				returns						OUT
//
//		Returns true if the owlClass is a geometry type
//
int64_t		DECL STDC	IsGeomertyType(
									int64_t			owlClass 
								);

//
//		GetRangeRestrictionsByIterator  
//				int64_t				rdfProperty					IN
//				int64_t				owlClass					IN
//
//				int64_t				returns						OUT
//
//		Returns the next class the property is restricted to.
//		If input class is zero, the handle will point to the first relevant class.
//		If all classes are past (or no relevant classes are found), the function will return 0.
//	
int64_t		DECL STDC	GetRangeRestrictionsByIterator(
									int64_t			rdfProperty, 
									int64_t			owlClass 
								);

//
//		GetParentsIterator
//				int64_t				owlClass					IN
//				int64_t				parent						IN
//
//				int64_t				returns						OUT
//
//		Returns the next parent of the class.
//		If input parent is zero, the handle will point to the first relevant parent.
//		If all parent are past (or no relevant parent are found), the function will return 0.
//
int64_t		DECL STDC	GetParentsByIterator(
									int64_t			owlClass,
									int64_t			parentOwlClass
								);

//
//		GetPropertiesByIterator
//				int64_t				model						IN
//				int64_t				rdfProperty					IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to an properties.
//		If input property is zero, the handle will point to the first relevant property.
//		If all properties are past (or no relevant properties are found), the function will return 0.
//
int64_t		DECL STDC	GetPropertiesByIterator(
									int64_t			model,
									int64_t			rdfProperty
								);


//
//		GetInstancesByIterator
//				int64_t				model						IN
//				int64_t				owlInstance					IN
//
//				int64_t				returns						OUT
//
//		Returns a handle to an instance.
//		If input instance is zero, the handle will point to the first relevant instance.
//		If all instances are past (or no relevant instances are found), the function will return 0.
//
int64_t		DECL STDC	GetInstancesByIterator(
									int64_t			model,
									int64_t			owlInstance
								);

//
//		GetInstanceClass
//				int64_t				owlInstance					IN
//
//				int64_t				returns						OUT
//
//		Returns the handle to the class of which an instances is instantiated.
//
//		Note: internally this function is not rich enough as support for multiple inheritance
//			  is making it impossible to answer this request with always one class handle.
//			  Even in the case of pure single inheritance an instance of a class is also an instance of 
//			  every parent classes in the inheritance tree. For now we expect single inheritance use
//			  and the returned class handle points to the 'lowest' class in the inheritance tree.
//
int64_t		DECL STDC	GetInstanceClass(
									int64_t			owlInstance
								);

//
//		InstanceCopyCreated
//				int64_t				owlInstance					IN
//
//		This function announces a copy is created by the host,
//		when this instance is deleted it has to be deleted one more time
//		so the copy can access the instance until the copy is also deleted.
//
void		DECL STDC	InstanceCopyCreated(
									int64_t			owlInstance
								);

//
//		RemoveInstance
//				int64_t				owlInstance					IN
//
//				int64_t				returns						OUT
//
//		This function removes an instance from the internal structure.
//		In case copies are created by the host this function checks if all
//		copies are removed otherwise the instance will stay available.
//		Return value is 0 if everything went ok and positive in case of an error
//
int64_t		DECL STDC	RemoveInstance(
									int64_t			owlInstance
								);



//
//		GetPropertyType
//				int64_t				rdfProperty					IN
//
//				int64_t				returns						OUT
//
//		This function returns the type of the property.
//		The following return values are possible:
//			0	The property is not defined yet
//			1	The property is an Object Type Property
//			2	The property is an Data Type Property of type Boolean
//			3	The property is an Data Type Property of type Char
//			4	The property is an Data Type Property of type Integer
//			5	The property is an Data Type Property of type Double
//
int64_t		DECL STDC	GetPropertyType(
									int64_t			rdfProperty
								);

//
//		GetPropertyRestrictions
//				int64_t				owlClass					IN
//				int64_t				rdfProperty					IN
//				int64_t				* minCard					IN / OUT
//				int64_t				* maxCard					IN / OUT
//
//		This function returns the minCard and maxCard of a certain
//		property in the context of a class. The cardinality of a property in 
//		an instance has to be between minCard and maxCard.
//		If undefined minCard and/or maxCard will be of value -1, this means
//		for minCard that it is 0 and for maxCard it means infinity.
//		Note: this function does not return inherited restrictions. 
//
//
void		DECL STDC	GetPropertyRestrictions(
									int64_t			owlClass,
									int64_t			rdfProperty,
									int64_t			* minCard,
									int64_t			* maxCard
								);



//
//		SetObjectTypeProperty
//				int64_t				owlInstance					IN
//				int64_t				rdfProperty					IN
//				int64_t				* value						IN
//				int64_t				card						IN
//
//		This function sets the value(s) of a certain objectTypeProperty
//		in the context of an instance.
//		The value of card gives the actual card of the value list.
//		The list value of integers is a list of handles to instances, this list
//		has a length as givin in the value card.
//		
//		Note: the client application needs to make sure the cardinality of
//			  the property is within the boundaries.
//
int64_t		DECL STDC	SetObjectTypeProperty(
									int64_t			owlInstance,
									int64_t			rdfProperty,
									int64_t			* value,
									int64_t			card
								);

//
//		GetObjectTypeProperty
//				int64_t				owlInstance					IN
//				int64_t				rdfProperty					IN
//				int64_t				** value					OUT
//				int64_t				* card						OUT
//
//		This function gets the value(s) of a certain objectTypeProperty
//		in the context of an instance.
//		The value of card gives the actual card of the value list.
//		The list value of integers is a list of handles to instances, this list
//		has a length as givin in the value card.
//		
int64_t		DECL STDC	GetObjectTypeProperty(
									int64_t			owlInstance,
									int64_t			rdfProperty,
									int64_t			** value,
									int64_t			* card
								);

//
//		SetDataTypeProperty
//				int64_t				owlInstance					IN
//				int64_t				rdfProperty					IN
//				void				* value						IN
//				int64_t				card						IN
//
//		This function sets the value(s) of a certain datatypeTypeProperty
//		in the context of an instance.
//		The value of card gives the actual card of the value list.
//		The list value of undefined (void) items is a list of booleans, chars, integers
//		or doubles, this list has a length as givin in the value card. The actual used type
//		is given by the definition of the dataTypeProperty.
//		
//		Note: the client application needs to make sure the cardinality of
//			  the property is within the boundaries.
//
int64_t		DECL STDC	SetDataTypeProperty(
									int64_t			owlInstance,
									int64_t			rdfProperty,
									void			* value,
									int64_t			card
								);

//
//		GetDataTypeProperty
//				int64_t				owlInstance					IN
//				int64_t				rdfProperty					IN
//				void				** value					OUT
//				int64_t				* card						OUT
//
//		This function gets the value(s) of a certain datatypeTypeProperty
//		in the context of an instance.
//		The value of card gives the actual card of the value list.
//		The list value of undefined (void) items is a list of booleans, chars, integers
//		or doubles, this list has a length as givin in the value card. The actual used type
//		is given by the definition of the dataTypeProperty.
//
int64_t		DECL STDC	GetDataTypeProperty(
									int64_t			owlInstance,
									int64_t			rdfProperty,
									void			** value,
									int64_t			* card
								);



//
//		SetFormat
//				int64_t				model						IN
//				int64_t				setting						IN
//				int64_t				mask						IN
//
//		This function sets the type of export format, by setting a mask
//			bit 0 & 1:
//				00	Each vertex is unique (although mostly irrelevant UpdateIndexBuffer() and 
//					UpdateTransformationBuffer() are still returning information)
//				01	Each index is unique => vertices are not necessarily (although mostly
//					irrelevant UpdateTransformationBuffer() is still returning information)
//				10	Single level Transformations are used, most optimal when using DirectX till version 11
//					and OpenGL till version 2
//				11	Nested Transformations are used, most optimal but till 2011 no known support of
//					low level 3D interfaces like DirectX and OpenGL
//			bit 2:
//				0	Vertex items returned as float (4 byte/32 bit)
//				1	Vertex items returned as double (8 byte/64 bit)
//			bit 3:
//				0	Index items returned as int32_t (4 byte/32 bit)
//				1	Index items returned as int64_t (8 byte/64 bit) (only available in 64 bit mode)
//
//			bit 4:
//				0	Vertex does not contain 3D point info
//				1	Vertex does contain 3D point info
//			bit 5:
//				0	Vertex does not contain 3D normal vector info
//				1	Vertex does contain 3D normal vector info => if set, bit 4 will also be set
//			bit 6:
//				0	Vertex does not contain first 2D texture info
//				1	Vertex does contain first 2D texture info
//			bit 7:
//				0	Vertex does not contain second 2D texture info
//				1	Vertex does contain second 2D texture info => if set, bit 6 will also be set
//
//			bit 8:	
//				0	No object form triangles are exported
//				1	Object form triangles are exported
//			bit 9:
//				0	No object polygon lines are exported
//				1	Object polygon lines are exported
//			bit 10:
//				0	No object points are exported
//				1	Object points are exported
//
//			bit 11:	Reserved, by default 0
//
//			bit 12:
//				0	No object face polygon lines are exported
//				1	Object face polygon lines are exported => if set, bit 8 will also be set
//			bit 13:
//				0	No object conceptual face polygon lines are exported
//				1	Object conceptual face polygon lines are exported => if set, bit 12 will also be set
//
//			bit 14:	Reserved, by default 0
//
//			bit 15:
//				0	All normals of triangles are transformed orthogonal to the 2D face they belong to
//				1	Normals are exported to be in line with the original semantic form description (could be non orthogonal to the 2D face) 
//
//			bit 16: 
//				0	no specific behavior
//				1	Where possible DirectX compatibility is given to exported data (i.e. order of components in vertices)
//						 => if set, bit 17 will be unset
//
//			bit 17: 
//				0	no specific behavior
//				1	Where possible OpenGL compatibility is given to exported data (i.e. order of components in vertices and inverted texture coordinates in Y direction)
//						 => if set, bit 16 will be unset
//
//			bit 18:	Reserved, by default 0
//
//			bit 19:	Reserved, by default 0
//
//			bit 20-23:
//				0000	version 0 (used in case there is different behavior between versions in DirectX or OpenGL)
//				....	...
//				1111	version 15
//
//			bit 24:
//				0	Vertex does not contain Ambient color information
//				1	Vertex does contain Ambient color information
//			bit 25:
//				0	Vertex does not contain Diffuse color information
//				1	Vertex does contain Diffuse color information
//			bit 26:
//				0	Vertex does not contain Emissive color information
//				1	Vertex does contain Emissive color information
//			bit 27:
//				0	Vertex does not contain Specular color information
//				1	Vertex does contain Specular color information
//
//			bit 28:
//				0	Vertex does not contain tangent vector for first texture
//				1	Vertex does contain tangent vector for first texture => if set, bit 6 will also be set
//			bit 29:
//				0	Vertex does not contain binormal vector for first texture
//				1	Vertex does contain binormal vector for first texture => if set, bit 6 will also be set
//			bit 30:
//				0	Vertex does not contain tangent vector for second texture
//				1	Vertex does contain tangent vector for second texture => if set, bit 6 will also be set
//			bit 31:
//				0	Vertex does not contain binormal vector for second texture
//				1	Vertex does contain binormal vector for second texture => if set, bit 6 will also be set
//
//			bit 26-31:	Reserved, by default 0
//
//			bit 32-63:	Reserved, by default 0
//
//		Note: default setting is 0000 0000 0000 0000   0000 0000 0000 0000  -  0000 0000 0000 0000   1000 0001  0011 0000 = h0000 0000 - 0000 8130 = 33072
//
int64_t		DECL STDC	SetFormat(
									int64_t			model,
									int64_t			setting,
									int64_t			mask
								);

//
//		GetFormat
//				int64_t				model						IN
//				int64_t				setting						IN
//
//				int64_t				returns						OUT
//
//	Returns the current format given a mask.
//
int64_t		DECL STDC	GetFormat(
									int64_t			model,
									int64_t			mask
								);

//
//		SetBehavior
//				int64_t				model						IN
//				int64_t				setting						IN
//				int64_t				mask						IN
//
//		This function sets the type of behavior, by setting a mask
//
//			bit 0-7:	Reserved, by default 0
//
//			bit 8:
//				0	Do not optimize
//				1	Vertex items returned as double (8 byte/64 bit)
//				
//			bit 9-31:	Reserved, by default 0
//
//			bit 32-63:	Reserved, by default 0
//
//		Note: default setting is 0000 0000 0000 0000   0000 0000 0000 0000  -  0000 0000 0000 0000   0000 0001  0000 0000 = h0000 0000 - 0000 0100 = 256
//
void		DECL STDC	SetBehavior(
									int64_t			model,
									int64_t			setting,
									int64_t			mask
								);

//
//		GetBehavior
//				int64_t				model						IN
//				int64_t				setting						IN
//
//				int64_t				returns						OUT
//
//	Returns the current behavior given a mask.
//
int64_t		DECL STDC	GetBehavior(
									int64_t			model,
									int64_t			mask
								);

//
//		SetVertexBufferOffset
//				int64_t				model						IN
//				double				x							IN
//				double				y							IN
//				double				z							IN
//
//	Sets the offset for a Vertex Buffer.
//	The offset will always be calculated in 64 bit, even if the vertex element size is 32 bit.
//
//	This function can be called just before updating the vertex buffer.
//
void		DECL STDC	SetVertexBufferOffset(
									int64_t			model,
									double			x,
									double			y,
									double			z
								);

//
//		SetIndexBufferOffset
//				int64_t				model						IN
//				int64_t				offset						IN
//
//	Sets the offset for an Index Buffer.
//	It is important call this function before updating the vertex buffer.
//
void		DECL STDC	SetIndexBufferOffset(
									int64_t			model,
									int64_t			offset
								);

//
//		ClearedExternalBuffers
//
//		This function tells the engine that all buffers have no memory of earlier filling.
//		This means that even when buffer content didn't changed it will be updated when
//		functions UpdateVertexBuffer(), UpdateIndexBuffer() and/or transformationBuffer()
//		are called.
//
void		DECL STDC	ClearedExternalBuffers(
									int64_t			model
								);

//
//		ClearedInstanceExternalBuffers
//
//		This function tells the engine that all buffers have no memory of earlier filling 
//		for a certain instance.
//		This means that even when buffer content didn't changed it will be updated when
//		functions UpdateVertexBuffer(), UpdateIndexBuffer() and/or transformationBuffer()
//		are called for this specific instance.
//
void		DECL STDC	ClearedInstanceExternalBuffers(
									int64_t			owlInstance
								);

//
//		SetInstanceForCalculation
//				int64_t				model						IN
//				int64_t				owlInstance					IN
//				int64_t				enable						IN
//				int64_t				nested						IN
//				int64_t				forceBufferAdjustment		IN
//
//		This function enables/disables instances for being exported to the buffers.
//		When the argument enable is true the instance will be available in the buffers,
//		otherwise it will not appear (and also no memory is needed on the client side)
//		By default all instances will be shown.
//		If argument nested is true not only this instances but also all subinstances
//		will be applied the same procedure, be aware that the nesting can be a network.
//		If forceBufferAdjustment is true all buffers will be adjusted with the first next call,
//		if this value is false, the engine will decide when to free memory on buffers depending
//		on use and frequency of resetting instance enabling.
//
//		Note 1: if instance is 0, the value enable counts for all instances => this automatically 
//			    means that in this case nested is irrelevant.
//		Note 2: Set forceBufferAdjustment only to true if you expect memory issues with the buffers.
//		Note 3: if instance is non-zero, model does not require a value 
//
void		DECL STDC	SetInstanceForCalculation(
									int64_t			model,
									int64_t			owlInstance,
									int64_t			enable,
									int64_t			nested,
									int64_t			forceBufferAdjustment
								);

//
//		CalculateInstance
//				int64_t				owlInstance					IN
//				int64_t				* vertexBufferSize			IN / OUT
//				int64_t				* indexBufferSize			IN / OUT
//				int64_t				* transformationBufferSize	IN / OUT
//
//		This function prepares the content to be ready so the buffers can be filled.
//		It returns the minimum size the buffers should be. This is only the case
//		when the pointer is given, all arguments are allowed to be NULL.
//
//		Note I: This function needs to be called directly before UpdateVertexBuffer(),
//			    UpdateIndexBuffer() and UpdateTransformationBuffer().
//
int64_t		DECL STDC	CalculateInstance(
									int64_t			owlInstance,
									int64_t			* vertexBufferSize,
									int64_t			* indexBufferSize,
									int64_t			* transformationBufferSize
								);

//
//		CalculateInstances
//				int64_t				model						IN
//				int64_t				* vertexBufferSize			IN / OUT
//				int64_t				* indexBufferSize			IN / OUT
//				int64_t				* transformationBufferSize	IN / OUT
//
//		This function prepares the content to be ready so the buffers can be filled.
//		It returns the minimum size the buffers should be. This is only the case
//		when the pointer is given, all arguments are allowed to be NULL.
//
//		Note I: This function needs to be called directly before UpdateVertexBuffer(),
//			    UpdateIndexBuffer() and UpdateTransformationBuffer().
//
int64_t		DECL STDC	CalculateInstances(
									int64_t			model,
									int64_t			* vertexBufferSize,
									int64_t			* indexBufferSize,
									int64_t			* transformationBufferSize
								);

//
//		UpdateInstanceVertexBuffer
//				int64_t				owlInstance					IN
//				void				* vertexBuffer				IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateIndexBuffer()
//		and UpdateTransformationBuffer().
//		It is expected to be called with a buffer vertexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateInstanceVertexBuffer(
									int64_t			owlInstance,
									void			* vertexBuffer
								);

//
//		UpdateVertexBuffer
//				int64_t				model						IN
//				void				* vertexBuffer				IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateIndexBuffer()
//		and UpdateTransformationBuffer().
//		It is expected to be called with a buffer vertexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateVertexBuffer(
									int64_t			model,
									void			* vertexBuffer
								);

//
//		UpdateInstanceIndexBuffer
//				int64_t				owlInstance					IN
//				void				* indexBuffer				IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateVertexBuffer()
//		and UpdateTransformationBuffer().
//		It is expected to be called with a buffer indexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateInstanceIndexBuffer(
									int64_t			owlInstance,
									void			* indexBuffer
								);

//
//		UpdateIndexBuffer
//				int64_t				model						IN
//				void				* indexBuffer				IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateVertexBuffer()
//		and UpdateTransformationBuffer().
//		It is expected to be called with a buffer indexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateIndexBuffer(
									int64_t			model,
									void			* indexBuffer
								);

//
//		UpdateInstanceTransformationBuffer
//				int64_t				owlInstance					IN
//				void				* transformationBuffer		IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateVertexBuffer()
//		and UpdateIndexBuffer().
//		It is expected to be called with a buffer vertexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateInstanceTransformationBuffer(
									int64_t			owlInstance,
									void			* transformationBuffer
								);

//
//		UpdateTransformationBuffer
//				int64_t				model						IN
//				void				* transformationBuffer		IN / OUT
//
//		This function should be preceded by the function CalculateInstances(),
//		the only allowed other API functions in between are UpdateVertexBuffer()
//		and UpdateIndexBuffer().
//		It is expected to be called with a buffer vertexBuffer of at least the size as 
//		given by CalculateInstances().
//		If not called for the first time it will expect to contain the same content as
//		from previous call, even is size is changed. This can be overruled by 
//		the function ClearedExternalBuffers().
//
int64_t		DECL STDC	UpdateTransformationBuffer(
									int64_t			model,
									void			* transformationBuffer
								);



//
//		GetConceptualFaceCnt
//				int64_t				instance					IN
//
//				int64_t				returns						OUT
//
//		This function returns the number of conceptual faces for a certain instance.
//
int64_t		DECL STDC	GetConceptualFaceCnt(
									int64_t			owlInstance
								);

//
//		GetConceptualFace
//				int64_t				owlnstance					IN
//				int64_t				index						IN
//				int64_t				* startIndex				IN / OUT
//				int64_t				* noTriangles				IN / OUT
//
//				int64_t				returns						OUT
//
//		This function returns a handle to the conceptual face. Be aware that different
//		instances can return the same handles (however with possible different startIndices and noTriangles).
//		Argument index should be at least zero and smaller then return value of GetConceptualFaceCnt().
//		Argument startIndex shows the first index used.
//		Argument noTriangles returns the number of triangles, each triangle is existing of 3 unique indices.
//
int64_t		DECL STDC	GetConceptualFace(
									int64_t			owlInstance,
									int64_t			index,
									int64_t			* startIndex,
									int64_t			* noTriangles
								);

//
//		GetConceptualFaceEx
//				int64_t				owlInstance							IN
//				int64_t				index								IN
//				int64_t				* startIndexTriangles				IN / OUT
//				int64_t				* noIndicesTriangles				IN / OUT
//				int64_t				* startIndexLines					IN / OUT
//				int64_t				* noIndicesLines					IN / OUT
//				int64_t				* startIndexPoints					IN / OUT
//				int64_t				* noIndicesPoints					IN / OUT
//				int64_t				* startIndexFacesPolygons			IN / OUT
//				int64_t				* noIndicesFacesPolygons			IN / OUT
//				int64_t				* startIndexConceptualFacePolygons	IN / OUT
//				int64_t				* noIndicesConceptualFacePolygons	IN / OUT
//
//				int64_t				returns								OUT
//
//		This function returns a handle to the conceptual face. Be aware that different
//		instances can return the same handles (however with possible different startIndices and noTriangles).
//		Argument index should be at least zero and smaller then return value of GetConceptualFaceCnt().
//
int64_t		DECL STDC	GetConceptualFaceEx(
									int64_t			owlInstance,
									int64_t			index,
									int64_t			* startIndexTriangles,
									int64_t			* noIndicesTriangles,
									int64_t			* startIndexLines,
									int64_t			* noIndicesLines,
									int64_t			* startIndexPoints,
									int64_t			* noIndicesPoints,
									int64_t			* startIndexFacesPolygons,
									int64_t			* noIndicesFacesPolygons,
									int64_t			* startIndexConceptualFacePolygons,
									int64_t			* noIndicesConceptualFacePolygons
								);

//
//		GetConceptualFaceOriginCnt
//				int64_t				conceptualFace				IN
//
//				int64_t				returns						OUT
//
//		This function returns the number of instances that are the source primitive/concept
//		for this conceptual face.
//
int64_t		DECL STDC	GetConceptualFaceOriginCnt(
									int64_t			conceptualFace
								);

//
//		GetConceptualFaceOrigin
//				int64_t				conceptualFace				IN
//				int64_t				index						IN
//
//				int64_t				returns						OUT
//
//		This function returns a handle to the instance that is the source primitive/concept
//		for this conceptual face.
//
int64_t		DECL STDC	GetConceptualFaceOrigin(
									int64_t			conceptualFace,
									int64_t			index
								);

//
//		GetFaceCnt
//				int64_t				instance					IN
//
//				int64_t				returns						OUT
//
//		This function returns the number of faces for a certain instance.
//
int64_t		DECL STDC	GetFaceCnt(
									int64_t			instance
								);

//
//		GetFace
//				int64_t				owlInstance					IN
//				int64_t				index						IN
//				int64_t				* startIndex				IN / OUT
//				int64_t				* noOpenings				IN / OUT
//
//		...
//
void		DECL STDC	GetFace(
									int64_t			owlInstance,
									int64_t			index,
									int64_t			* startIndex,
									int64_t			* noOpenings
								);

//
//		GetBoundingBox
//				int64_t				owlInstance					IN
//				void				* transformationMatrix		IN
//				void				* startVector				IN
//				void				* endVector					IN
//
//		...
//
void		DECL STDC	GetBoundingBox(
									int64_t			owlInstance,
									void			* transformationMatrix,
									void			* startVector,
									void			* endVector
								);

//
//		SetBoundingBoxReference
//				int64_t				owlInstance					IN
//				void				* transformationMatrix		IN
//				void				* startVector				IN
//				void				* endVector					IN
//
//		This function passes addresses from the hosting application. This enables
//		the engine to update these values without extra need for API calls. This is
//		especially of interest because the hosting application is not aware of what
//		instances are updated and 
//		The transformationMatrix has 12 double values: _11, _12, _13, _21, _22, _23, 
//		_31, _32, _33, _41, _42, _43.
//		The startVector is the leftundernear vector and the endVector is the 
//		rightupperfar vector, in all cases values are doubles (64 bit).
//
void		DECL STDC	SetBoundingBoxReference(
									int64_t			owlInstance,
									void			* transformationMatrix,
									void			* startVector,
									void			* endVector
								);



//
//		GetDependingPropertyCnt
//				int64_t				baseOwlInstance				ignored at this moment
//				int64_t				conceptualFace				IN
//
//				int64_t				returns						OUT
//
//		This function returns the number of properties that are of influence on the
//		location and form of the conceptualFace.
//
//		Note: BE AWARE, THIS FUNCTION EXPECTS A TREE, NOT A NETWORK, IN CASE OF A NETWORK THIS FUNCTION CAN LOCK THE ENGINE
//
int64_t		DECL STDC	GetDependingPropertyCnt(
									int64_t			baseOwlInstance,
									int64_t			conceptualFace
								);

//
//		GetDependingProperty
//				int64_t				baseOwlInstance				ignored at this moment
//				int64_t				conceptualFace				IN
//				int64_t				index						IN
//				int64_t				* instance					IN / OUT
//				int64_t				* _property					IN / OUT
//
//		This function returns a handle to the property that is the 'index'-th property
//		of influence on the form. It also returns the handle to instance this property
//		belongs to.
//
//		Note: the returned property is always a datatypeProperty
//		Note: if input is incorrect (for example index is in wrong domain) _property and
//			  instance will be both zero.
//
//		Note: BE AWARE, THIS FUNCTION EXPECTS A TREE, NOT A NETWORK, IN CASE OF A NETWORK THIS FUNCTION CAN LOCK THE ENGINE
//
void		DECL STDC	GetDependingProperty(
									int64_t			baseOwlInstance,
									int64_t			conceptualFace,
									int64_t			index,
									int64_t			* instance,
									int64_t			* _property
								);

	
	
//
//		OpenModel
//				char				* fileName					IN
//
//				int64_t				returns						OUT
//
//		This function opens the model on location fileName.
//		References inside to other ontologies will be included.
//		Existing memory will be deleted before opening the file.
//		A handle to the model will be returned, or 0 in case something went wrong.
//
int64_t		DECL STDC	OpenModel(
									const char		* fileName
								);

int64_t		DECL STDC	OpenModelW(
									const wchar_t	* fileName
								);

//
//		CloseModel
//				int64_t				model						IN
//
//		This function closes the model. After this call none of the instances and classes within the model
//		can be used anymore, also garbage collection is not allowed anymore, in default compilation the
//		model itself will be known in the kernel, however known to be disabled. Calls containing the model
//		reference will be protected from crashing when called.
//
int64_t		DECL STDC	CloseModel(
									int64_t			model
								);

//
//		CloseSession
//
//		This function closes the session, after this call the kernel cannot be used anymore.
//
int64_t		DECL STDC	CloseSession(
								);

//
//		AbortModel
//				int64_t				model						IN
//
//		This function abort running processes for a model.
//
int64_t		DECL STDC	AbortModel(
									int64_t			model,
									int64_t			setting
								);

//
//		SaveModel
//				int64_t				model						IN
//				char				* fileName					IN
//
//		This function saves the current model on location fileName.
//
int64_t		DECL STDC	SaveModel(
									int64_t			model,
									const char		* fileName
								);

int64_t		DECL STDC	SaveModelW(
									int64_t			model,
									const wchar_t	* fileName
								);

//
//		SetAssertionFile
//				char				* fileName					IN
//
//		This function sets the file location where internal assertions should be written to.
//		If the filename is not set (default) many internal control procedures are not executed
//		and the code will be faster.
//
void		DECL STDC	SetAssertionFile(
									const char		* fileName
								);

void		DECL STDC	CleanMemory(
								);

int64_t		DECL STDC	Intersect(
									int64_t			owlInstanceI,
									int64_t			owlInstanceII
								);

double		DECL STDC	GetCentroid(
									int64_t			owlInstance,
									void			* vertices,
									void			* indices,
									double			* centroid
								);

//
//		GetVolume
//				int64_t				owlInstance					IN
//				void				* vertices					optional IN
//				void				* indices					optional IN
//
//				double				returns						OUT
//
//		This function calculates the volume of an instance.
//		For perfomance reasons it is benefitial to call it with vertex and index array when
//		the arrays are calculated anyway or Volume and Area are needed.
//
//		There are two ways to call GetVolume:
//			vertices and indices are both zero: in this case the instance will be
//					recalculated when needed. It is expected the client does not
//					need the arrays itself or there is no performance issue.
//			vertices and indices are both given: the call is placed directly after
//					updateBuffer calls and no structural change to depending instances have 
//					been done in between. The transformationMatrix array is not needed,
//					even if it is being used due to not giving any performance gain to this
//					operation.
//
//		Note: internally the call does not store its results, any optimization based on known
//			  dependancies between instances need to be implemented on the client.
//		Note: in case precision is important and vertex array is 32 bit it is advised to
//			  set vertices and indices to 0 even if arrays are existing.
//
double		DECL STDC	GetVolume(
									int64_t			owlInstance,
									void			* vertices,
									void			* indices
								);

//
//		GetArea
//				int64_t				owlInstance					IN
//				void				* vertices					optional IN
//				void				* indices					optional IN
//
//				double				returns						OUT
//
//		This function calculates the area of an instance.
//		For perfomance reasons it is benefitial to call it with vertex and index array when
//		the arrays are calculated anyway or Volume and Area are needed.
//
//		There are two ways to call GetVolume:
//			vertices and indices are both zero: in this case the instance will be
//					recalculated when needed. It is expected the client does not
//					need the arrays itself or there is no performance issue.
//			vertices and indices are both given: the call is placed directly after
//					updateBuffer calls and no structural change to depending instances have 
//					been done in between. The transformationMatrix array is not needed,
//					even if it is being used due to not giving any performance gain to this
//					operation.
//
//		Note: internally the call does not store its results, any optimization based on known
//			  dependancies between instances need to be implemented on the client.
//		Note: in case precision is important and vertex array is 32 bit it is advised to
//			  set vertices and indices to 0 even if arrays are existing.
//
double		DECL STDC	GetArea(
									int64_t			owlInstance,
									void			* vertices,
									void			* indices
								);

//
//		GetPerimeter
//				int64_t				owlInstance					IN
//
//				double				returns						OUT
//
//		This function calculates the perimeter of an instance.
//
//		Note: internally the call does not store its results, any optimization based on known
//			  dependancies between instances need to be implemented on the client.
//		Note: due to internal structure using already calculated vertices/indices does not
//			  give any performance benefits, in opposite to GetVolume and GetArea
//
double		DECL STDC	GetPerimeter(
									int64_t			owlInstance
								);

//
//		GetSessionMetaInfo
//				int64_t				allocatedBlocks				IN/OUT
//				int64_t				allocatedBytes				IN/OUT
//				int64_t				nonUsedBlocks				IN/OUT
//				int64_t				nonUsedBytes				IN/OUT
//
void		DECL STDC	GetSessionMetaInfo(
									int64_t			* allocatedBlocks,
									int64_t			* allocatedBytes,
									int64_t			* nonUsedBlocks,
									int64_t			* nonUsedBytes
								);

//
//		GetModelMetaInfo
//				int64_t				model						IN
//				int64_t				allocatedInstances			IN/OUT
//				int64_t				allocatedUniqueInstances	IN/OUT
//				int64_t				activeInstances				IN/OUT
//				int64_t				activeUniqueInstances		IN/OUT
//				int64_t				removedInstances			IN/OUT
//				int64_t				removedUniqueInstances		IN/OUT
//				int64_t				inactiveUniqueInstances		IN/OUT
//				int64_t				allocatedBlocks				IN/OUT
//				int64_t				allocatedBytes				IN/OUT
//
void		DECL STDC	GetModelMetaInfo(
									int64_t			model,
									int64_t			* allocatedInstances,
									int64_t			* allocatedUniqueInstances,
									int64_t			* activeInstances,
									int64_t			* activeUniqueInstances,
									int64_t			* removedInstances,
									int64_t			* removedUniqueInstances,
									int64_t			* inactiveUniqueInstances,
									int64_t			* allocatedBlocks,
									int64_t			* allocatedBytes
								);

//
//		GetInstanceMetaInfo
//				int64_t				owlInstance					IN
//				int64_t				allocatedBlocks				IN/OUT
//				int64_t				allocatedBytes				IN/OUT
//
void		DECL STDC	GetInstanceMetaInfo(
									int64_t			owlInstance,
									int64_t			* allocatedBlocks,
									int64_t			* allocatedBytes
								);

//
//		CreateInstanceInContextStructure
//				int64_t				owlInstance					IN
//
//				int64_t				returns						OUT
//
//		InstanceInContext structures give you more detailed information about
//		individual parts of the geometry of a certain instance viualized.
//		It is allowed to have more then 1 InstanceInContext structures per instance.
//		InstanceInContext structures are updated dynamically when the geometry
//		structure is updated.
//
int64_t		DECL STDC	CreateInstanceInContextStructure(
									int64_t			owlInstance
								);

//
//		DestroyInstanceInContextStructure
//				int64_t				owlInstanceInContext		IN
//
//		InstanceInContext structures are updated dynamically and therfore even while the cost
//		in performance and memory is limited it is advised to destroy structures as soon
//		as they are obsolete.
//
void		DECL STDC	DestroyInstanceInContextStructure(
									int64_t			owlInstanceInContext
								);

//
//		InstanceInContextChild
//				int64_t				owlInstanceInContext		IN
//
//				int64_t				returns						OUT
//
int64_t		DECL STDC	InstanceInContextChild(
									int64_t			owlInstanceInContext
								);

//
//		InstanceInContextNext
//				int64_t				owlInstanceInContext		IN
//
//				int64_t				returns						OUT
//
int64_t		DECL STDC	InstanceInContextNext(
									int64_t			owlInstanceInContext
								);

//
//		InstanceInContextIsUpdated
//				int64_t				owlInstanceInContext		IN
//
//				int64_t				returns						OUT
//
int64_t		DECL STDC	InstanceInContextIsUpdated(
									int64_t			owlInstanceInContext
								);

//
//		GetTriangles
//				int64_t				owlInstance					IN
//				int64_t				* startIndex				IN / OUT
//				int64_t				* noTriangles				IN / OUT
//				int64_t				* startVertex				IN / OUT
//				int64_t				* firstNotUsedVertex		IN / OUT
//
//		This function returns where the triangles for a certain instance can be found.
//		Argument startIndex will be filled with the first index in de indexList.
//		Argument noTriangles will return the number of triangles, they are always placed
//		directly behind each other starting at position startIndex and each triangle has exactly 
//		3 unique indices (i.e. there is no support for advanced trianglelist types as known by DirectX).
//		Optional argument startVertex is the first vertex used by the triangles.
//		Optional argument firstNotUsedVertex is the first vertex after the last vertex used by the triangles.
//
//		Note: the last two optional arguments are relevant for improving DirectX performance, in general
//			  not every program will find them usefull. Both arguments are allowed to be called with NULL.
//
void		DECL STDC	GetTriangles(
									int64_t			owlInstance,
									int64_t			* startIndex,
									int64_t			* noTriangles,
									int64_t			* startVertex,
									int64_t			* firstNotUsedVertex
								);

//
//		GetLines
//				int64_t				owlInstance					IN
//				int64_t				* startIndex				IN / OUT
//				int64_t				* noLines					IN / OUT
//				int64_t				* startVertex				IN / OUT
//				int64_t				* firstNotUsedVertex		IN / OUT
//
//		This function returns where the lines for a certain instance can be found.
//		Argument startIndex will be filled with the first index in de indexList.
//		Argument noLines will return the number of lines, they are always placed
//		directly behind each other starting at position startIndex and each line has exactly 
//		2 unique indices (i.e. there is no support for advanced linelist types as known by DirectX).
//		Optional argument startVertex is the first vertex used by the lines.
//		Optional argument firstNotUsedVertex is the first vertex after the last vertex used by the lines.
//
//		Note: the last two optional arguments are relevant for improving DirectX performance, in general
//			  not every program will find them usefull.
//
void		DECL STDC	GetLines(
									int64_t			owlInstance,
									int64_t			* startIndex,
									int64_t			* noLines,
									int64_t			* startVertex,
									int64_t			* firstNotUsedVertex
								);

//
//		GetPoints
//				int64_t				owlInstance					IN
//				int64_t				* startIndex				IN / OUT
//				int64_t				* noPoints					IN / OUT
//				int64_t				* startVertex				IN / OUT
//				int64_t				* firstNotUsedVertex		IN / OUT
//
//		This function returns where the points for a certain instance can be found.
//		Argument startIndex will be filled with the first index in de indexList.
//		Argument noPoints will return the number of points, they are always placed
//		directly behind each other starting at position startIndex and each line has exactly 
//		Optional argument startVertex is the first vertex used by the points.
//		Optional argument firstNotUsedVertex is the first vertex after the last vertex used by the points.
//
//		Note: the last two optional arguments are relevant for improving DirectX performance, in general
//			  not every program will find them usefull.
//
void		DECL STDC	GetPoints(
									int64_t			owlInstance,
									int64_t			* startIndex,
									int64_t			* noPoints,
									int64_t			* startVertex,
									int64_t			* firstNotUsedVertex
								);



#undef DECL 
#undef STDC  

#ifdef __cplusplus
}
#endif
