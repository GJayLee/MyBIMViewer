#pragma execution_character_set("utf-8")

#include "unit.h"


#ifdef WIN64
	#define int __int64
#endif



void	UnitAddUnitType(STRUCT__SIUNIT * unit, char * unitType)
{
	//
	//	unitType
	//
	if	(EqualsC(unitType, ".ABSORBEDDOSEUNIT.")) {
		unit->type = ABSORBEDDOSEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ABSORBEDDOSEUNIT";
#else
		unit->unitType = "ABSORBEDDOSEUNIT";
#endif
	} else if  (EqualsC(unitType, ".AREAUNIT.")) {
		unit->type = AREAUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"AREAUNIT";
#else
		unit->unitType = "AREAUNIT";
#endif
	} else if  (EqualsC(unitType, ".DOSEEQUIVALENTUNIT.")) {
		unit->type = DOSEEQUIVALENTUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"DOSEEQUIVALENTUNIT";
#else
		unit->unitType = "DOSEEQUIVALENTUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICCAPACITANCEUNIT.")) {
		unit->type = ELECTRICCAPACITANCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICCAPACITANCEUNIT";
#else
		unit->unitType = "ELECTRICCAPACITANCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICCHARGEUNIT.")) {
		unit->type = ELECTRICCHARGEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICCHARGEUNIT";
#else
		unit->unitType = "ELECTRICCHARGEUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICCONDUCTANCEUNIT.")) {
		unit->type = ELECTRICCONDUCTANCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICCONDUCTANCEUNIT";
#else
		unit->unitType = "ELECTRICCONDUCTANCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICCURRENTUNIT.")) {
		unit->type = ELECTRICCURRENTUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICCURRENTUNIT";
#else
		unit->unitType = "ELECTRICCURRENTUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICRESISTANCEUNIT.")) {
		unit->type = ELECTRICRESISTANCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICRESISTANCEUNIT";
#else
		unit->unitType = "ELECTRICRESISTANCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".ELECTRICVOLTAGEUNIT.")) {
		unit->type = ELECTRICVOLTAGEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ELECTRICVOLTAGEUNIT";
#else
		unit->unitType = "ELECTRICVOLTAGEUNIT";
#endif
	} else if  (EqualsC(unitType, ".ENERGYUNIT.")) {
		unit->type = ENERGYUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ENERGYUNIT";
#else
		unit->unitType = "ENERGYUNIT";
#endif
	} else if  (EqualsC(unitType, ".FORCEUNIT.")) {
		unit->type = FORCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"FORCEUNIT";
#else
		unit->unitType = "FORCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".FREQUENCYUNIT.")) {
		unit->type = FREQUENCYUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"FREQUENCYUNIT";
#else
		unit->unitType = "FREQUENCYUNIT";
#endif
	} else if  (EqualsC(unitType, ".ILLUMINANCEUNIT.")) {
		unit->type = ILLUMINANCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"ILLUMINANCEUNIT";
#else
		unit->unitType = "ILLUMINANCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".INDUCTANCEUNIT.")) {
		unit->type = INDUCTANCEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"INDUCTANCEUNIT";
#else
		unit->unitType = "INDUCTANCEUNIT";
#endif
	} else if  (EqualsC(unitType, ".LENGTHUNIT.")) {
		unit->type = LENGTHUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"LENGTHUNIT";
#else
		unit->unitType = "LENGTHUNIT";
#endif
	} else if  (EqualsC(unitType, ".LUMINOUSFLUXUNIT.")) {
		unit->type = LUMINOUSFLUXUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"LUMINOUSFLUXUNIT";
#else
		unit->unitType = "LUMINOUSFLUXUNIT";
#endif
	} else if  (EqualsC(unitType, ".LUMINOUSINTENSITYUNIT.")) {
		unit->type = LUMINOUSINTENSITYUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"LUMINOUSINTENSITYUNIT";
#else
		unit->unitType = "LUMINOUSINTENSITYUNIT";
#endif
	} else if  (EqualsC(unitType, ".MAGNETICFLUXDENSITYUNIT.")) {
		unit->type = MAGNETICFLUXDENSITYUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"MAGNETICFLUXDENSITYUNIT";
#else
		unit->unitType = "MAGNETICFLUXDENSITYUNIT";
#endif
	} else if  (EqualsC(unitType, ".MAGNETICFLUXUNIT.")) {
		unit->type = MAGNETICFLUXUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"MAGNETICFLUXUNIT";
#else
		unit->unitType = "MAGNETICFLUXUNIT";
#endif
	} else if  (EqualsC(unitType, ".MASSUNIT.")) {
		unit->type = MASSUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"MASSUNIT";
#else
		unit->unitType = "MASSUNIT";
#endif
	} else if  (EqualsC(unitType, ".PLANEANGLEUNIT.")) {
		unit->type = PLANEANGLEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"PLANEANGLEUNIT";
#else
		unit->unitType = "PLANEANGLEUNIT";
#endif
	} else if  (EqualsC(unitType, ".POWERUNIT.")) {
		unit->type = POWERUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"POWERUNIT";
#else
		unit->unitType = "POWERUNIT";
#endif
	} else if  (EqualsC(unitType, ".PRESSUREUNIT.")) {
		unit->type = PRESSUREUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"PRESSUREUNIT";
#else
		unit->unitType = "PRESSUREUNIT";
#endif
	} else if  (EqualsC(unitType, ".RADIOACTIVITYUNIT.")) {
		unit->type = RADIOACTIVITYUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"RADIOACTIVITYUNIT";
#else
		unit->unitType = "RADIOACTIVITYUNIT";
#endif
	} else if  (EqualsC(unitType, ".SOLIDANGLEUNIT.")) {
		unit->type = SOLIDANGLEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"SOLIDANGLEUNIT";
#else
		unit->unitType = "SOLIDANGLEUNIT";
#endif
	} else if  (EqualsC(unitType, ".THERMODYNAMICTEMPERATUREUNIT.")) {
		unit->type = THERMODYNAMICTEMPERATUREUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"THERMODYNAMICTEMPERATUREUNIT";
#else
		unit->unitType = "THERMODYNAMICTEMPERATUREUNIT";
#endif
	} else if  (EqualsC(unitType, ".TIMEUNIT.")) {
		unit->type = TIMEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"TIMEUNIT";
#else
		unit->unitType = "TIMEUNIT";
#endif
	} else if  (EqualsC(unitType, ".VOLUMEUNIT.")) {
		unit->type = VOLUMEUNIT;
#ifdef	_UNICODE
		unit->unitType = (char *) L"VOLUMEUNIT";
#else
		unit->unitType = "VOLUMEUNIT";
#endif
	} else if  (EqualsC(unitType, ".USERDEFINED.")) {
		unit->type = USERDEFINED;
#ifdef	_UNICODE
		unit->unitType = (char *) L"USERDEFINED";
#else
		unit->unitType = "USERDEFINED";
#endif
	} else {
		//ASSERT(false);
		return;
	}
}

