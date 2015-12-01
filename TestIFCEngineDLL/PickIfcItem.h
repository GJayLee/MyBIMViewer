#pragma once
#pragma execution_character_set("utf-8")

#include<tchar.h>

#include<osg\Group>
#include<osgGA\GUIEventHandler>
#include<osgUtil\LineSegmentIntersector>
#include<osg\MatrixTransform>
#include<osg\LineStipple>

#include"IFCEngineInteract.h"
#include"unit.h"

class CPickHandler : public osgGA::GUIEventHandler
{
public:
	CPickHandler(int model, osgViewer::Viewer* viewer) :ifcModel(model), mViewer(viewer)
	{
		lastSelect = new osg::Node;
		lastPickNode = 0;
		lastIfcItem = NULL;
	}
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		switch (ea.getEventType())
		{
		case osgGA::GUIEventAdapter::PUSH:
			if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
			{
				//点选
				//Pick(ea.getX(), ea.getY());
				
				//点选并显示包围盒
				/*if (lastPickNode)
				{
					lastPickNode->asGeode()->removeDrawable(lastPickNode->asGeode()->getDrawable(lastPickNode->asGeode()->getNumDrawables() - 1));
					lastPickNode = 0;
				}
				PickAndShowBoundingBox(ea.getX(), ea.getY());*/
			}
			if (ea.getButton() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
			{
				OpenDoor(ea.getX(), ea.getY());
			}
			break;
		case osgGA::GUIEventAdapter::MOVE:
			if (lastSelect && lastIfcItem)
			{
				//把选中的物体的颜色设置回原来的颜色
				if (lastIfcItem->itemColor)
				{
					osg::StateSet* state = lastSelect->getOrCreateStateSet();
					osg::Material* material = dynamic_cast<osg::Material*>(state->getAttribute(osg::StateAttribute::MATERIAL));
					if (!material)
					{
						material = new osg::Material;
					}
					if (lastIfcItem->itemColor->transparency == -1 || lastIfcItem->itemColor->transparency == 1)
					{
						material->setAmbient(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->surface.R, lastIfcItem->itemColor->surface.G, lastIfcItem->itemColor->surface.B, lastIfcItem->itemColor->surface.A));
						material->setDiffuse(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->diffuse.R, lastIfcItem->itemColor->diffuse.G, lastIfcItem->itemColor->diffuse.B, lastIfcItem->itemColor->diffuse.A));
						material->setSpecular(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->specular.R, lastIfcItem->itemColor->specular.G, lastIfcItem->itemColor->specular.B, lastIfcItem->itemColor->specular.A));
						state->setAttributeAndModes(material, osg::StateAttribute::ON);
					}
					else if (lastIfcItem->itemColor->transparency >= 0 && lastIfcItem->itemColor->transparency < 1)
					{
						material->setAmbient(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->surface.R, lastIfcItem->itemColor->surface.G, lastIfcItem->itemColor->surface.B, lastIfcItem->itemColor->transparency));
						material->setDiffuse(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->diffuse.R, lastIfcItem->itemColor->diffuse.G, lastIfcItem->itemColor->diffuse.B, lastIfcItem->itemColor->transparency));
						material->setSpecular(osg::Material::FRONT_AND_BACK,
							osg::Vec4(lastIfcItem->itemColor->specular.R, lastIfcItem->itemColor->specular.G, lastIfcItem->itemColor->specular.B, lastIfcItem->itemColor->transparency));
						state->setAttributeAndModes(material, osg::StateAttribute::ON);
						state->setMode(GL_BLEND, osg::StateAttribute::ON);
						state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
						state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
					}
				}
				else
				{
					osg::StateSet* state = lastSelect->getOrCreateStateSet();
					osg::Material* material = dynamic_cast<osg::Material*>(state->getAttribute(osg::StateAttribute::MATERIAL));
					if(material)
						state->setAttributeAndModes(material, osg::StateAttribute::OFF);

					/*STRUCT__IFC__ITEM *ifcItem = lastIfcItem->child;       
					osg::ref_ptr<osg::Group> group = new osg::Group;
					group = lastSelect->getParent(0)->asGroup();

					for (int i = 0; i < group->getNumDrawables(); i++)
					{
						osg::StateSet* state = group->getDrawable(i)->getOrCreateStateSet();
						osg::Material* material = dynamic_cast<osg::Material*>(state->getAttribute(osg::StateAttribute::MATERIAL));
						if (!material)
						{
							material = new osg::Material;
						}
						if (ifcItem->itemColor->transparency == -1 || ifcItem->itemColor->transparency == 1)
						{
							material->setAmbient(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->surface.R, ifcItem->itemColor->surface.G, ifcItem->itemColor->surface.B, ifcItem->itemColor->surface.A));
							material->setDiffuse(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->diffuse.R, ifcItem->itemColor->diffuse.G, ifcItem->itemColor->diffuse.B, ifcItem->itemColor->diffuse.A));
							material->setSpecular(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->specular.R, ifcItem->itemColor->specular.G, ifcItem->itemColor->specular.B, ifcItem->itemColor->specular.A));
							state->setAttributeAndModes(material, osg::StateAttribute::ON);
						}
						else if (ifcItem->itemColor->transparency >= 0 && ifcItem->itemColor->transparency < 1)
						{
							material->setAmbient(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->surface.R, ifcItem->itemColor->surface.G, ifcItem->itemColor->surface.B, ifcItem->itemColor->transparency));
							material->setDiffuse(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->diffuse.R, ifcItem->itemColor->diffuse.G, ifcItem->itemColor->diffuse.B, ifcItem->itemColor->transparency));
							material->setSpecular(osg::Material::FRONT_AND_BACK,
								osg::Vec4(ifcItem->itemColor->specular.R, ifcItem->itemColor->specular.G, ifcItem->itemColor->specular.B, ifcItem->itemColor->transparency));
							state->setAttributeAndModes(material, osg::StateAttribute::ON);
							state->setMode(GL_BLEND, osg::StateAttribute::ON);
							state->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
							state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
						}
						ifcItem = ifcItem->next;
					}*/
				}
				lastSelect = 0;
				lastIfcItem = NULL;
			}
			//PickAndSetHighLight(ea.getX(), ea.getY());
			return true;
		}
		return false;
	}
