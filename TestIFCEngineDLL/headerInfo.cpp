#pragma execution_character_set("utf-8")

#include "headerInfo.h"
#include "generic.h"



#ifdef WIN64
	#define int __int64
#endif



#ifdef	_UNICODE
STRUCT__HEADER__SET	* CreateHeaderSet(STRUCT__HEADER__SET * parent, wchar_t * name, wchar_t * value)
#else
STRUCT__HEADER__SET	* CreateHeaderSet(STRUCT__HEADER__SET * parent, char * name, char * value)
#endif
{
	STRUCT__HEADER__SET	* headerSet = new STRUCT__HEADER__SET;

	headerSet->structType = STRUCT_TYPE_HEADER_SET;
	headerSet->name = __copy__(name);
	headerSet->value = __copy__(value);

	//headerSet->hTreeItem = 0;
#ifdef	_UNICODE
	headerSet->nameBuffer = new wchar_t[512];
#else
	headerSet->nameBuffer = new char[512];
#endif

	if	(parent) {
		STRUCT__HEADER__SET	** ppHeaderSet = &parent->child;
		while  ((*ppHeaderSet)) {
			ppHeaderSet = &(*ppHeaderSet)->next;
		}
		(*ppHeaderSet) = headerSet;
	}

	headerSet->child = 0;
	headerSet->next = 0;

	return	headerSet;
}


//
//		Get Header Info
//


STRUCT__HEADER__SET	* GetHeaderDescription(int ifcModel, STRUCT__HEADER__SET * parent)
{
#ifdef	_UNICODE
	STRUCT__HEADER__SET	* headerDescription = CreateHeaderSet(parent, L"Set of Descriptions", 0),
#else
	STRUCT__HEADER__SET	* headerDescription = CreateHeaderSet(parent, "Set of Descriptions", 0),
#endif
						** ppHeader = &headerDescription->child;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif
	int		i = 0;

#ifdef	_UNICODE
	if	(!GetSPFFHeaderItem(ifcModel, 0, i, sdaiUNICODE, (char **) &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 0, i++, sdaiUNICODE, (char **) &text)) {
			(* ppHeader) = CreateHeaderSet(headerDescription, L"Description", text);
#else
	if	(!GetSPFFHeaderItem(ifcModel, 0, i, sdaiSTRING, &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 0, i++, sdaiSTRING, &text)) {
			(* ppHeader) = CreateHeaderSet(headerDescription, "Description", text);
#endif
			ppHeader = &(* ppHeader)->next;
			text = 0;
		}
	}

	return	headerDescription;
}

STRUCT__HEADER__SET	* GetImplementationLevel(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerImplementationLevel = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 1, 0, sdaiUNICODE, (char **) &text);
	headerImplementationLevel = CreateHeaderSet(parent, L"ImplementationLevel", text);
#else
	GetSPFFHeaderItem(ifcModel, 1, 0, sdaiSTRING, &text);
	headerImplementationLevel = CreateHeaderSet(parent, "ImplementationLevel", text);
#endif

	return	headerImplementationLevel;
}

STRUCT__HEADER__SET	* GetName(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerName = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 2, 0, sdaiUNICODE, (char **) &text);
	headerName = CreateHeaderSet(parent, L"Name", text);
#else
	GetSPFFHeaderItem(ifcModel, 2, 0, sdaiSTRING, &text);
	headerName = CreateHeaderSet(parent, "Name", text);
#endif

	return	headerName;
}

STRUCT__HEADER__SET	* GetTimeStamp(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerTimeStamp = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 3, 0, sdaiUNICODE, (char **) &text);
	headerTimeStamp = CreateHeaderSet(parent, L"TimeStamp", text);
#else
	GetSPFFHeaderItem(ifcModel, 3, 0, sdaiSTRING, &text);
	headerTimeStamp = CreateHeaderSet(parent, "TimeStamp", text);
#endif

	return	headerTimeStamp;
}

STRUCT__HEADER__SET	* GetAuthor(int ifcModel, STRUCT__HEADER__SET * parent)
{
#ifdef	_UNICODE
	STRUCT__HEADER__SET	* headerAuthor = CreateHeaderSet(parent, L"Set of Authors", 0),
#else
	STRUCT__HEADER__SET	* headerAuthor = CreateHeaderSet(parent, "Set of Authors", 0),
#endif
						** ppHeader = &headerAuthor->child;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif
	int		i = 0;

#ifdef	_UNICODE
	if	(!GetSPFFHeaderItem(ifcModel, 4, i, sdaiUNICODE, (char **) &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 4, i++, sdaiUNICODE, (char **) &text)) {
			(* ppHeader) = CreateHeaderSet(headerAuthor, L"Author", text);
#else
	if	(!GetSPFFHeaderItem(ifcModel, 4, i, sdaiSTRING, &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 4, i++, sdaiSTRING, &text)) {
			(* ppHeader) = CreateHeaderSet(headerAuthor, "Author", text);
#endif
			ppHeader = &(* ppHeader)->next;
			text = 0;
		}
	}

	return	headerAuthor;
}

