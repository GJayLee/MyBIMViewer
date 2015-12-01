#pragma once

#include<osgGA\CameraManipulator>
#include<osgViewer\Viewer>
#include<osgUtil\IntersectVisitor>
#include<osg\LineSegment>
#include<osg\MatrixTransform>

class MyNavigator : public osgGA::CameraManipulator
{
public:
	MyNavigator(osg::Camera* cam1, osg::Camera* cam2, osg::MatrixTransform* mt);
	virtual void setByMatrix(const osg::Matrixd& matrix) {};
	virtual osg::Matrixd getMatrix()const;
	virtual void setByInverseMatrix(const osg::Matrixd& matrix) {};
	virtual osg::Matrixd getInverseMatrix()const;
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);
	bool changePosition(osg::Vec3 delta, bool isUpOrDown);
	void setStep(int delta_step);
	void setMnode(osg::Node* node);

private:
	osg::Vec3 m_vPosition;             //初始化摄像机的位置
	osg::Vec3 m_vRotation;             //初始化摄像机的角度
	int m_vStep;                       //摄像机移动的速度
	float m_vRotateStep;               //摄像机旋转的速度
	float m_iLeftX;                    //鼠标左键按下后鼠标的X坐标
	float m_iLeftY;                    //鼠标左键按下后鼠标的Y坐标
	bool m_bLeftDown;                  //鼠标左键是否按下
	bool m_bMidDown;                   //鼠标滚轮是否按下
	float m_iMidX;                     //鼠标滚轮按下后鼠标的X坐标
	float m_iMidY;                     //鼠标滚轮按下后鼠标的Y坐标
	int m_vTrans;                      //导航图平移的速度
	osg::Node* m_node;
	osg::Camera* masterCamera;         //主摄像机
	osg::Camera* rttCamera;            //导航图摄像机
	osg::MatrixTransform* nm;          //导航图中的三角新图标
	float scale;                       //导航图放大的倍数
};