protected:
	char* Wchar2char(wchar_t *wstr)
	{
		//一个中文字符的长度为2个字节
		int len = 2 * wcslen(wstr) + 1;
		//声明cstr的长度
		char *cstr = (char*)malloc(sizeof(char)*len);
		//初始化化cstr为空
		memset(cstr, 0, len);
		int nlength = wcslen(wstr);
		//获取转换后的长度
		int nbytes = WideCharToMultiByte(0, 0, wstr, nlength, NULL, 0, NULL, NULL);
		if (nbytes > len)
			nbytes = len;
		//转换Unicode字符为ascii字符
		WideCharToMultiByte(0, 0, wstr, nlength, cstr, nbytes, NULL, NULL);

		return cstr;
	}
	//输出ifcItem的属性数据
	void PrintIfcPropterties(STRUCT__IFC__ITEM *ifcItem)
	{
		if (ifcItem == NULL)
			return;

		STRUCT__PROPERTY__SET *propertySets = ifcItem->propertySets;
		while (propertySets)
		{
			cout << Wchar2char(propertySets->name) << endl;
			STRUCT__PROPERTY *properties = propertySets->properties;
			while (properties)
			{
				cout << Wchar2char(properties->name) << "=";
				if (properties->description)
					cout << Wchar2char(properties->description) << ", ";
				else if (properties->nominalValue)
					cout << Wchar2char(properties->nominalValue) << ", ";
				else if (properties->lengthValue)
					cout << Wchar2char(properties->lengthValue) << ", ";
				else if (properties->areaValue)
					cout << Wchar2char(properties->areaValue) << ", ";
				else if (properties->volumeValue)
					cout << Wchar2char(properties->volumeValue) << ", ";
				else if (properties->countValue)
					cout << Wchar2char(properties->countValue) << ", ";
				else if (properties->weigthValue)
					cout << Wchar2char(properties->weigthValue) << ", ";
				else if (properties->timeValue)
					cout << Wchar2char(properties->timeValue) << ", ";
				cout << endl;
				properties = properties->next;
			}
			propertySets = propertySets->next;
			cout << endl;
		}
	}

	void OpenDoor(float x, float y)
	{
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (mViewer->computeIntersections(x, y, intersections))
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin(); hitr != intersections.end(); ++hitr)
			{
				if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
				{
					const osg::NodePath& np = hitr->nodePath;
					for (int i = np.size() - 1; i >= 0; --i)
					{
						osg::Node* nd = dynamic_cast<osg::Node*>(np[i]);
						STRUCT__IFC__ITEM *ifcItem = NULL;

						ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());
						if (Equals(ifcItem->ifcType, L"IfcDoor"))
							nd->setNodeMask(0);

						//if (nd->getName() == "0")
						//{
						//	//ifcItem = GetIfcItem(nd->getParent(0)->getName().c_str());
						//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getParent(0)->getName().c_str());
						//	if (Equals(ifcItem->ifcType, L"IfcDoor"))
						//		nd->getParent(0)->setNodeMask(0);
						//}
						//else
						//{
						//	//ifcItem = GetIfcItem(nd->getName().c_str());
						//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());
						//	if (Equals(ifcItem->ifcType, L"IfcDoor"))
						//		nd->setNodeMask(0);
						//}
						
						return;
					}
				}
			}
		}
	}

	//生成选中物体的包围盒
	void calBoundingBox(osg::Node* node, float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
	{
		osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
		osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_LINES, 0);
		//包围盒顶点数据
		vertices->push_back(osg::Vec3(xMin, yMin, zMin));
		vertices->push_back(osg::Vec3(xMax, yMin, zMin));
		vertices->push_back(osg::Vec3(xMax, yMin, zMax));
		vertices->push_back(osg::Vec3(xMin, yMin, zMax));
		vertices->push_back(osg::Vec3(xMin, yMax, zMin));
		vertices->push_back(osg::Vec3(xMax, yMax, zMin));
		vertices->push_back(osg::Vec3(xMax, yMax, zMax));
		vertices->push_back(osg::Vec3(xMin, yMax, zMax));
		//包围盒顶点索引
		indices->push_back(0); indices->push_back(1);
		indices->push_back(0); indices->push_back(3);
		indices->push_back(0); indices->push_back(4);
		indices->push_back(1); indices->push_back(2);
		indices->push_back(1); indices->push_back(5);
		indices->push_back(2); indices->push_back(3);
		indices->push_back(2); indices->push_back(6);
		indices->push_back(3); indices->push_back(7);
		indices->push_back(4); indices->push_back(7);
		indices->push_back(4); indices->push_back(5);
		indices->push_back(5); indices->push_back(6);
		indices->push_back(6); indices->push_back(7);

		geom->setVertexArray(vertices);
		geom->addPrimitiveSet(indices);

		osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();
		colors->push_back(osg::Vec4(0.0, 0.0, 0.0, 1.0));

		geom->setColorArray(colors.get());
		geom->setColorBinding(osg::Geometry::BIND_OVERALL);

		geom->setName("BoundingBox");
		osg::ref_ptr<osg::StateSet> state = geom->getOrCreateStateSet();
		osg::ref_ptr<osg::LineWidth> lw = new osg::LineWidth(3.0f);
		osg::ref_ptr<osg::LineStipple> ls = new osg::LineStipple(1, 0xff00);
		state->setAttribute(lw.get());
		state->setAttributeAndModes(ls.get(), osg::StateAttribute::ON);

		node->asGeode()->addDrawable(geom.get());
	}

	void PickAndShowBoundingBox(float x, float y)
	{
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (mViewer->computeIntersections(x, y, intersections))
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin(); hitr != intersections.end(); ++hitr)
			{
				if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
				{
					const osg::NodePath& np = hitr->nodePath;
					for (int i = np.size() - 1; i >= 0; --i)
					{
						osg::Node* nd = dynamic_cast<osg::Node*>(np[i]);

						/*float lengthX = nd->asGeode()->getBoundingBox().xMax() - nd->asGeode()->getBoundingBox().xMin();
						float lengthY = nd->asGeode()->getBoundingBox().yMax() - nd->asGeode()->getBoundingBox().yMin();
						float lengthZ = nd->asGeode()->getBoundingBox().zMax() - nd->asGeode()->getBoundingBox().zMin();

						osg::Vec3 center = nd->asGeode()->getBoundingBox().center();
						osg::ref_ptr<osg::ShapeDrawable> box = new osg::ShapeDrawable(new osg::Box(center, lengthX, lengthY, lengthZ));
						osg::ref_ptr<osg::Vec3Array> colors = new osg::Vec3Array;
						box->setColor(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
						osg::ref_ptr<osg::StateSet> state = box->getOrCreateStateSet();
						osg::ref_ptr<osg::PolygonMode> pm = new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE);
						state->setAttributeAndModes(pm.get(), osg::StateAttribute::ON);
						osg::ref_ptr<osg::LineWidth> lw = new osg::LineWidth(3.0f);
						osg::ref_ptr<osg::LineStipple> ls = new osg::LineStipple(1, 0xff00);
						state->setAttribute(lw.get());
						state->setAttributeAndModes(ls.get(), osg::StateAttribute::ON);
						box->setName("BoundingBox");
						nd->asGeode()->addDrawable(box.get());
						cout << lengthX << "," << lengthY << "," << lengthZ << endl;*/

						/*osg::MatrixList worldMatrices = nd->getWorldMatrices();
						cout << worldMatrices.size() << endl;
						for (osg::MatrixList::iterator itr = worldMatrices.begin(); itr != worldMatrices.end(); ++itr)
						{
						osg::Matrix& matrix = *itr;
						osg::ref_ptr<osg::MatrixTransform> boxMt = new osg::MatrixTransform;
						boxMt->setMatrix(matrix);
						boxMt->addChild(box.get());
						nd->asGeode()->addDrawable(boxMt->asDrawable());
						}*/

						calBoundingBox(nd,
							nd->asGeode()->getBoundingBox().xMin(), nd->asGeode()->getBoundingBox().xMax(),
							nd->asGeode()->getBoundingBox().yMin(), nd->asGeode()->getBoundingBox().yMax(),
							nd->asGeode()->getBoundingBox().zMin(), nd->asGeode()->getBoundingBox().zMax());

						lastPickNode = nd;

						return;
					}
				}
			}
		}
	}

	void Pick(float x, float y)
	{
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (mViewer->computeIntersections(x, y, intersections))
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin(); hitr != intersections.end(); ++hitr)
			{
				if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
				{
					const osg::NodePath& np = hitr->nodePath;
					for (int i = np.size() - 1; i >= 0; --i)
					{
						osg::Node* nd = dynamic_cast<osg::Node*>(np[i]);
						STRUCT__IFC__ITEM *ifcItem = NULL;
						//if (nd->getName() == "0")
						//{
						//	//osg::Matrixd *matrixd = getWordCoords(nd->getParent(0));
						//	//ifcItem = GetIfcItem(baseIfcItem, atoi(nd->getParent(0)->getName().c_str()));
						//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getParent(0)->getName().c_str());
						//	if (ifcItem == NULL)
						//		continue;
						//	if (ifcItem->parent->propertySetsAvailableButNotLoadedYet)
						//	{
						//		CreateIfcInstanceProperties(ifcModel, ifcItem->parent, ifcItem->parent->ifcID, ifcItem->parent->units);
						//		ifcItem->parent->propertySetsAvailableButNotLoadedYet = false;
						//	}
						//	PrintIfcPropterties(ifcItem->parent);
						//}
						//else
						//{
						//	//osg::Matrixd *matrixd = getWordCoords(nd);
						//	//ifcItem = GetIfcItem(baseIfcItem, atoi(nd->getName().c_str()));
						//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());
						//	if (ifcItem == NULL)
						//		continue;
						//	if (ifcItem->propertySetsAvailableButNotLoadedYet)
						//	{
						//		CreateIfcInstanceProperties(ifcModel, ifcItem, ifcItem->ifcID, ifcItem->units);
						//		ifcItem->propertySetsAvailableButNotLoadedYet = false;
						//	}
						//	PrintIfcPropterties(ifcItem);
						//}
						//cout << Wchar2char(ifcItem->ifcType) << endl;

						ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());
						if (ifcItem == NULL)
							continue;
						if (HasChildrenIfcInstanceProperties(ifcModel, ifcItem, ifcItem->ifcID, ifcItem->units))
						{
							if (!ifcItem->propertySetsAvailableHasLoadedYet)
							{
								CreateIfcInstanceProperties(ifcModel, ifcItem, ifcItem->ifcID, ifcItem->units);
								ifcItem->propertySetsAvailableHasLoadedYet = true;
							}
							PrintIfcPropterties(ifcItem);
						}

						return;
					}
				}
			}
		}
	}

	void PickAndSetHighLight(float x, float y)
	{
		osgUtil::LineSegmentIntersector::Intersections intersections;
		if (mViewer->computeIntersections(x, y, intersections))
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin(); hitr != intersections.end(); hitr++)
			{
				if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
				{
					const osg::NodePath& np = hitr->nodePath;
					for (int i = np.size() - 1; i >= 0; i--)
					{
						osg::Node* nd = dynamic_cast<osg::Node*>(np[i]);
						if (nd)
						{
							STRUCT__IFC__ITEM *ifcItem = NULL;
							//if (nd->getName() == "0")
							//{
							//	//ifcItem = GetIfcItem(nd->getParent(0)->getName().c_str());
							//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getParent(0)->getName().c_str());
							//}
							//else
							//{
							//	//ifcItem = GetIfcItem(nd->getName().c_str());
							//	ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());
							//}
							ifcItem = GetIveIfcItem(baseIfcItem, ifcItem, nd->getName().c_str());

							if (ifcItem == NULL)
								continue;

							osg::StateSet* state = nd->getOrCreateStateSet();
							osg::Material* mtrl = dynamic_cast<osg::Material*>(state->getAttribute(osg::StateAttribute::MATERIAL));
							if (!mtrl)
							{
								mtrl = new osg::Material;
							}
							mtrl->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0.6, 0.0, 0.0, 0.8));
							mtrl->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0.6, 0.0, 0.0, 0.8));
							mtrl->setTransparency(osg::Material::FRONT_AND_BACK, 0.2);
							state->setAttributeAndModes(mtrl, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
							//state->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
							lastSelect = nd;
							lastIfcItem = ifcItem;
							return;
						}
					}
				}
			}
		}
		return;
	}

	int ifcModel;
	osgViewer::Viewer* mViewer;
	osg::Node* lastSelect;
	STRUCT__IFC__ITEM *lastIfcItem;
	osg::Node* lastPickNode;
};



