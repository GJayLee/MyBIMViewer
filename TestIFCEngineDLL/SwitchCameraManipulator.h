#pragma once
#pragma execution_character_set("utf-8")

#include<osgViewer\Viewer>
#include<osgGA\GUIEventHandler>
#include<osgGA\TrackballManipulator>

//自定义漫游器
#include"MyNavigator.h"

//RTT导航图
#include"RTTNavigator.h"

class SwitchCameraManipulator : public osgGA::GUIEventHandler
{
public:
	//SwitchCameraManipulator(osg::Group* group, osg::Camera* cam, osgViewer::Viewer* viewer, osg::MatrixTransform* mt)
	SwitchCameraManipulator(osg::Group* group, osg::Camera* cam, osgViewer::Viewer* viewer, osg::Node* node)
	{
		changeToNavigator = true;
		rootNode = group;
		master = cam;
		mViewer = viewer;
		model = node;
	}
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		switch (ea.getEventType())
		{
		case osgGA::GUIEventAdapter::KEYDOWN:
			if (ea.getKey() == '1')
			{
				if (!changeToNavigator)
				{
					mViewer->setCameraManipulator(new osgGA::TrackballManipulator());
					//cout << "1" << endl;

					//删掉导航图
					rootNode->removeChild(hudCamera);
					rootNode->removeChild(rttCamera);
					changeToNavigator = true;
				}
			}
			else if (ea.getKey() == '2')
			{
				if (changeToNavigator)
				{
					//初始化导航图
					InitRTTCamera();
					//简单漫游器的实现
					osg::ref_ptr<MyNavigator> mNavigator = new MyNavigator(master, rttCamera, nm);
					mNavigator->setMnode(model);
					mViewer->setCameraManipulator(mNavigator);
					//cout << "2" << endl;
					changeToNavigator = false;
				}
			}
			break;
		}
		return false;
	}

	//初始化导航图
	void InitRTTCamera()
	{
		//RTT导航图
		rttCamera = new osg::Camera;
		rttCamera->setName("upCamera");
		//设置导航窗口的大小(目前是以这个例子为例，后面需根据不同的模型大小设置窗口大小)
		//camera->setComputeNearFarMode(osg::Camera::DO_NOT_COMPUTE_NEAR_FAR);
		osg::BoundingSphere boundSphere = model->getBound();
		rttCamera->setProjectionMatrixAsOrtho(-boundSphere.radius() / 2, boundSphere.radius() / 2, -boundSphere.radius() / 2, boundSphere.radius() / 2, 0, 600);
		//camera->setViewMatrixAsLookAt(osg::Vec3(0, 0, 1000), osg::Vec3(0, 0, 0), osg::Vec3(0, 1, 0));
		//camera->setProjectionMatrixAsOrtho(-400, 400, -400, 400, 0, 600);
		//rttCamera->setViewMatrixAsLookAt(osg::Vec3(boundSphere._center.x(), boundSphere._center.y(), -3750), osg::Vec3(boundSphere._center.x(), boundSphere._center.y(), -50000), osg::Vec3(0, 1, 0));
		rttCamera->setViewMatrixAsLookAt(osg::Vec3(boundSphere._center.x(), boundSphere._center.y(), 2000), osg::Vec3(boundSphere._center.x(), boundSphere._center.y(), -50000), osg::Vec3(0, 1, 0));
		rttCamera->setRenderOrder(osg::Camera::PRE_RENDER);
		//camera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		rttCamera->setAllowEventFocus(false);
		rttCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
		rttCamera->addChild(model);
		nm->addChild(CreatePointer());
		rttCamera->addChild(nm.get());
		//把全景渲染到RTT
		osg::Texture2D *t2d = new osg::Texture2D;
		t2d->setInternalFormat(GL_RGBA);
		rttCamera->attach(osg::Camera::COLOR_BUFFER, t2d);

		hudCamera = CreateHUD(t2d);
		hudCamera->setName("HUDCamera");

		rootNode->addChild(rttCamera);
		rootNode->addChild(hudCamera);
	}
protected:
	osgViewer::Viewer* mViewer;

	bool changeToNavigator;                   //判断是哪种模式

	MyNavigator *mNavigator;                  //漫游操作器
	osg::Camera *master;                      //场景主摄像机
	osg::Group* rootNode;                     //场景根节点
	//osg::MatrixTransform* modelMt;            //场景模型
	osg::Node* model;                         //场景模型
	//RTT导航图摄像机
	osg::Camera* rttCamera;                  
	osg::Camera* hudCamera;
};