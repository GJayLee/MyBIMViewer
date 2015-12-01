#pragma execution_character_set("utf-8")

#include<iostream>

#include"MyNavigator.h"

using namespace std;

MyNavigator::MyNavigator(osg::Camera* cam1, osg::Camera* cam2, osg::MatrixTransform* mt)
{
	//m_vPosition = osg::Vec3(158832, 95642, -3750);
	m_vPosition = osg::Vec3(-8000, -40000, 2000);
	m_vRotation = osg::Vec3(osg::PI_2, 0, osg::PI_2);
	m_vStep = 750.0;
	m_vRotateStep = 0.005;
	m_bLeftDown = false;
	m_bMidDown = false;
	m_node = 0;
	masterCamera = cam1;
	rttCamera = cam2;
	nm = mt;

	double left, right, bottom, top, zNear, zFar;
	rttCamera->getProjectionMatrixAsOrtho(left, right, bottom, top, zNear, zFar);
	scale = right / 15;
	m_vTrans = right / 500;
}

osg::Matrixd MyNavigator::getMatrix()const
{
	osg::Matrixd mat;
	mat.makeTranslate(m_vPosition);
	return osg::Matrixd::rotate(m_vRotation[0], osg::X_AXIS, m_vRotation[1], osg::Y_AXIS, m_vRotation[2], osg::Z_AXIS)*mat;
}

osg::Matrixd MyNavigator::getInverseMatrix()const
{
	osg::Matrixd mat;
	mat.makeTranslate(m_vPosition);
	return osg::Matrixd::inverse(osg::Matrixd::rotate(m_vRotation[0], osg::X_AXIS, m_vRotation[1], osg::Y_AXIS, m_vRotation[2], osg::Z_AXIS)*mat);
}

bool MyNavigator::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us)
{
	osgViewer::Viewer* view = dynamic_cast<osgViewer::Viewer*>(&us);
	switch (ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		if (ea.getKey() == 'w' || ea.getKey() == 'W')
			changePosition(osg::Vec3(m_vStep*cosf(osg::PI_2 + m_vRotation._v[2]), m_vStep*sinf(osg::PI_2 + m_vRotation._v[2]), 0), false);
		else if (ea.getKey() == 's' || ea.getKey() == 'S')
			changePosition(osg::Vec3(-m_vStep*cosf(osg::PI_2 + m_vRotation._v[2]), -m_vStep*sinf(osg::PI_2 + m_vRotation._v[2]), 0), false);
		else if (ea.getKey() == 'a' || ea.getKey() == 'A')
			changePosition(osg::Vec3(-m_vStep*sinf(osg::PI_2 + m_vRotation._v[2]), m_vStep*cosf(osg::PI_2 + m_vRotation._v[2]), 0), false);
		else if (ea.getKey() == 'd' || ea.getKey() == 'D')
			changePosition(osg::Vec3(m_vStep*sinf(osg::PI_2 + m_vRotation._v[2]), -m_vStep*cosf(osg::PI_2 + m_vRotation._v[2]), 0), false);
		else if (ea.getKey() == '+')
			setStep(1);
		else if (ea.getKey() == '-')
			setStep(-1);
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Home)
			changePosition(osg::Vec3(0, 0, 50.0), true);
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_End)
			changePosition(osg::Vec3(0, 0, -50.0), true);
		break;
	case osgGA::GUIEventAdapter::PUSH:
		if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			m_iLeftX = ea.getX();
			m_iLeftY = ea.getY();
			m_bLeftDown = true;
		}
		if (ea.getButton() == osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON)
		{
			m_iMidX = ea.getX();
			m_iMidY = ea.getY();
			m_bMidDown = true;
			//cout << "middle down!" << endl;
		}
		return true;
	case osgGA::GUIEventAdapter::RELEASE:
		if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			m_bLeftDown = false;
		}
		if (ea.getButton() == osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON)
		{
			m_bMidDown = false;
			//cout << "middle up!" << endl;
		}
		return true;
	case osgGA::GUIEventAdapter::DRAG:
		if (m_bLeftDown)
		{
			int delX = ea.getX() - m_iLeftX;
			int delY = ea.getY() - m_iLeftY;
			m_vRotation[2] -= osg::DegreesToRadians(m_vRotateStep*delX);
			
			m_vRotation[0] += osg::DegreesToRadians(m_vRotateStep*delY);
			if (m_vRotation[0] <= 0)
				m_vRotation[0] = 0;
			if (m_vRotation[0] >= osg::PI)
				m_vRotation[0] = osg::PI;
			//旋转导航图中的三角形图标
			osg::Vec3 eye, center, up;
			masterCamera->getViewMatrixAsLookAt(eye, center, up);
			nm->setMatrix(osg::Matrix::rotate(m_vRotation[2], osg::Vec3(0, 0, 1))*osg::Matrix::translate(osg::Vec3d(eye.x(), eye.y(), eye.z())));
		}
		if (m_bMidDown)
		{
			osg::Vec3 eye, center, up;
			int delX = ea.getX() - m_iMidX;
			int delY = ea.getY() - m_iMidY;
			osg::Vec3 del(-delX*m_vTrans, -delY*m_vTrans, 0);
			rttCamera->getViewMatrixAsLookAt(eye, center, up);
			rttCamera->setViewMatrixAsLookAt(eye + del, center + del, up);
			m_iMidX = ea.getX();
			m_iMidY = ea.getY();
		}
		return true;
	case osgGA::GUIEventAdapter::SCROLL:
		switch (ea.getScrollingMotion())
		{
			double left, right, bottom, top, zNear, zFar;
		case osgGA::GUIEventAdapter::ScrollingMotion::SCROLL_UP:
			rttCamera->getProjectionMatrixAsOrtho(left, right, bottom, top, zNear, zFar);
			if (right - scale >= 0)
				rttCamera->setProjectionMatrixAsOrtho(left + scale, right - scale, bottom + scale, top - scale, zNear, zFar);
			//cout << "up" << endl;
			return true;
		case osgGA::GUIEventAdapter::ScrollingMotion::SCROLL_DOWN:
			rttCamera->getProjectionMatrixAsOrtho(left, right, bottom, top, zNear, zFar);
			rttCamera->setProjectionMatrixAsOrtho(left - scale, right + scale, bottom - scale, top + scale, zNear, zFar);
			//cout << "down" << endl;
			return true;
		}
		return true;
	default:
		break;
	}
	return false;
}

