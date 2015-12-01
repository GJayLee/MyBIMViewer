#if _MSC_VER > 1000
#pragma once
#pragma execution_character_set("utf-8")
#endif // _MSC_VER > 1000


#include"ifcengine.h"
#include"GenericTreeItem.h"


#ifdef WIN64
	#define int __int64
#endif


#define		ABSORBEDDOSEUNIT					101
#define		AREAUNIT							102
#define		DOSEEQUIVALENTUNIT					103
#define		ELECTRICCAPACITANCEUNIT				104
#define		ELECTRICCHARGEUNIT					105
#define		ELECTRICCONDUCTANCEUNIT				106
#define		ELECTRICCURRENTUNIT					107
#define		ELECTRICRESISTANCEUNIT				108
#define		ELECTRICVOLTAGEUNIT					109
#define		ENERGYUNIT							110
#define		FORCEUNIT							111
#define		FREQUENCYUNIT						112
#define		ILLUMINANCEUNIT						113
#define		INDUCTANCEUNIT						114
#define		LENGTHUNIT							115
#define		LUMINOUSFLUXUNIT					116
#define		LUMINOUSINTENSITYUNIT				117
#define		MAGNETICFLUXDENSITYUNIT				118
#define		MAGNETICFLUXUNIT					119
#define		MASSUNIT							120
#define		PLANEANGLEUNIT						121
#define		POWERUNIT							122
#define		PRESSUREUNIT						123
#define		RADIOACTIVITYUNIT					124
#define		SOLIDANGLEUNIT						125
#define		THERMODYNAMICTEMPERATUREUNIT		126
#define		TIMEUNIT							127
#define		VOLUMEUNIT							128
#define		USERDEFINED							129



typedef struct STRUCT__SIUNIT {
	int								type;
	char							* unitType;

#ifdef	_UNICODE
	wchar_t							* prefix;
	wchar_t							* name;
#else
	char							* prefix;
	char							* name;
#endif

	STRUCT__SIUNIT					* next;
}	STRUCT__SIUNIT;



#ifdef	_UNICODE
bool			Equals(wchar_t * txtI, wchar_t * txtII);
#else
bool			Equals(char * txtI, char * txtII);
#endif
bool			EqualsC(char * txtI, char * txtII);

STRUCT__SIUNIT	* GetUnits(int ifcModel, int ifcProjectInstance);
void			CreateIfcInstanceProperties(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcObjectInstance, STRUCT__SIUNIT * units);
bool			HasChildrenIfcInstanceProperties(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcObjectInstance, STRUCT__SIUNIT * units);



#undef int