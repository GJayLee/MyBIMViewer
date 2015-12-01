#pragma once
#pragma execution_character_set("utf-8")

#include<osg\Camera>
#include<osg\MatrixTransform>
#include<osg\Geode>
#include<osg\GraphicsContext>
#include<osg\Texture2D>
#include<osg\ShapeDrawable>
#include<osgViewer\Viewer>

//导航图中的三角形图标
osg::ref_ptr<osg::MatrixTransform> nm = new osg::MatrixTransform;
bool hasInit = false;

class CameraUpdateCallBack : public osg::NodeCallback
{
public:
	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
	{
		osg::Camera* camera = dynamic_cast<osg::Camera*>(node);
		if (camera)
		{
			osg::Vec3 eye, center, up;
			double left, right, bottom, top, znear, zfar;
			if (camera->getName().compare("MasterCamera") == 0)
			{
				camera->getViewMatrixAsLookAt(eye, center, up);
				camera->getProjectionMatrixAsOrtho(left, right, bottom, top, znear, zfar);
				
				if (last.z() == -999999.0f)
					last = eye;

				if (last != eye && !hasInit)
				{
					last = eye;
					//初始化导航图中图标的位置，只初始化一次，不然后面无法更新位置
					nm->setMatrix(osg::Matrix::translate(osg::Vec3d(eye.x(), eye.y(), eye.z())));
					hasInit = true;
				}

				//cout << "eye: " << eye.x() << "," << eye.y() << "," << eye.z() << endl;
				//cout << "center: " << center.x() << "," << center.y() << "," << center.z() << endl;
				//cout << "up: " << up.x() << "," << up.y() << "," << up.z() << endl;
				//cout << left << " " << right << " " << bottom << " " << top << " " << znear << " " << zfar << endl;
			}
		}
		traverse(node, nv);
	}

protected:
	osg::Vec3 last = osg::Vec3(0.0f,0.0f,-999999.0f);
};

osg::Node* CreateNode(osg::Texture2D* t2d)
{
	osg::Geode* gnode = new osg::Geode;
	osg::StateSet* stateset = gnode->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	//stateset->setMode(GL_BLEND, osg::StateAttribute::ON);
	//stateset->setTextureAttributeAndModes(0, t2d, osg::StateAttribute::ON);
	stateset->setTextureAttributeAndModes(0, new osg::Texture2D(osgDB::readImageFile("Images/dog_right_eye.jpg")), osg::StateAttribute::ON);
	osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable(new osg::Box(osg::Vec3(860, 620, 0), 200, 200, 0.1));
	//osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable(new osg::Box(osg::Vec3(100, 100, 0), 200, 200, 0.1));
	sd->setColor(osg::Vec4(0.5, 0.5, 0.5, 1.0));
	gnode->addDrawable(sd.get());
	return gnode;
}
osg::Node* CreatePointer()
{
	osg::Geode* gnode = new osg::Geode();
	osg::StateSet* stateset = gnode->getOrCreateStateSet();
	stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	//stateset->setMode(GL_BLEND, osg::StateAttribute::ON);

	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array();
	vertices->push_back(osg::Vec3(1500.0f, -2000.0f, 0.0f));
	vertices->push_back(osg::Vec3(0.0f, 3000.0f, 0.0f));
	vertices->push_back(osg::Vec3(-1500.0f, -2000.0f, 0.0f));
	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array();
	normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
	osg::ref_ptr<osg::Geometry> triangles = new osg::Geometry();
	triangles->setVertexArray(vertices.get());
	triangles->setNormalArray(normals.get());
	triangles->setNormalBinding(osg::Geometry::BIND_OVERALL);
	triangles->setColorArray(colors.get());
	triangles->setColorBinding(osg::Geometry::BIND_OVERALL);
	triangles->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES, 0, 3));

	/*osg::TessellationHints* hints = new osg::TessellationHints;
	hints->setDetailRatio(1.0f);
	osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3(0, 0, 0), 300, 300), hints);
	osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3(0, 0, 0), 300, 300), hints);
	sd->setColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
	gnode->addDrawable(sd.get());*/

	gnode->addDrawable(triangles.get());

	return gnode;
}
osg::Camera* CreateHUD(osg::Texture2D* t2d)
{
	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setViewMatrix(osg::Matrix::identity());
	camera->setAllowEventFocus(false);
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setViewport(0, 0, 960, 720);
	camera->setProjectionMatrixAsOrtho2D(0, 960, 0, 720);
	camera->setClearMask(GL_DEPTH_BUFFER_BIT);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->addChild(CreateNode(t2d));
	return camera.release();
}
//osg::Group* CreateRTT(osg::Group* model)
//{
//	osg::ref_ptr<osg::Group> gp = new osg::Group();
//	osg::ref_ptr<osg::Group> floor = new osg::Group();
//
//	floor->addChild(model);
//	gp->addChild(floor.get());
//	osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//	camera->setName("upCamera");
//	camera->setProjectionMatrixAsOrtho(-100, 100, -100, 100, 400, 500);
//	camera->setViewMatrixAsLookAt(osg::Vec3(0, 0, 8000), osg::Vec3(0, 0, 7999), osg::Vec3(0, 1, 0));
//	camera->setRenderOrder(osg::Camera::PRE_RENDER);
//	camera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
//	camera->setAllowEventFocus(false);
//	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
//	camera->addChild(floor);
//	nm->addChild(CreatePointer());
//	camera->addChild(nm.get());
//
//	osg::Texture2D *t2d = new osg::Texture2D;
//	t2d->setInternalFormat(GL_RGBA);
//	camera->attach(osg::Camera::COLOR_BUFFER, t2d);
//	gp->addChild(camera);
//	gp->addChild(CreateHUD(t2d));
//	//gp->addChild(model);
//
//	return gp.get();
//}