bool MyNavigator::changePosition(osg::Vec3 delta, bool isUpOrDown)
{
	osg::Vec3 rttEye, rttCenter, rttUp;
	osg::Vec3 masterEye, masterCenter, masterUp;
	double left, right, bottom, top, zNear, zFar;
	if (m_node)
	{
		osg::Vec3 newPos = m_vPosition + delta;
		osgUtil::IntersectVisitor iv;

		osg::ref_ptr<osg::LineSegment> line = new osg::LineSegment(newPos, m_vPosition);
		iv.addLineSegment(line.get());
		m_node->accept(iv);
		if (!iv.hits())
		{
			m_vPosition += delta;
			//平移导航图
			rttCamera->getViewMatrixAsLookAt(rttEye, rttCenter, rttUp);
			rttCamera->setViewMatrixAsLookAt(rttEye + delta, rttCenter + delta, rttUp);
			//cout << m_vPosition._v[0] << "," << m_vPosition._v[1] << "," << m_vPosition._v[2] << endl;
			if (isUpOrDown)
			{
				//缩放导航图
				rttCamera->getProjectionMatrixAsOrtho(left, right, bottom, top, zNear, zFar);
				rttCamera->setProjectionMatrixAsOrtho(left, right, bottom, top, zNear, zFar + delta.z());
				//cout << zFar + delta.z() << endl;
			}
			//移动和旋转导航图中的三角形图标
			masterCamera->getViewMatrixAsLookAt(masterEye, masterCenter, masterUp);
			nm->setMatrix(osg::Matrix::rotate(m_vRotation[2], osg::Vec3(0, 0, 1))*osg::Matrix::translate(osg::Vec3d(masterEye.x(), masterEye.y(), masterEye.z())));
			
		}
		else
			return false;
	}
	else
		m_vPosition += delta;

	return true;
}

void MyNavigator::setStep(int delta_step)
{
	m_vStep += delta_step;
	if (m_vStep <= 0)
		m_vStep = 0;
}

void MyNavigator::setMnode(osg::Node* temp)
{
	m_node = temp;
}