STRUCT__HEADER__SET	* GetOrganization(int ifcModel, STRUCT__HEADER__SET * parent)
{
#ifdef	_UNICODE
	STRUCT__HEADER__SET	* headerOrganization = CreateHeaderSet(parent, L"Set of Organizations", 0),
#else
	STRUCT__HEADER__SET	* headerOrganization = CreateHeaderSet(parent, "Set of Organizations", 0),
#endif
						** ppHeader = &headerOrganization->child;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif
	int		i = 0;

#ifdef	_UNICODE
	if	(!GetSPFFHeaderItem(ifcModel, 5, i, sdaiUNICODE, (char **) &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 5, i++, sdaiUNICODE, (char **) &text)) {
			(* ppHeader) = CreateHeaderSet(headerOrganization, L"Organization", text);
#else
	if	(!GetSPFFHeaderItem(ifcModel, 5, i, sdaiSTRING, &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 5, i++, sdaiSTRING, &text)) {
			(* ppHeader) = CreateHeaderSet(headerOrganization, "Organization", text);
#endif
			ppHeader = &(* ppHeader)->next;
			text = 0;
		}
	}

	return	headerOrganization;
}

STRUCT__HEADER__SET	* GetPreprocessorVersion(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerPreprocessorVersion = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 6, 0, sdaiUNICODE, (char **) &text);
	headerPreprocessorVersion = CreateHeaderSet(parent, L"PreprocessorVersion", text);
#else
	GetSPFFHeaderItem(ifcModel, 6, 0, sdaiSTRING, &text);
	headerPreprocessorVersion = CreateHeaderSet(parent, "PreprocessorVersion", text);
#endif

	return	headerPreprocessorVersion;
}

STRUCT__HEADER__SET	* GetOriginatingSystem(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerOriginatingSystem = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 7, 0, sdaiUNICODE, (char **) &text);
	headerOriginatingSystem = CreateHeaderSet(parent, L"OriginatingSystem", text);
#else
	GetSPFFHeaderItem(ifcModel, 7, 0, sdaiSTRING, &text);
	headerOriginatingSystem = CreateHeaderSet(parent, "OriginatingSystem", text);
#endif

	return	headerOriginatingSystem;
}

STRUCT__HEADER__SET	* GetAuthorization(int ifcModel, STRUCT__HEADER__SET * parent)
{
	STRUCT__HEADER__SET	* headerAuthorization = 0;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif

#ifdef	_UNICODE
	GetSPFFHeaderItem(ifcModel, 8, 0, sdaiUNICODE, (char **) &text);
	headerAuthorization = CreateHeaderSet(parent, L"Authorization", text);
#else
	GetSPFFHeaderItem(ifcModel, 8, 0, sdaiSTRING, &text);
	headerAuthorization = CreateHeaderSet(parent, "Authorization", text);
#endif

	return	headerAuthorization;
}

STRUCT__HEADER__SET	* GetFileSchema(int ifcModel, STRUCT__HEADER__SET * parent)
{
#ifdef	_UNICODE
	STRUCT__HEADER__SET	* headerFileSchema = CreateHeaderSet(parent, L"Set of FileSchemas", 0),
#else
	STRUCT__HEADER__SET	* headerFileSchema = CreateHeaderSet(parent, "Set of FileSchemas", 0),
#endif
						** ppHeader = &headerFileSchema->child;
#ifdef	_UNICODE
	wchar_t	* text = 0;
#else
	char	* text = 0;
#endif
	int		i = 0;

#ifdef	_UNICODE
	if	(!GetSPFFHeaderItem(ifcModel, 9, i, sdaiUNICODE, (char **) &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 9, i++, sdaiUNICODE, (char **) &text)) {
			(* ppHeader) = CreateHeaderSet(headerFileSchema, L"FileSchema", text);
#else
	if	(!GetSPFFHeaderItem(ifcModel, 9, i, sdaiSTRING, &text)) {
		while  (!GetSPFFHeaderItem(ifcModel, 9, i++, sdaiSTRING, &text)) {
			(* ppHeader) = CreateHeaderSet(headerFileSchema, "FileSchema", text);
#endif
			ppHeader = &(* ppHeader)->next;
			text = 0;
		}
	}

	return	headerFileSchema;
}

STRUCT__HEADER__SET	* GetHeaderInfo(int ifcModel)
{
#ifdef	_UNICODE
	STRUCT__HEADER__SET	* headerFileSchema = CreateHeaderSet(0, L"Header Info", 0),
#else
	STRUCT__HEADER__SET	* headerFileSchema = CreateHeaderSet(0, "Header Info", 0),
#endif
						** ppHeader = &headerFileSchema->child;

	(* ppHeader) = GetHeaderDescription(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetImplementationLevel(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetName(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetTimeStamp(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetAuthor(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetOrganization(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetPreprocessorVersion(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetOriginatingSystem(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetAuthorization(ifcModel, headerFileSchema);
	ppHeader = &(* ppHeader)->next;
	(* ppHeader) = GetFileSchema(ifcModel, headerFileSchema);

	return	headerFileSchema;
}



#undef int 