void	UnitAddPrefix(STRUCT__SIUNIT * unit, char * prefix)
{
	//
	//	prefix
	//
	if	(EqualsC(prefix, ".EXA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Exa";
#else
		unit->prefix = "Exa";
#endif
	} else if  (EqualsC(prefix, ".PETA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Peta";
#else
		unit->prefix = "Peta";
#endif
	} else if  (EqualsC(prefix, ".TERA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Tera";
#else
		unit->prefix = "Tera";
#endif
	} else if  (EqualsC(prefix, ".GIGA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Giga";
#else
		unit->prefix = "Giga";
#endif
	} else if  (EqualsC(prefix, ".MEGA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Mega";
#else
		unit->prefix = "Mega";
#endif
	} else if  (EqualsC(prefix, ".KILO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Kilo";
#else
		unit->prefix = "Kilo";
#endif
	} else if  (EqualsC(prefix, ".HECTO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Hecto";
#else
		unit->prefix = "Hecto";
#endif
	} else if  (EqualsC(prefix, ".DECA.")) {
#ifdef	_UNICODE
		unit->prefix = L"Deca";
#else
		unit->prefix = "Deca";
#endif
	} else if  (EqualsC(prefix, ".DECI.")) {
#ifdef	_UNICODE
		unit->prefix = L"Deci";
#else
		unit->prefix = "Deci";
#endif
	} else if  (EqualsC(prefix, ".CENTI.")) {
#ifdef	_UNICODE
		unit->prefix = L"Centi";
#else
		unit->prefix = "Centi";
#endif
	} else if  (EqualsC(prefix, ".MILLI.")) {
#ifdef	_UNICODE
		unit->prefix = L"Milli";
#else
		unit->prefix = "Milli";
#endif
	} else if  (EqualsC(prefix, ".MICRO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Micro";
#else
		unit->prefix = "Micro";
#endif
	} else if  (EqualsC(prefix, ".NANO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Nano";
#else
		unit->prefix = "Nano";
#endif
	} else if  (EqualsC(prefix, ".PICO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Pico";
#else
		unit->prefix = "Pico";
#endif
	} else if  (EqualsC(prefix, ".FEMTO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Femto";
#else
		unit->prefix = "Femto";
#endif
	} else if  (EqualsC(prefix, ".ATTO.")) {
#ifdef	_UNICODE
		unit->prefix = L"Atto";
#else
		unit->prefix = "Atto";
#endif
	} else {
		//ASSERT(prefix == 0);
		if (prefix != 0)
			return;
	}
}

void	UnitAddName(STRUCT__SIUNIT * unit, char * name)
{
	//
	//	name
	//
	if	(EqualsC(name, ".AMPERE.")) {
#ifdef	_UNICODE
		unit->name = L"Ampere";
#else
		unit->name = "Ampere";
#endif
	} else if  (EqualsC(name, ".BECQUEREL.")) {
#ifdef	_UNICODE
		unit->name = L"Becquerel";
#else
		unit->name = "Becquerel";
#endif
	} else if  (EqualsC(name, ".CANDELA.")) {
#ifdef	_UNICODE
		unit->name = L"Candela";
#else
		unit->name = "Candela";
#endif
	} else if  (EqualsC(name, ".COULOMB.")) {
#ifdef	_UNICODE
		unit->name = L"Coulomb";
#else
		unit->name = "Coulomb";
#endif
	} else if  (EqualsC(name, ".CUBIC_METRE.")) {
#ifdef	_UNICODE
		unit->name = L"Cubic Metre";
#else
		unit->name = "Cubic Metre";
#endif
	} else if  (EqualsC(name, ".DEGREE_CELSIUS.")) {
#ifdef	_UNICODE
		unit->name = L"Degree Celcius";
#else
		unit->name = "Degree Celcius";
#endif
	} else if  (EqualsC(name, ".FARAD.")) {
#ifdef	_UNICODE
		unit->name = L"Farad";
#else
		unit->name = "Farad";
#endif
	} else if  (EqualsC(name, ".GRAM.")) {
#ifdef	_UNICODE
		unit->name = L"Gram";
#else
		unit->name = "Gram";
#endif
	} else if  (EqualsC(name, ".GRAY.")) {
#ifdef	_UNICODE
		unit->name = L"Gray";
#else
		unit->name = "Gray";
#endif
	} else if  (EqualsC(name, ".HENRY.")) {
#ifdef	_UNICODE
		unit->name = L"Henry";
#else
		unit->name = "Henry";
#endif
	} else if  (EqualsC(name, ".HERTZ.")) {
#ifdef	_UNICODE
		unit->name = L"Hertz";
#else
		unit->name = "Hertz";
#endif
	} else if  (EqualsC(name, ".JOULE.")) {
#ifdef	_UNICODE
		unit->name = L"Joule";
#else
		unit->name = "Joule";
#endif
	} else if  (EqualsC(name, ".KELVIN.")) {
#ifdef	_UNICODE
		unit->name = L"Kelvin";
#else
		unit->name = "Kelvin";
#endif
	} else if  (EqualsC(name, ".LUMEN.")) {
#ifdef	_UNICODE
		unit->name = L"Lumen";
#else
		unit->name = "Lumen";
#endif
	} else if  (EqualsC(name, ".LUX.")) {
#ifdef	_UNICODE
		unit->name = L"Lux";
#else
		unit->name = "Lux";
#endif
	} else if  (EqualsC(name, ".METRE.")) {
#ifdef	_UNICODE
		unit->name = L"Metre";
#else
		unit->name = "Metre";
#endif
	} else if  (EqualsC(name, ".MOLE.")) {
#ifdef	_UNICODE
		unit->name = L"Mole";
#else
		unit->name = "Mole";
#endif
	} else if  (EqualsC(name, ".NEWTON.")) {
#ifdef	_UNICODE
		unit->name = L"Newton";
#else
		unit->name = "Newton";
#endif
	} else if  (EqualsC(name, ".OHM.")) {
#ifdef	_UNICODE
		unit->name = L"Ohm";
#else
		unit->name = "Ohm";
#endif
	} else if  (EqualsC(name, ".PASCAL.")) {
#ifdef	_UNICODE
		unit->name = L"Pascal";
#else
		unit->name = "Pascal";
#endif
	} else if  (EqualsC(name, ".RADIAN.")) {
#ifdef	_UNICODE
		unit->name = L"Radian";
#else
		unit->name = "Radian";
#endif
	} else if  (EqualsC(name, ".SECOND.")) {
#ifdef	_UNICODE
		unit->name = L"Second";
#else
		unit->name = "Second";
#endif
	} else if  (EqualsC(name, ".SIEMENS.")) {
#ifdef	_UNICODE
		unit->name = L"Siemens";
#else
		unit->name = "Siemens";
#endif
	} else if  (EqualsC(name, ".SIEVERT.")) {
#ifdef	_UNICODE
		unit->name = L"Sievert";
#else
		unit->name = "Sievert";
#endif
	} else if  (EqualsC(name, ".SQUARE_METRE.")) {
#ifdef	_UNICODE
		unit->name = L"Square Metre";
#else
		unit->name = "Square Metre";
#endif
	} else if  (EqualsC(name, ".STERADIAN.")) {
#ifdef	_UNICODE
		unit->name = L"Steradian";
#else
		unit->name = "Steradian";
#endif
	} else if  (EqualsC(name, ".TESLA.")) {
#ifdef	_UNICODE
		unit->name = L"Tesla";
#else
		unit->name = "Tesla";
#endif
	} else if  (EqualsC(name, ".VOLT.")) {
#ifdef	_UNICODE
		unit->name = L"Volt";
#else
		unit->name = "Volt";
#endif
	} else if  (EqualsC(name, ".WATT.")) {
#ifdef	_UNICODE
		unit->name = L"Watt";
#else
		unit->name = "Watt";
#endif
	} else if  (EqualsC(name, ".WEBER.")) {
#ifdef	_UNICODE
		unit->name = L"Weber";
#else
		unit->name = "Weber";
#endif
	} else {
		//ASSERT(false);
		return;
	}
}

STRUCT__SIUNIT	* GetUnits(int ifcModel, int ifcProjectInstance)
{
	STRUCT__SIUNIT	* firstUnit = 0;

    int ifcUnitAssignmentInstance = 0;
#ifdef	_UNICODE
    sdaiGetAttrBN(ifcProjectInstance, (char *) L"UnitsInContext", sdaiINSTANCE, &ifcUnitAssignmentInstance);
#else
    sdaiGetAttrBN(ifcProjectInstance, "UnitsInContext", sdaiINSTANCE, &ifcUnitAssignmentInstance);
#endif

#ifdef	_UNICODE
	int	ifcConversianBasedUnit_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCCONVERSIONBASEDUNIT"),
		ifcSIUnit_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCSIUNIT");
#else
	int	ifcConversianBasedUnit_TYPE = sdaiGetEntity(ifcModel, "IFCCONVERSIONBASEDUNIT"),
		ifcSIUnit_TYPE = sdaiGetEntity(ifcModel, "IFCSIUNIT");
#endif

    int * unit_set = 0, unit_cnt, i = 0;
#ifdef	_UNICODE
    sdaiGetAttrBN(ifcUnitAssignmentInstance, (char *) L"Units", sdaiAGGR, &unit_set);
#else
    sdaiGetAttrBN(ifcUnitAssignmentInstance, "Units", sdaiAGGR, &unit_set);
#endif
    unit_cnt = sdaiGetMemberCount(unit_set);
	for (i = 0; i < unit_cnt; ++i) {
		int		ifcUnitInstance = 0;
		engiGetAggrElement(unit_set, i, sdaiINSTANCE, &ifcUnitInstance);
		if	(sdaiGetInstanceType(ifcUnitInstance) == ifcConversianBasedUnit_TYPE) {
			STRUCT__SIUNIT	* unit = new STRUCT__SIUNIT();
			unit->unitType = 0;
			unit->prefix = 0;
			unit->name = 0;
			unit->next = firstUnit;
			firstUnit = unit;

			int	ifcMeasureWithUnitInstance = 0;
#ifdef	_UNICODE
		    sdaiGetAttrBN(ifcUnitInstance, (char *) L"ConversionFactor", sdaiINSTANCE, &ifcMeasureWithUnitInstance);
#else
			sdaiGetAttrBN(ifcUnitInstance, "ConversionFactor", sdaiINSTANCE, &ifcMeasureWithUnitInstance);
#endif
			if	(ifcMeasureWithUnitInstance) {
				int	ifcSIUnitInstance = 0;
#ifdef	_UNICODE
			    sdaiGetAttrBN(ifcMeasureWithUnitInstance, (char *) L"UnitComponent", sdaiINSTANCE, &ifcSIUnitInstance);
#else
				sdaiGetAttrBN(ifcMeasureWithUnitInstance, "UnitComponent", sdaiINSTANCE, &ifcSIUnitInstance);
#endif
				if	(sdaiGetInstanceType(ifcSIUnitInstance) == ifcSIUnit_TYPE) {
					char	* unitType = 0, * prefix = 0, * name = 0;
#ifdef	_UNICODE
					sdaiGetAttrBN(ifcSIUnitInstance, (char *) L"UnitType", sdaiSTRING, &unitType);
					sdaiGetAttrBN(ifcSIUnitInstance, (char *) L"Prefix", sdaiSTRING, &prefix);
					sdaiGetAttrBN(ifcSIUnitInstance, (char *) L"Name", sdaiSTRING, &name);
#else
					sdaiGetAttrBN(ifcSIUnitInstance, "UnitType", sdaiSTRING, &unitType);
					sdaiGetAttrBN(ifcSIUnitInstance, "Prefix", sdaiSTRING, &prefix);
					sdaiGetAttrBN(ifcSIUnitInstance, "Name", sdaiSTRING, &name);
#endif
					UnitAddUnitType(unit, unitType);
					UnitAddPrefix(unit, prefix);
					UnitAddName(unit, name);
				} else {
					//ASSERT(false);
				}
			} else {
				//ASSERT(false);
			}
		} else if  (sdaiGetInstanceType(ifcUnitInstance) == ifcSIUnit_TYPE) {
			STRUCT__SIUNIT	* unit = new STRUCT__SIUNIT();
			unit->unitType = 0;
			unit->prefix = 0;
			unit->name = 0;
			unit->next = firstUnit;
			firstUnit = unit;

			char	* unitType = 0, * prefix = 0, * name = 0;
#ifdef	_UNICODE
			sdaiGetAttrBN(ifcUnitInstance, (char *) L"UnitType", sdaiSTRING, &unitType);
			sdaiGetAttrBN(ifcUnitInstance, (char *) L"Prefix", sdaiSTRING, &prefix);
			sdaiGetAttrBN(ifcUnitInstance, (char *) L"Name", sdaiSTRING, &name);
#else
			sdaiGetAttrBN(ifcUnitInstance, "UnitType", sdaiSTRING, &unitType);
			sdaiGetAttrBN(ifcUnitInstance, "Prefix", sdaiSTRING, &prefix);
			sdaiGetAttrBN(ifcUnitInstance, "Name", sdaiSTRING, &name);
#endif

			UnitAddUnitType(unit, unitType);
			UnitAddPrefix(unit, prefix);
			UnitAddName(unit, name);
		} else {
///////////////////			ASSERT(false);
		}
	}

	return	firstUnit;
}

#ifdef	_UNICODE
wchar_t	* GetUnit(STRUCT__SIUNIT * units, char * unitType)
#else
char	* GetUnit(STRUCT__SIUNIT * units, char * unitType)
#endif
{
	STRUCT__SIUNIT	* unit = units;

	while  (unit) {
		if	(EqualsC(unit->unitType, unitType)) {
			int i = 0, j = 0;
			if	(unit->prefix) {
				while  (unit->prefix[i]) { i++; }
				i++;
			}
			if	(unit->name) {
				while  (unit->name[j]) { j++; }
			}
#ifdef	_UNICODE
			wchar_t	* rValue = new wchar_t[i + j + 1];
#else
			char	* rValue = new char[i + j + 1];
#endif
			i = 0;
			if	(unit->prefix) {
				while  (unit->prefix[i]) { rValue[i++] = unit->prefix[i]; }
				rValue[i++] = ' ';
			}
			j = 0;
			if	(unit->name) {
				while  (unit->name[j]) { rValue[i + j++] = unit->name[j]; }
				rValue[i + j] = 0;
			}
			return	rValue;
		}
		unit = unit->next;
	}

	return	0;
}

void	CreateIfcPropertySingleValue(int ifcModel, int ifcPropertySingleValue, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* nominalValue = 0,
#else
	char	* nominalValue = 0,
#endif
			* unit = 0;
	char	* typePath = 0;
	int		* nominalValueADB = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcPropertySingleValue, (char *) L"NominalValue", sdaiUNICODE, &nominalValue);
	if	(nominalValue) {
		sdaiGetAttrBN(ifcPropertySingleValue, (char *) L"NominalValue", sdaiADB, &nominalValueADB);
		typePath = sdaiGetADBTypePath(nominalValueADB, 0);
		sdaiGetAttrBN(ifcPropertySingleValue, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcPropertySingleValue, "NominalValue", sdaiSTRING, &nominalValue);
	if	(nominalValue) {
		sdaiGetAttrBN(ifcPropertySingleValue, "NominalValue", sdaiADB, &nominalValueADB);
		typePath = sdaiGetADBTypePath(nominalValueADB, 0);
		sdaiGetAttrBN(ifcPropertySingleValue, "Unit", sdaiSTRING, &unit);
#endif
		if	(unit == 0) {
#ifdef	_UNICODE
			if	(EqualsC(typePath, "IFCBOOLEAN")) {
				} else if  (EqualsC(typePath, "IFCIDENTIFIER")) {
				} else if  (EqualsC(typePath, "IFCINTEGER")) {
				} else if  (EqualsC(typePath, "IFCLABEL")) {
				} else if  (EqualsC(typePath, "IFCTEXT")) {
				} else if  (EqualsC(typePath, "IFCREAL")) {
				} else if  (EqualsC(typePath, "IFCCOUNTMEASURE")) {
				} else if  (EqualsC(typePath, "IFCPOSITIVERATIOMEASURE")) {
				} else if  (EqualsC(typePath, "IFCVOLUMETRICFLOWRATEMEASURE")) {
				} else if  (EqualsC(typePath, "IFCABSORBEDDOSEMEASURE")) {
					unit = GetUnit(units, (char *) L"ABSORBEDDOSEUNIT");
				} else if  (EqualsC(typePath, "IFCAMOUNTOFSUBSTANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"AMOUNTOFSUBSTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCAREAMEASURE")) {
					unit = GetUnit(units, (char *) L"AREAUNIT");
				} else if  (EqualsC(typePath, "IFCDOSEEQUIVALENTMEASURE")) {
					unit = GetUnit(units, (char *) L"DOSEEQUIVALENTUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCAPACITANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICCAPACITANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCHARGEMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICCHARGEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCONDUCTANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICCONDUCTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCURRENTMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICCURRENTUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICRESISTANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICRESISTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICVOLTAGEMEASURE")) {
					unit = GetUnit(units, (char *) L"ELECTRICVOLTAGEUNIT");
				} else if  (EqualsC(typePath, "IFCENERGYMEASURE")) {
					unit = GetUnit(units, (char *) L"ENERGYUNIT");
				} else if  (EqualsC(typePath, "IFCFORCEMEASURE")) {
					unit = GetUnit(units, (char *) L"FORCEUNIT");
				} else if  (EqualsC(typePath, "IFCFREQUENCYMEASURE")) {
					unit = GetUnit(units, (char *) L"FREQUENCYUNIT");
				} else if  (EqualsC(typePath, "IFCILLUMINANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"ILLUMINANCEUNIT");
				} else if  (EqualsC(typePath, "IFCINDUCTANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"INDUCTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCLENGTHMEASURE")  ||  EqualsC(typePath, "IFCPOSITIVELENGTHMEASURE")) {
					unit = GetUnit(units, (char *) L"LENGTHUNIT");
				} else if  (EqualsC(typePath, "IFCLUMINOUSFLUXMEASURE")) {
					unit = GetUnit(units, (char *) L"LUMINOUSFLUXUNIT");
				} else if  (EqualsC(typePath, "IFCLUMINOUSINTENSITYMEASURE")) {
					unit = GetUnit(units, (char *) L"LUMINOUSINTENSITYUNIT");
				} else if  (EqualsC(typePath, "IFCMAGNETICFLUXDENSITYMEASURE")) {
					unit = GetUnit(units, (char *) L"MAGNETICFLUXDENSITYUNIT");
				} else if  (EqualsC(typePath, "IFCMAGNETICFLUXMEASURE")) {
					unit = GetUnit(units, (char *) L"MAGNETICFLUXUNIT");
				} else if  (EqualsC(typePath, "IFCMASSMEASURE")) {
					unit = GetUnit(units, (char *) L"MASSUNIT");
				} else if  (EqualsC(typePath, "IFCPLANEANGLEMEASURE")) {
					unit = GetUnit(units, (char *) L"PLANEANGLEUNIT");
				} else if  (EqualsC(typePath, "IFPOWERCMEASURE")) {
					unit = GetUnit(units, (char *) L"POWERUNIT");
				} else if  (EqualsC(typePath, "IFCPRESSUREMEASURE")) {
					unit = GetUnit(units, (char *) L"PRESSUREUNIT");
				} else if  (EqualsC(typePath, "IFCRADIOACTIVITYMEASURE")) {
					unit = GetUnit(units, (char *) L"RADIOACTIVITYUNIT");
				} else if  (EqualsC(typePath, "IFCSOLIDANGLEMEASURE")) {
					unit = GetUnit(units, (char *) L"SOLIDANGLEUNIT");
				} else if  (EqualsC(typePath, "IFCTHERMODYNAMICTEMPERATUREMEASURE")) {
					unit = GetUnit(units, (char *) L"THERMODYNAMICTEMPERATUREUNIT");
				} else if  (EqualsC(typePath, "IFCTIMEMEASURE")) {
					unit = GetUnit(units, (char *) L"TIMEUNIT");
				} else if  (EqualsC(typePath, "IFCVOLUMEMEASURE")) {
					unit = GetUnit(units, (char *) L"VOLUMEUNIT");
				} else if  (EqualsC(typePath, "IFCUSERDEFINEDMEASURE")) {
					unit = GetUnit(units, (char *) L"USERDEFINED");
				} else if  (EqualsC(typePath, "IFCTHERMALTRANSMITTANCEMEASURE")) {
					unit = GetUnit(units, (char *) L"???");
#else
			if	(EqualsC(typePath, "IFCBOOLEAN")) {
				} else if  (EqualsC(typePath, "IFCIDENTIFIER")) {
				} else if  (EqualsC(typePath, "IFCINTEGER")) {
				} else if  (EqualsC(typePath, "IFCLABEL")) {
				} else if  (EqualsC(typePath, "IFCTEXT")) {
				} else if  (EqualsC(typePath, "IFCREAL")) {
				} else if  (EqualsC(typePath, "IFCCOUNTMEASURE")) {
				} else if  (EqualsC(typePath, "IFCPOSITIVERATIOMEASURE")) {
				} else if  (EqualsC(typePath, "IFCVOLUMETRICFLOWRATEMEASURE")) {
				} else if  (EqualsC(typePath, "IFCABSORBEDDOSEMEASURE")) {
					unit = GetUnit(units, "ABSORBEDDOSEUNIT");
				} else if  (EqualsC(typePath, "IFCAMOUNTOFSUBSTANCEMEASURE")) {
					unit = GetUnit(units, "AMOUNTOFSUBSTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCAREAMEASURE")) {
					unit = GetUnit(units, "AREAUNIT");
				} else if  (EqualsC(typePath, "IFCDOSEEQUIVALENTMEASURE")) {
					unit = GetUnit(units, "DOSEEQUIVALENTUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCAPACITANCEMEASURE")) {
					unit = GetUnit(units, "ELECTRICCAPACITANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCHARGEMEASURE")) {
					unit = GetUnit(units, "ELECTRICCHARGEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCONDUCTANCEMEASURE")) {
					unit = GetUnit(units, "ELECTRICCONDUCTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICCURRENTMEASURE")) {
					unit = GetUnit(units, "ELECTRICCURRENTUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICRESISTANCEMEASURE")) {
					unit = GetUnit(units, "ELECTRICRESISTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCELECTRICVOLTAGEMEASURE")) {
					unit = GetUnit(units, "ELECTRICVOLTAGEUNIT");
				} else if  (EqualsC(typePath, "IFCENERGYMEASURE")) {
					unit = GetUnit(units, "ENERGYUNIT");
				} else if  (EqualsC(typePath, "IFCFORCEMEASURE")) {
					unit = GetUnit(units, "FORCEUNIT");
				} else if  (EqualsC(typePath, "IFCFREQUENCYMEASURE")) {
					unit = GetUnit(units, "FREQUENCYUNIT");
				} else if  (EqualsC(typePath, "IFCILLUMINANCEMEASURE")) {
					unit = GetUnit(units, "ILLUMINANCEUNIT");
				} else if  (EqualsC(typePath, "IFCINDUCTANCEMEASURE")) {
					unit = GetUnit(units, "INDUCTANCEUNIT");
				} else if  (EqualsC(typePath, "IFCLENGTHMEASURE")  ||  EqualsC(typePath, "IFCPOSITIVELENGTHMEASURE")) {
					unit = GetUnit(units, "LENGTHUNIT");
				} else if  (EqualsC(typePath, "IFCLUMINOUSFLUXMEASURE")) {
					unit = GetUnit(units, "LUMINOUSFLUXUNIT");
				} else if  (EqualsC(typePath, "IFCLUMINOUSINTENSITYMEASURE")) {
					unit = GetUnit(units, "LUMINOUSINTENSITYUNIT");
				} else if  (EqualsC(typePath, "IFCMAGNETICFLUXDENSITYMEASURE")) {
					unit = GetUnit(units, "MAGNETICFLUXDENSITYUNIT");
				} else if  (EqualsC(typePath, "IFCMAGNETICFLUXMEASURE")) {
					unit = GetUnit(units, "MAGNETICFLUXUNIT");
				} else if  (EqualsC(typePath, "IFCMASSMEASURE")) {
					unit = GetUnit(units, "MASSUNIT");
				} else if  (EqualsC(typePath, "IFCPLANEANGLEMEASURE")) {
					unit = GetUnit(units, "PLANEANGLEUNIT");
				} else if  (EqualsC(typePath, "IFPOWERCMEASURE")) {
					unit = GetUnit(units, "POWERUNIT");
				} else if  (EqualsC(typePath, "IFCPRESSUREMEASURE")) {
					unit = GetUnit(units, "PRESSUREUNIT");
				} else if  (EqualsC(typePath, "IFCRADIOACTIVITYMEASURE")) {
					unit = GetUnit(units, "RADIOACTIVITYUNIT");
				} else if  (EqualsC(typePath, "IFCSOLIDANGLEMEASURE")) {
					unit = GetUnit(units, "SOLIDANGLEUNIT");
				} else if  (EqualsC(typePath, "IFCTHERMODYNAMICTEMPERATUREMEASURE")) {
					unit = GetUnit(units, "THERMODYNAMICTEMPERATUREUNIT");
				} else if  (EqualsC(typePath, "IFCTIMEMEASURE")) {
					unit = GetUnit(units, "TIMEUNIT");
				} else if  (EqualsC(typePath, "IFCVOLUMEMEASURE")) {
					unit = GetUnit(units, "VOLUMEUNIT");
				} else if  (EqualsC(typePath, "IFCUSERDEFINEDMEASURE")) {
					unit = GetUnit(units, "USERDEFINED");
				} else if  (EqualsC(typePath, "IFCTHERMALTRANSMITTANCEMEASURE")) {
					unit = GetUnit(units, "???");
#endif
				} else {
					//ASSERT(false);
					return;
				}
		} else {
			//ASSERT(false);
			return;
		}
		ifcProperty->nominalValue = __copy__(nominalValue);
		ifcProperty->unit = __copy__(unit);
	} else {
		ifcProperty->nominalValue = 0;
		ifcProperty->unit = 0;
	}
}

void	CreateIfcQuantityLength(int ifcModel, int ifcQuantityLength, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* lengthValue = 0,
#else
	char	* lengthValue = 0,
#endif
			* unit = 0;
	int		ifcUnitInstance = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityLength, (char *) L"LengthValue", sdaiUNICODE, &lengthValue);
	sdaiGetAttrBN(ifcQuantityLength, (char *) L"Unit", sdaiUNICODE, &unit);
	sdaiGetAttrBN(ifcQuantityLength, (char *) L"Unit", sdaiINSTANCE, &ifcUnitInstance);
#else
	sdaiGetAttrBN(ifcQuantityLength, "LengthValue", sdaiSTRING, &lengthValue);
	sdaiGetAttrBN(ifcQuantityLength, "Unit", sdaiSTRING, &unit);
	sdaiGetAttrBN(ifcQuantityLength, "Unit", sdaiINSTANCE, &ifcUnitInstance);
#endif
	//ASSERT(ifcUnitInstance == 0);
	if (ifcUnitInstance != 0)
		return;

	ifcProperty->lengthValue = __copy__(lengthValue);
	ifcProperty->unit = __copy__(unit);
	if	(unit == 0  ||  unit[0] == 0) {
		while  (units) {
			if	(units->type == LENGTHUNIT) {
				ifcProperty->unit = units->name;
			}
			units = units->next;
		}
	}
}

void	CreateIfcQuantityArea(int ifcModel, int ifcQuantityArea, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* areaValue = 0,
#else
	char	* areaValue = 0,
#endif
			* unit = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityArea, (char *) L"AreaValue", sdaiUNICODE, &areaValue);
	sdaiGetAttrBN(ifcQuantityArea, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcQuantityArea, "AreaValue", sdaiSTRING, &areaValue);
	sdaiGetAttrBN(ifcQuantityArea, "Unit", sdaiSTRING, &unit);
#endif

	ifcProperty->areaValue = __copy__(areaValue);
	ifcProperty->unit = __copy__(unit);
	if	(unit == 0  ||  unit[0] == 0) {
		while  (units) {
			if	(units->type == AREAUNIT) {
				ifcProperty->unit = units->name;
			}
			units = units->next;
		}
	}
}

void	CreateIfcQuantityVolume(int ifcModel, int ifcQuantityVolume, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* volumeValue = 0,
#else
	char	* volumeValue = 0,
#endif
			* unit = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityVolume, (char *) L"VolumeValue", sdaiUNICODE, &volumeValue);
	sdaiGetAttrBN(ifcQuantityVolume, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcQuantityVolume, "VolumeValue", sdaiSTRING, &volumeValue);
	sdaiGetAttrBN(ifcQuantityVolume, "Unit", sdaiSTRING, &unit);
#endif

	ifcProperty->volumeValue = __copy__(volumeValue);
	ifcProperty->unit = __copy__(unit);
	if	(unit == 0  ||  unit[0] == 0) {
		while  (units) {
			if	(units->type == VOLUMEUNIT) {
				ifcProperty->unit = units->name;
			}
			units = units->next;
		}
	}
}

void	CreateIfcQuantityCount(int ifcModel, int ifcQuantityCount, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* countValue = 0,
#else
	char	* countValue = 0,
#endif
			* unit = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityCount, (char *) L"CountValue", sdaiUNICODE, &countValue);
	sdaiGetAttrBN(ifcQuantityCount, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcQuantityCount, "CountValue", sdaiSTRING, &countValue);
	sdaiGetAttrBN(ifcQuantityCount, "Unit", sdaiSTRING, &unit);
#endif

	ifcProperty->countValue = __copy__(countValue);
	ifcProperty->unit = __copy__(unit);
}

void	CreateIfcQuantityWeigth(int ifcModel, int ifcQuantityWeigth, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* weigthValue = 0,
#else
	char	* weigthValue = 0,
#endif
			* unit = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityWeigth, (char *) L"WeigthValue", sdaiUNICODE, &weigthValue);
	sdaiGetAttrBN(ifcQuantityWeigth, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcQuantityWeigth, "WeigthValue", sdaiSTRING, &weigthValue);
	sdaiGetAttrBN(ifcQuantityWeigth, "Unit", sdaiSTRING, &unit);
#endif

	ifcProperty->weigthValue = __copy__(weigthValue);
	ifcProperty->unit = __copy__(unit);
	if	(unit == 0  ||  unit[0] == 0) {
		while  (units) {
			if	(units->type == MASSUNIT) {
				ifcProperty->unit = units->name;
			}
			units = units->next;
		}
	}
}

void	CreateIfcQuantityTime(int ifcModel, int ifcQuantityTime, STRUCT__PROPERTY * ifcProperty, STRUCT__SIUNIT * units)
{
#ifdef	_UNICODE
	wchar_t	* timeValue = 0,
#else
	char	* timeValue = 0,
#endif
			* unit = 0;
#ifdef	_UNICODE
	sdaiGetAttrBN(ifcQuantityTime, (char *) L"TimeValue", sdaiUNICODE, &timeValue);
	sdaiGetAttrBN(ifcQuantityTime, (char *) L"Unit", sdaiUNICODE, &unit);
#else
	sdaiGetAttrBN(ifcQuantityTime, "TimeValue", sdaiSTRING, &timeValue);
	sdaiGetAttrBN(ifcQuantityTime, "Unit", sdaiSTRING, &unit);
#endif

	ifcProperty->timeValue = __copy__(timeValue);
	ifcProperty->unit = __copy__(unit);
	if	(unit == 0  ||  unit[0] == 0) {
		while  (units) {
			if	(units->type == TIMEUNIT) {
				ifcProperty->unit = units->name;
			}
			units = units->next;
		}
	}
}

void	CreateIfcElementQuantity(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcPropertySetInstance, STRUCT__SIUNIT * units)
{
	STRUCT__PROPERTY__SET	** ppPropertySet = &ifcItem->propertySets;
	while  ((* ppPropertySet)) {
		ppPropertySet = &(* ppPropertySet)->next;
	}

#ifdef	_UNICODE
	wchar_t	* name = 0, * description = 0;
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"Name", sdaiUNICODE, &name);
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"Description", sdaiUNICODE, &description);
#else
	char	* name = 0, * description = 0;
	sdaiGetAttrBN(ifcPropertySetInstance, "Name", sdaiSTRING, &name);
	sdaiGetAttrBN(ifcPropertySetInstance, "Description", sdaiSTRING, &description);
#endif

	//ASSERT((* ppPropertySet) == 0);
	if ((*ppPropertySet) != 0)
		return;
	(* ppPropertySet) = CreateIfcPropertySet(ifcPropertySetInstance, name, description);
	STRUCT__PROPERTY	** ppProperty = &(* ppPropertySet)->properties;

	int	* ifcQuantityInstances = 0,
#ifdef	_UNICODE
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"Quantities", sdaiAGGR, &ifcQuantityInstances);
#else
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcPropertySetInstance, "Quantities", sdaiAGGR, &ifcQuantityInstances);
#endif
	if	(ifcQuantityInstances) {
		int	ifcQuantityInstancesCnt = sdaiGetMemberCount(ifcQuantityInstances);
		for  (int i = 0; i < ifcQuantityInstancesCnt; ++i) {
			int	ifcQuantityInstance = 0,
#ifdef	_UNICODE
				ifcQuantityLength_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYLENGTH"),
				ifcQuantityArea_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYAREA"),
				ifcQuantityVolume_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYVOLUME"),
				ifcQuantityCount_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYCOUNT"),
				ifcQuantityWeigth_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYWEIGHT"),
				ifcQuantityTime_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCQUANTITYTIME");
#else
				ifcQuantityLength_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYLENGTH"),
				ifcQuantityArea_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYAREA"),
				ifcQuantityVolume_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYVOLUME"),
				ifcQuantityCount_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYCOUNT"),
				ifcQuantityWeigth_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYWEIGHT"),
				ifcQuantityTime_TYPE = sdaiGetEntity(ifcModel, "IFCQUANTITYTIME");
#endif
			engiGetAggrElement(ifcQuantityInstances, i, sdaiINSTANCE, &ifcQuantityInstance);

#ifdef	_UNICODE
			wchar_t	* quantityName = 0, * quantityDescription = 0;
			sdaiGetAttrBN(ifcQuantityInstance, (char *) L"Name", sdaiUNICODE, &quantityName);
			sdaiGetAttrBN(ifcQuantityInstance, (char *) L"Description", sdaiUNICODE, &quantityDescription);
#else
			char	* quantityName = 0, * quantityDescription = 0;
			sdaiGetAttrBN(ifcQuantityInstance, "Name", sdaiSTRING, &quantityName);
			sdaiGetAttrBN(ifcQuantityInstance, "Description", sdaiSTRING, &quantityDescription);
#endif

			//ASSERT((* ppProperty) == 0);
			if ((*ppProperty) != 0)
				return;
			(* ppProperty) = CreateIfcProperty(ifcQuantityInstance, quantityName, quantityDescription);

			if	(sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityLength_TYPE) {
				CreateIfcQuantityLength(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else if  (sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityArea_TYPE) {
				CreateIfcQuantityArea(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else if  (sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityVolume_TYPE) {
				CreateIfcQuantityVolume(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else if  (sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityCount_TYPE) {
				CreateIfcQuantityCount(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else if  (sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityWeigth_TYPE) {
				CreateIfcQuantityWeigth(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else if  (sdaiGetInstanceType(ifcQuantityInstance) == ifcQuantityTime_TYPE) {
				CreateIfcQuantityTime(ifcModel, ifcQuantityInstance, (* ppProperty), units);
			} else {
				//ASSERT(false);
				return;
			}

			ppProperty = &(* ppProperty)->next;
		}
	}
}

void	CreateIfcPropertySet(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcPropertySetInstance, STRUCT__SIUNIT * units)
{
	STRUCT__PROPERTY__SET	** ppPropertySet = &ifcItem->propertySets;
	while  ((* ppPropertySet)) {
		ppPropertySet = &(* ppPropertySet)->next;
	}

#ifdef	_UNICODE
	wchar_t	* name = 0, * description = 0;
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"Name", sdaiUNICODE, &name);
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"Description", sdaiUNICODE, &description);
#else
	char	* name = 0, * description = 0;
	sdaiGetAttrBN(ifcPropertySetInstance, "Name", sdaiSTRING, &name);
	sdaiGetAttrBN(ifcPropertySetInstance, "Description", sdaiSTRING, &description);
#endif

	//ASSERT((* ppPropertySet) == 0);
	if ((*ppPropertySet) != 0)
		return;
	(* ppPropertySet) = CreateIfcPropertySet(ifcPropertySetInstance, name, description);
	STRUCT__PROPERTY	** ppProperty = &(* ppPropertySet)->properties;

	int	* ifcPropertyInstances = 0,
#ifdef	_UNICODE
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcPropertySetInstance, (char *) L"HasProperties", sdaiAGGR, &ifcPropertyInstances);
#else
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcPropertySetInstance, "HasProperties", sdaiAGGR, &ifcPropertyInstances);
#endif
	if	(ifcPropertyInstances) {
		int	ifcPropertyInstancesCnt = sdaiGetMemberCount(ifcPropertyInstances);
		for  (int i = 0; i < ifcPropertyInstancesCnt; ++i) {
			int	ifcPropertyInstance = 0,
#ifdef	_UNICODE
				ifcPropertySingleValue_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCPROPERTYSINGLEVALUE");
#else
				ifcPropertySingleValue_TYPE = sdaiGetEntity(ifcModel, "IFCPROPERTYSINGLEVALUE");
#endif
			engiGetAggrElement(ifcPropertyInstances, i, sdaiINSTANCE, &ifcPropertyInstance);

#ifdef	_UNICODE
			wchar_t	* propertyName = 0, * propertyDescription = 0;
			sdaiGetAttrBN(ifcPropertyInstance, (char *) L"Name", sdaiUNICODE, &propertyName);
			sdaiGetAttrBN(ifcPropertyInstance, (char *) L"Description", sdaiUNICODE, &propertyDescription);
#else
			char	* propertyName = 0, * propertyDescription = 0;
			sdaiGetAttrBN(ifcPropertyInstance, "Name", sdaiSTRING, &propertyName);
			sdaiGetAttrBN(ifcPropertyInstance, "Description", sdaiSTRING, &propertyDescription);
#endif

			//ASSERT((* ppProperty) == 0);
			if ((*ppProperty) != 0)
				return;
			(* ppProperty) = CreateIfcProperty(ifcPropertyInstance, propertyName, propertyDescription);

			if	(sdaiGetInstanceType(ifcPropertyInstance) == ifcPropertySingleValue_TYPE) {
				CreateIfcPropertySingleValue(ifcModel, ifcPropertyInstance, (* ppProperty), units);
			} else {
//				ASSERT(false);	
			}

			ppProperty = &(* ppProperty)->next;
		}
	}
}

void	CreateTypeObjectInstance(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcTypeObjectInstance, STRUCT__SIUNIT * units)
{
	if	(ifcTypeObjectInstance) {
		int	* hasPropertySets = 0, hasPropertySetsCnt,
#ifdef	_UNICODE
			ifcElementQuantity_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCELEMENTQUANTITY"),
			ifcPropertySet_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCPROPERTYSET");
		sdaiGetAttrBN(ifcTypeObjectInstance, (char *) L"HasPropertySets", sdaiAGGR, &hasPropertySets);
#else
			ifcElementQuantity_TYPE = sdaiGetEntity(ifcModel, "IFCELEMENTQUANTITY"),
			ifcPropertySet_TYPE = sdaiGetEntity(ifcModel, "IFCPROPERTYSET");
		sdaiGetAttrBN(ifcTypeObjectInstance, "HasPropertySets", sdaiAGGR, &hasPropertySets);
#endif
		hasPropertySetsCnt = sdaiGetMemberCount(hasPropertySets);
		for  (int i = 0; i < hasPropertySetsCnt; ++i) {
			int	hasPropertySetInstance = 0;
			engiGetAggrElement(hasPropertySets, i, sdaiINSTANCE, &hasPropertySetInstance);
			if	(sdaiGetInstanceType(hasPropertySetInstance) == ifcElementQuantity_TYPE) {
				CreateIfcElementQuantity(ifcModel, ifcItem, hasPropertySetInstance, units);
			} else if  (sdaiGetInstanceType(hasPropertySetInstance) == ifcPropertySet_TYPE) {
				CreateIfcPropertySet(ifcModel, ifcItem, hasPropertySetInstance, units);
			} else {
				//ASSERT(false);
				return;
			}
		}
	}
}

void	CreateRelDefinesByProperties(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcRelDefinesByProperties, STRUCT__SIUNIT * units)
{
	if	(ifcRelDefinesByProperties) {
		int	ifcPropertySetInstance = 0,
#ifdef	_UNICODE
			ifcElementQuantity_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCELEMENTQUANTITY"),
			ifcPropertySet_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCPROPERTYSET");
		sdaiGetAttrBN(ifcRelDefinesByProperties, (char *) L"RelatingPropertyDefinition", sdaiINSTANCE, &ifcPropertySetInstance);
#else
			ifcElementQuantity_TYPE = sdaiGetEntity(ifcModel, "IFCELEMENTQUANTITY"),
			ifcPropertySet_TYPE = sdaiGetEntity(ifcModel, "IFCPROPERTYSET");
		sdaiGetAttrBN(ifcRelDefinesByProperties, "RelatingPropertyDefinition", sdaiINSTANCE, &ifcPropertySetInstance);
#endif
		if	(sdaiGetInstanceType(ifcPropertySetInstance) == ifcElementQuantity_TYPE) {
			CreateIfcElementQuantity(ifcModel, ifcItem, ifcPropertySetInstance, units);
		} else if  (sdaiGetInstanceType(ifcPropertySetInstance) == ifcPropertySet_TYPE) {
			CreateIfcPropertySet(ifcModel, ifcItem, ifcPropertySetInstance, units);
		} else {
			//ASSERT(false);
			return;
		}
	} else {
		//ASSERT(false);
		return;
	}
}

void	CreateIfcInstanceProperties(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcObjectInstance, STRUCT__SIUNIT * units)
{
	int	* isDefinedByInstances = 0,
#ifdef	_UNICODE
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcObjectInstance, (char *) L"IsDefinedBy", sdaiAGGR, &isDefinedByInstances);
#else
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcObjectInstance, "IsDefinedBy", sdaiAGGR, &isDefinedByInstances);
#endif
	if	(isDefinedByInstances) {
		int	typeCnt = 0,
			isDefinedByInstancesCnt = sdaiGetMemberCount(isDefinedByInstances);
		for  (int i = 0; i < isDefinedByInstancesCnt; ++i) {
			int	isDefinedByInstance = 0;
			engiGetAggrElement(isDefinedByInstances, i, sdaiINSTANCE, &isDefinedByInstance);

			if	(sdaiGetInstanceType(isDefinedByInstance) == ifcRelDefinesByType_TYPE) {
				int	typeObjectInstance = 0;
#ifdef	_UNICODE
				sdaiGetAttrBN(isDefinedByInstance, (char *) L"RelatingType", sdaiINSTANCE, &typeObjectInstance);
#else
				sdaiGetAttrBN(isDefinedByInstance, "RelatingType", sdaiINSTANCE, &typeObjectInstance);
#endif
				CreateTypeObjectInstance(ifcModel, ifcItem, typeObjectInstance, units);
			} else if  (sdaiGetInstanceType(isDefinedByInstance) == ifcRelDefinesByProperties_TYPE) {
				CreateRelDefinesByProperties(ifcModel, ifcItem, isDefinedByInstance, units);
			} else {
				//ASSERT(false);
				return;
			}
		}
	}
}


bool	HasChildrenIfcInstanceProperties(int ifcModel, STRUCT__IFC__ITEM * ifcItem, int ifcObjectInstance, STRUCT__SIUNIT * units)
{
	int	* isDefinedByInstances = 0,
#ifdef	_UNICODE
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, (char *) L"IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcObjectInstance, (char *) L"IsDefinedBy", sdaiAGGR, &isDefinedByInstances);
#else
		ifcRelDefinesByType_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYTYPE"),
		ifcRelDefinesByProperties_TYPE = sdaiGetEntity(ifcModel, "IFCRELDEFINESBYPROPERTIES");
	sdaiGetAttrBN(ifcObjectInstance, "IsDefinedBy", sdaiAGGR, &isDefinedByInstances);
#endif
	if	(isDefinedByInstances) {
		int	typeCnt = 0,
			isDefinedByInstancesCnt = sdaiGetMemberCount(isDefinedByInstances);
		for  (int i = 0; i < isDefinedByInstancesCnt; ++i) {
			int	isDefinedByInstance = 0;
			engiGetAggrElement(isDefinedByInstances, i, sdaiINSTANCE, &isDefinedByInstance);

			if	(sdaiGetInstanceType(isDefinedByInstance) == ifcRelDefinesByType_TYPE) {
				//...
			} else if  (sdaiGetInstanceType(isDefinedByInstance) == ifcRelDefinesByProperties_TYPE) {
				return	true;
			} else {
				//ASSERT(false);
			}
		}
	}

	return	false;
}



#undef int 