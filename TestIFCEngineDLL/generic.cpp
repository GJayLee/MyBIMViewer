#pragma execution_character_set("utf-8")

#include "generic.h"



#ifdef WIN64
	#define int __int64
#endif



#ifdef	_UNICODE
bool	Equals(wchar_t * txtI, wchar_t * txtII)
#else
bool	Equals(char * txtI, char * txtII)
#endif
{
	int i = 0;

	while  (txtI  &&  txtI[i]) {
		if	(!txtII  ||  txtI[i] != txtII[i]) {
			return	false;
		}
		i++;
	}

	if	(txtII  &&  txtII[i]) {
		return	false;
	}

	return	true;
}

bool	EqualsC(char * txtI, char * txtII)
{
	int i = 0;

	while  (txtI  &&  txtI[i]) {
//#ifdef	_UNICODE
//		if	(!txtII  ||  txtI[i] != txtII[2*i]) {
//#else
		if	(!txtII  ||  txtI[i] != txtII[i]) {
//#endif
			return	false;
		}
		i++;
	}

//#ifdef	_UNICODE
//	if	(txtII  &&  txtII[2*i]) {
//#else
	if	(txtII  &&  txtII[i]) {
//#endif
		return	false;
	}

	return	true;
}

#ifdef	_UNICODE
wchar_t	* __copy__(wchar_t * txt)
#else
char	* __copy__(char * txt)
#endif
{
	if	(txt) {
		int	i = 0;
		while  (txt[i]) { i++; }
#ifdef	_UNICODE
		wchar_t	* rValue = new wchar_t[i+1];
#else
		char	* rValue = new char[i+1];
#endif
		i = 0;
		while  (txt[i]) {
			rValue[i] = txt[i];
			i++;
		}
		rValue[i] = 0;

		return	rValue;
	} else {
		return	0;
	}
}

double	__abs__(double value)
{
	if	(value < 0) {
		return	-value;
	} else {
		return	value;
	}
}



#undef int 