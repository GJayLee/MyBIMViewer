#include<iostream>

//OSG
#include<osgViewer\CompositeViewer>
#include<osgViewer\Viewer>
#include<osgViewer\ViewerBase>
#include<osgViewer\ViewerEventHandlers>
#include<osg\Geometry>
#include<osg\Geode>
#include<osg\Switch>
#include<osg\Material>
#include<osg\StateSet>
#include<osg\Light>
#include<osg\LightSource>
#include<osg\PolygonMode>
#include<osg\Blendfunc>
#include<osg\Shader>
#include<osg\Program>
#include<osg\GraphicsContext>
#include<osg\ShapeDrawable>
#include<osg\CullFace>
#include<osgShadow\ShadowedScene>
#include<osgShadow\ShadowMap>
#include<osgShadow\ShadowTexture>
#include<osgShadow\SoftShadowMap>
#include<osgShadow\ViewDependentShadowMap>
#include<osgUtil\SmoothingVisitor>
#include<osgUtil\Optimizer>
#include<osgWidget\Util>
#include<osgWidget\WindowManager>
#include<osgDB\ReadFile>
#include<osgDB\WriteFile>
#include<osgFX\Scribe>

//点选物体
#include"PickIfcItem.h"
//切换摄像机
#include"SwitchCameraManipulator.h"
//IFCEngineDll
#include"IFCEngineInteract.h"

int ifcModel;
osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer();
//osg::ref_ptr<osg::Group> model = new osg::Group;
//osg::ref_ptr<osg::Group> wireModel = new osg::Group;
osg::ref_ptr<osg::Node> model = new osg::Node;
osg::ref_ptr<osg::Node> wireModel = new osg::Node;

//主摄像机
osg::ref_ptr<osg::Camera> master = new osg::Camera;
//阴影
osg::ref_ptr<osgShadow::ShadowedScene> shadowedScene = new osgShadow::ShadowedScene;
static int ReceivesShadowTraversalMask = 0x1;
static int CastsShadowTraversalMask = 0x2;

//根据节点名称判断是否有父亲节点
osg::Group* GetParentNode(const string& name)
{
	osg::ref_ptr<osg::Group> node = new osg::Group;
	osg::ref_ptr<osg::Group> group = new osg::Group;
	group = model->asGroup();
	for (int i = 0; i < group->getNumChildren(); i++)
	{
		if (group->getChild(i)->getName() == name)
		{
			node = group->getChild(i)->asGroup();
			return node.release();
		}
	}

	return NULL;
}

osg::Geode* GetGeodeNode(const string& name)
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::Group> group = new osg::Group;
	group = model->asGroup();
	for (int i = 0; i < group->getNumChildren(); i++)
	{
		if (group->getChild(i)->getName() == name)
		{
			geode = group->getChild(i)->asGeode();
			return geode.release();
		}
	}

	return NULL;
}

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

