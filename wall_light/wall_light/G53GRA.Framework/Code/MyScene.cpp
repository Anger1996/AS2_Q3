#include "MyScene.h"
#include "Wall.h"
#include "Lights.h"
MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Wall * w = new Wall();
	w->size(130.0f, 130.0f, 1.0f);


	Lights *l = new Lights();
	
	AddObjectToScene(w);

	AddObjectToScene(l);

	

}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
