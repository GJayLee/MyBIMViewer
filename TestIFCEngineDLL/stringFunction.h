#pragma once
#pragma execution_character_set("utf-8")

//#include"stdafx.h"

bool contains(wchar_t * txtI, wchar_t* txtII)
{
	int		i = 0;
	while (txtI[i] && txtII[i]) {
		if (txtI[i] != txtII[i]) {
			return	false;
		}
		i++;
	}
	if (txtII[i]) {
		return	false;
	}
	else {
		return	true;
	}
}

bool charContains(wchar_t* txtI, wchar_t* txtII)
{
	int i = 0;
	while (txtI[i]) {
		int j = 0;
		while (txtII[j] && txtI[i + j] == txtII[j]) {
			j++;
		}
		if (!txtII[j]) { return  true; }
		i++;
	}
	return	false;
}

wchar_t	*charFill(wchar_t * txtI, wchar_t * txtII, wchar_t * buffer)
{
	int i = 0;
	while (txtI[i]) {
		int j = 0;
		while (txtII[j] && txtI[i + j] == txtII[j]) {
			j++;
		}
		if (!txtII[j]) {
			i += j;
			//ASSERT(txtI[i + 0] == '=');
			//ASSERT(txtI[i + 1] == '"');
			i += 2;
			j = 0;
			while (txtI[i + j] != '"') {
				buffer[j++] = txtI[i + j];
			}
			buffer[j] = 0;
			return	buffer;
		}
		i++;
	}
	return	false;
}

bool charFind(wchar_t * txtI, wchar_t * txtII)
{
	int i = 0;
	while (txtI[i] && txtI[i] != '>') {
		int j = 0;
		while (txtII[j] && txtI[i + j] == txtII[j]) {
			j++;
		}
		if (!txtII[j]) {
			return	true;
		}
		i++;
	}
	return	false;
}



////判断是否是同一个点
//bool equalVertex(osg::Vec3 v1, osg::Vec3 v2)
//{
//	return (v1._v[0] == v2._v[0] && v1._v[1] == v2._v[1] && v1._v[2] == v2._v[2]) ? 1 : 0;
//}
//
////添加新的点
//bool addVertex(osg::Vec3Array *vertices, osg::Vec3 v, int vertexNum)
//{
//	for (int i = 0; i < vertexNum; i++)
//	{
//		//if (equalVertex((*vertices)[i], v))
//		if ((*vertices)[i] == v)
//		{
//			//(*vertices)[vertices->size()].set(v._v[0], v._v[1], v._v[2]);
//			return false;
//		}
//	}
//	return true;
//}