//解析IFC文件
bool ParseIfcFile()
{
	wchar_t *strFilePath = L"E:\\Lee\\OSG\\OsgProject\\TestIFCEngineDLL\\Debug\\";
	//wchar_t *strFilePath = L"E:\\";

	int i = wcslen(strFilePath);

	ifcSchemaName_IFC2X3 = new wchar_t[i + wcslen(L"IFC2X3_TC1.exp") + 1];
	memcpy(&ifcSchemaName_IFC2X3[0], strFilePath, (i + 1)*sizeof(wchar_t));
	memcpy(&ifcSchemaName_IFC2X3[i], L"IFC2X3_TC1.exp", (wcslen(L"IFC2X3_TC1.exp") + 1)*sizeof(wchar_t));

	ifcFileName = new wchar_t[512];
	memcpy(&ifcFileName[0], strFilePath, (i + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"项目1.ifc", (wcslen(L"项目1.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"项目2.ifc", (wcslen(L"项目2.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"项目3.ifc", (wcslen(L"项目3.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"项目4.ifc", (wcslen(L"项目4.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"项目6.ifc", (wcslen(L"项目6.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"5F.ifc", (wcslen(L"5F.ifc") + 1)*sizeof(wchar_t));
	//memcpy(&ifcFileName[i], L"2.ifc", (wcslen(L"2.ifc") + 1)*sizeof(wchar_t));
	memcpy(&ifcFileName[i], L"rac_basic_sample_project.ifc", (wcslen(L"rac_basic_sample_project.ifc") + 1)*sizeof(wchar_t));

	xmlSettings_IFC2x3 = new wchar_t[i + wcslen(L"IFC2X3-Settings.xml") + 1];
	memcpy(&xmlSettings_IFC2x3[0], strFilePath, (i + 1)*sizeof(wchar_t));
	memcpy(&xmlSettings_IFC2x3[i], L"IFC2X3-Settings.xml", (wcslen(L"IFC2X3-Settings.xml") + 1)*sizeof(wchar_t));

	setStringUnicode(true);
	ifcModel = sdaiOpenModelBNUnicode(0, (char *)ifcFileName, (char *)ifcSchemaName_IFC2X3);
	if (ifcModel)
	{
		FILE *file = 0;
		wchar_t* fileSchema = 0;
		GetSPFFHeaderItem(ifcModel, 9, 0, sdaiUNICODE, (char **)&fileSchema);
		if (fileSchema == 0 
			|| contains(fileSchema, L"IFC2x3")
			|| contains(fileSchema, L"IFC2X3") 
			|| contains(fileSchema, L"IFC2x2") 
			|| contains(fileSchema, L"IFC2X2") 
			|| contains(fileSchema, L"IFC2x_")
			|| contains(fileSchema, L"IFC2X_") 
			|| contains(fileSchema, L"IFC20")) 
			_wfopen_s(&file, xmlSettings_IFC2x3, L"r");

		__int64 owlModel = 0;
		owlGetModel(ifcModel, &owlModel);
		initializeColor(owlModel);

		if (file)
		{
			bool hide;
			wchar_t buff[512], buffName[512];
			while (0 != fgetws(buff, 500, file))
			{
				if (charContains(buff, L"<object "))
				{
					charFill(buff, L"name", buffName);
					hide = charFind(buff, L"hide");
					RetrieveObjects(ifcModel, buffName, hide);
				}
			}
			fclose(file);
		}

		completeItemColorItems();

		return	true;
	}
	else
	{
		//ASSERT(baseIfcItem == 0 && baseTreeItem == 0);
		return	false;
	}
}

//创建光源
osg::Node* createLightSource(unsigned int num, const osg::Vec3& trans, osg::Vec4& color)
{
	osg::ref_ptr<osg::Light> light = new osg::Light;
	light->setLightNum(num);
	//light->setAmbient(color);
	light->setDiffuse(color);
	//light->setSpecular(color);
	light->setPosition(osg::Vec4(0.0f, 0.0f, 0.0f, 0.0f));
	/*light->setConstantAttenuation(1.0f);
	light->setLinearAttenuation(4.0f/modelSize);
	light->setQuadraticAttenuation(4.0f/osg::square(modelSize));*/

	osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
	lightSource->setLight(light);
	osg::ref_ptr<osg::MatrixTransform> sourceTrans = new osg::MatrixTransform;
	sourceTrans->setMatrix(osg::Matrix::translate(trans));
	sourceTrans->addChild(lightSource.get());
	return sourceTrans.release();
}

//初始化OSG窗口
void InitMainWindow()
{
	osg::ref_ptr<osg::Light> topLight = new osg::Light;
	topLight->setLightNum(0);
	topLight->setAmbient(osg::Vec4(0.7, 0.7, 0.7, 1.0));
	topLight->setDiffuse(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	//topLight->setSpecular(osg::Vec4(0.75, 0.75, 0.75, 1.0));
	//topLight->setSpecular(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	topLight->setPosition(osg::Vec4(1.0, 0.0, 1.0, 0.0f));
	osg::ref_ptr<osg::LightSource> ls = new osg::LightSource;
	ls->setLight(topLight);
	//->getOrCreateStateSet()->setAttributeAndModes(topLight.get(), osg::StateAttribute::ON);
	shadowedScene->addChild(ls.get());

	/*osg::ref_ptr<osg::Light> ambient = new osg::Light;
	ambient->setAmbient(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	osg::ref_ptr<osg::LightSource> ls1 = new osg::LightSource;
	ls1->setLight(ambient);*/
	//shadowedScene->addChild(ls1.get());

	//设置抗锯齿
	osg::ref_ptr<osg::DisplaySettings> ds = osg::DisplaySettings::instance();
	ds->setNumMultiSamples(10);

	//设置窗口参数
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->x = 40;
	traits->y = 40;
	traits->width = 960;
	traits->height = 720;
	traits->windowDecoration = true;
	traits->doubleBuffer = true;
	traits->sharedContext = 0;
	traits->samples = ds->getNumMultiSamples();

	osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	//设置摄像机参数
	/*osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setGraphicsContext(gc.get());
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
	GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;
	camera->setDrawBuffer(buffer);
	camera->setReadBuffer(buffer);
	viewer.addSlave(camera.get());*/

	master->setGraphicsContext(gc);
	//master->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	master->setClearColor(osg::Vec4(1.0f, 1.0f, 1.0f, 0.0f));
	master->setViewport(0, 0, traits->width, traits->height);
	viewer->addSlave(master);
	master->setName("MasterCamera");
	osg::ref_ptr<CameraUpdateCallBack> cuc = new CameraUpdateCallBack();
	master->setUpdateCallback(cuc.get());
}

int main()
{
	osg::ref_ptr<osg::Group> rootNode = new osg::Group;    //根节点
	osg::ref_ptr<osg::Group> myScene = new osg::Group;     //场景节点（包括一些缩放节点和模型节点）
	//初始化阴影的参数
	osgShadow::ShadowSettings* settings = shadowedScene->getShadowSettings();
	settings->setReceivesShadowTraversalMask(ReceivesShadowTraversalMask);
	settings->setCastsShadowTraversalMask(CastsShadowTraversalMask);
	
	//四种类型的阴影
	/*osg::ref_ptr<osgShadow::ShadowMap> sm = new osgShadow::ShadowMap;
	shadowedScene->setShadowTechnique(sm.get());*/

	/*osg::ref_ptr<osgShadow::ViewDependentShadowMap> vdsm = new osgShadow::ViewDependentShadowMap;
	shadowedScene->setShadowTechnique(vdsm.get());*/

	//osg::ref_ptr<osgShadow::SoftShadowMap> ssm = new osgShadow::SoftShadowMap;
	////ssm->setBias(0.005);
	//shadowedScene->setShadowTechnique(ssm.get());

	/*osg::ref_ptr<osgShadow::ShadowTexture> st = new osgShadow::ShadowTexture;
	shadowedScene->setShadowTechnique(st.get());*/

	//解析IFC文件
	ParseIfcFile();
	//读取IFC文件中的几何数据
	//GetGeometryData(baseIfcItem);
	
	model = osgDB::readNodeFile("myModel_.ive");
	wireModel = osgDB::readNodeFile("myWireModel_.ive");

	//使用shader
	//添加光源
	osg::ref_ptr<osg::Light> topLight = new osg::Light;
	topLight->setLightNum(0);
	topLight->setAmbient(osg::Vec4(0.3, 0.3, 0.3, 1.0));
	topLight->setDiffuse(osg::Vec4(0.8, 0.8, 0.8, 1.0));
	topLight->setPosition(osg::Vec4(1.0, 1.0, 1.0, 0.0f));
	osg::ref_ptr<osg::LightSource> ls = new osg::LightSource;
	ls->setLight(topLight);
	//myScene->getOrCreateStateSet()->setMode(GL_LIGHT1, osg::StateAttribute::ON);
	myScene->addChild(ls.get());
	//逐顶点光照
	static const char* vertSource = {
		"void main()\n"
		"{\n"
		"    vec3 normal;\n"
		"    vec3 lightDir;\n"
		"    vec4 diffuse, ambient, globalAmbient, specular;\n"
		"    float NdotL;\n"
		"    normal = normalize(gl_NormalMatrix * gl_Normal);\n"
		"    lightDir = normalize(vec3(gl_LightSource[0].position));\n"
		"    NdotL = max(dot(normal, lightDir),0.0);\n"
		"    diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;\n"
		"    ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;\n"
		"    globalAmbient = gl_FrontMaterial.ambient * gl_LightModel.ambient;\n"
		"    gl_FrontColor = NdotL * diffuse + globalAmbient + ambient;\n"
		"    gl_Position = ftransform();\n"
		"}\n"
	};
	static const char* fragSource = {
		"void main()\n"
		"{\n"
		"    gl_FragColor = gl_Color;\n"
		"}\n"
	};

	/*static const char vertSource[] =
	{
		"varying vec4 color;                                                    \n"
		"const vec3 lightPos      =vec3(0.0, 0.0, 10.0);                        \n"
		"const vec4 cessnaColor   =vec4(0.8, 0.8, 0.8, 1.0);                    \n"
		"const vec4 lightAmbient  =vec4(0.1, 0.1, 0.1, 1.0);                    \n"
		"const vec4 lightDiffuse  =vec4(0.4, 0.4, 0.4, 1.0);                    \n"
		"const vec4 lightSpecular =vec4(0.8, 0.8, 0.8, 1.0);                    \n"
		"void DirectionalLight(in vec3 normal,                                  \n"
		"                      in vec3 ecPos,                                   \n"
		"                      inout vec4 ambient,                              \n"
		"                      inout vec4 diffuse,                              \n"
		"                      inout vec4 specular)                             \n"
		"{                                                                      \n"
		"     float nDotVP;                                                     \n"
		"     vec3 L = normalize(gl_ModelViewMatrix*vec4(lightPos, 0.0)).xyz;   \n"
		"     nDotVP = max(0.0, dot(normal, L));                                \n"
		"                                                                       \n"
		"     if (nDotVP > 0.0) {                                               \n"
		"       vec3 E = normalize(-ecPos);                                     \n"
		"       vec3 R = normalize(reflect( L, normal ));                       \n"
		"       specular = pow(max(dot(R, E), 0.0), 16.0) * lightSpecular;      \n"
		"     }                                                                 \n"
		"     ambient  = lightAmbient;                                          \n"
		"     diffuse  = lightDiffuse * nDotVP;                                 \n"
		"}                                                                      \n"
		"void main() {                                                          \n"
		"    vec4 ambiCol = vec4(0.0);                                          \n"
		"    vec4 diffCol = vec4(0.0);                                          \n"
		"    vec4 specCol = vec4(0.0);                                          \n"
		"    gl_Position   = gl_ModelViewProjectionMatrix * gl_Vertex;          \n"
		"    vec3 normal   = normalize(gl_NormalMatrix * gl_Normal);            \n"
		"    vec4 ecPos    = gl_ModelViewMatrix * gl_Vertex;                    \n"
		"    DirectionalLight(normal, ecPos.xyz, ambiCol, diffCol, specCol);    \n"
		"    color = cessnaColor * (ambiCol + diffCol + specCol);               \n"
		"}\n"
	};

	static const char fragSource[] =
	{
		"varying vec4 color;               \n"
		"void main() {                             \n"
		"  gl_FragColor = color;                   \n"
		"}\n"
	};*/
		

	//逐像素光照
	/*static const char* vertSource = {
	"varying vec4 diffuse, ambient;\n"
	"varying vec3 normal,lightDir,halfVector;\n"
	"void main()\n"
	"{\n"
	"    normal = normalize(gl_NormalMatrix * gl_Normal);\n"
	"    lightDir = normalize(vec3(gl_LightSource[0].position));\n"
	"    halfVector = normalize(gl_LightSource[0].halfVector.xyz);\n"
	"    diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;\n"
	"    ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;\n"
	"    ambient += gl_FrontMaterial.ambient * gl_LightModel.ambient;\n"
	"    gl_Position = ftransform();\n"
	"}\n"
	};
	static const char* fragSource = {
	"varying vec4 diffuse, ambient;"
	"varying vec3 normal,lightDir,halfVector;"
	"void main()\n"
	"{\n"
	"    vec3 n, halfV;\n"
	"    float NdotL, NdotHV;\n"
	"    vec4 color = ambient;\n"
	"    n = normalize(normal);\n"
	"    NdotL = max(dot(n, lightDir), 0.0);\n"
	"    if(NdotL > 0.0)\n"
	"    {\n"
	"        color += diffuse * NdotL;\n"
	"        halfV = normalize(halfVector);\n"
	"        NdotHV = max(dot(n, halfV), 0.0);\n"
	"        color += gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(NdotHV, gl_FrontMaterial.shininess);\n"
	"    }\n"
	"    gl_FragColor = color;\n"
	"}\n"
	};*/

	osg::ref_ptr<osg::Shader> vertShader = new osg::Shader(osg::Shader::VERTEX, vertSource);
	osg::ref_ptr<osg::Shader> fragShader = new osg::Shader(osg::Shader::FRAGMENT, fragSource);
	osg::ref_ptr<osg::Program> program = new osg::Program;
	program->addShader(vertShader.get());
	program->addShader(fragShader.get());
	osg::StateSet* stateSet = model->getOrCreateStateSet();
	stateSet->setAttributeAndModes(program.get());

	//初始化OSG窗口参数
	InitMainWindow();
	
	//osgDB::Registry::instance()->setBuildKdTreesHint(osgDB::ReaderWriter::Options::BUILD_KDTREES);
	//test
	//osg::ref_ptr<osg::Group> sphere = new osg::Group;
	//osg::ref_ptr<osg::Drawable> drawable = new osg::ShapeDrawable(new osg::Sphere(osg::Vec3(0.0f, 0.0f, 5000.0f), 100));
	////把球体加入到叶节点
	//osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	//geode->addDrawable(drawable.get());
	//sphere->addChild(geode.get());
	//myScene->addChild(sphere.get());
	
	//给模型设置刻线效果
	/*osg::ref_ptr<osgFX::Scribe> sc = new osgFX::Scribe();
	sc->setWireframeColor(osg::Vec4(0.1f, 0.1f, 0.1f, 1.0f));
	sc->setWireframeLineWidth(0.8f);
	sc->addChild(model.get());*/
	
	//把模型平移到原点，并对模型进行缩放
	/*osg::BoundingSphere modelBoundSphere = model->getBound();
	osg::ref_ptr<osg::MatrixTransform> mt1 = new osg::MatrixTransform;
	mt1->setMatrix(osg::Matrix::translate(osg::Vec3f(-modelBoundSphere.center().x(), -modelBoundSphere.center().y(), -modelBoundSphere.center().z())));
	mt1->addChild(model.get());
	osg::ref_ptr<osg::MatrixTransform> mt2 = new osg::MatrixTransform;
	mt2->setMatrix(osg::Matrix::scale(osg::Vec3(0.25f, 0.25f, 0.25f)));
	mt2->addChild(mt1);
	myScene->addChild(mt2);*/
	
	myScene->addChild(model.get());
	myScene->addChild(wireModel.get());

	//把线框模型平移到原点，并对它进行缩放
	/*osg::BoundingSphere wireModelBoundSphere = wireModel->getBound();
	osg::ref_ptr<osg::MatrixTransform> wireMt1 = new osg::MatrixTransform;
	wireMt1->setMatrix(osg::Matrix::translate(osg::Vec3f(-wireModelBoundSphere.center().x(), -wireModelBoundSphere.center().y(), -wireModelBoundSphere.center().z())));
	wireMt1->addChild(wireModel.get());
	osg::ref_ptr<osg::MatrixTransform> wireMt2 = new osg::MatrixTransform;
	wireMt2->setMatrix(osg::Matrix::scale(osg::Vec3(0.25f, 0.25f, 0.25f)));
	wireMt2->addChild(wireMt1);
	rootNode->addChild(wireMt2);*/
	
	/*osg::ref_ptr<osg::CullFace> cull = new osg::CullFace;
	cull->setMode(osg::CullFace::BACK);
	myScene->getOrCreateStateSet()->setAttributeAndModes(cull, osg::StateAttribute::ON);*/

	//设置1个环境点光源
	//osg::Node* light1 = createLightSource(1, osg::Vec3(modelBoundSphere.center().x(), modelBoundSphere.center().y(), modelBoundSphere.center().z()), osg::Vec4(0.1, 0.1, 0.1, 0.5));
	/*osg::Node* light1 = createLightSource(1, osg::Vec3(0, 0, 01), osg::Vec4(1.0, 1.0, 1.0, 1.0));
	rootNode->getOrCreateStateSet()->setMode(GL_LIGHT1, osg::StateAttribute::ON);
	rootNode->addChild(light1);*/

	//创建天空盒
	/*osg::ref_ptr<osg::Node> skydome = osgDB::readNodeFile("skydome.osgt");
	osg::BoundingSphere skydomeBoundSphere = skydome->getBound();
	osg::ref_ptr<osg::MatrixTransform> mt3 = new osg::MatrixTransform;
	mt3->setMatrix(osg::Matrix::translate(osg::Vec3f(-skydomeBoundSphere.center().x(), -skydomeBoundSphere.center().y(), -skydomeBoundSphere.center().z())));
	mt3->addChild(skydome);
	osg::ref_ptr<osg::MatrixTransform> mt4 = new osg::MatrixTransform;
	mt4->setMatrix(osg::Matrix::scale(osg::Vec3(5.0f, 5.0f, 5.0f)));
	mt4->addChild(mt3);
	rootNode->addChild(mt4);*/

	//osgDB::writeNodeFile(*(myScene.get()), "myModel.osg");
	//osgDB::Registry::instance()->writeNode(*(myScene.get()), "myModel_2.ive", osgDB::Registry::instance()->getOptions());

	//把场景节点加入到阴影节点中
	//shadowedScene->addChild(myScene.get());
	//rootNode->addChild(shadowedScene.get());
	////优化场景
	//osgUtil::Optimizer optimizer;
	//optimizer.optimize(rootNode.get());
	//viewer->setSceneData(rootNode.get());

	rootNode->addChild(myScene.get());
	osgUtil::Optimizer optimizer;
	optimizer.optimize(rootNode.get());
	viewer->setSceneData(rootNode.get());
	
	////RTT导航图
	//osg::ref_ptr<osg::Camera> rttCamera = new osg::Camera;
	//rttCamera->setName("upCamera");
	////设置导航窗口的大小(目前是以这个例子为例，后面需根据不同的模型大小设置窗口大小)
	////camera->setComputeNearFarMode(osg::Camera::DO_NOT_COMPUTE_NEAR_FAR);
	//osg::BoundingSphere boundSphere = mt2->getBound();
	//rttCamera->setProjectionMatrixAsOrtho(-boundSphere.radius() / 2, boundSphere.radius() / 2, -boundSphere.radius() / 2, boundSphere.radius() / 2, 0, 600);
	////camera->setViewMatrixAsLookAt(osg::Vec3(0, 0, 1000), osg::Vec3(0, 0, 0), osg::Vec3(0, 1, 0));
	////camera->setProjectionMatrixAsOrtho(-400, 400, -400, 400, 0, 600);
	//rttCamera->setViewMatrixAsLookAt(osg::Vec3(0, 0, 150), osg::Vec3(0, 0, 0), osg::Vec3(0, 1, 0));
	//rttCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	////camera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	//rttCamera->setAllowEventFocus(false);
	//rttCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	//rttCamera->addChild(mt2.get());
	//nm->addChild(CreatePointer());
	//rttCamera->addChild(nm.get());
	////把全景渲染到RTT
	//osg::Texture2D *t2d = new osg::Texture2D;
	//t2d->setInternalFormat(GL_RGBA);
	//rttCamera->attach(osg::Camera::COLOR_BUFFER, t2d);
	//rootNode->addChild(rttCamera);
	//rootNode->addChild(CreateHUD(t2d));

	//简单漫游器的实现
	/*osg::ref_ptr<MyNavigator> mNavigator = new MyNavigator(master, rttCamera, nm);
	mNavigator->setMnode(myScene);*/
	//viewer->setCameraManipulator(mNavigator);

	//设置导航图三角形初始坐标
	osg::Vec3 eye, center, up;
	master->getViewMatrixAsLookAt(eye, center, up);
	nm->setMatrix(osg::Matrix::translate(osg::Vec3d(eye.x(), eye.y(), eye.z())));

	viewer->setCameraManipulator(new osgGA::TrackballManipulator());
	viewer->addEventHandler(new CPickHandler(ifcModel, viewer));
	//viewer->addEventHandler(new osgViewer::StatsHandler);
	//切换摄像机
	//viewer->addEventHandler(new SwitchCameraManipulator(rootNode, master, viewer.get(), mt2.get()));
	viewer->addEventHandler(new SwitchCameraManipulator(rootNode, master, viewer.get(), model.get()));

	viewer->realize();
	viewer->run();
	return 0;
}