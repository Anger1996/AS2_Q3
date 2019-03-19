#include "Lights.h"
#include <cmath>


Lights::Lights() :
	isVisualized(false)
{
	static GLfloat ambient[] =
	{   
	    // LIGHT 0 
		0.1f, 0.0f, 0.0f, 1.0f,
		// LIGHT 1 
		0.0f, 0.1f, 0.0f, 1.0f
	};

	static GLfloat diffuse[] =
	{
		// LIGHT 0
		0.9f, 0.0f, 0.0f, 1.0f,
		// LIGHT 1
		0.0f, 0.9f, 0.0f, 1.0f

	};

	static GLfloat specular[] =
	{
		// LIGHT 0 
		0.7f, 0.0f, 0.0f, 1.0f,
		// LIGHT 1 
		0.0f, 0.7f, 0.0f, 1.0f
	};

	_ambient = ambient;
	_diffuse = diffuse;
	_specular = specular;
}

Lights::~Lights()
{
}


void Lights::Display()
{

	/*draw the lights if choose to visualize them */
	if (isVisualized) {

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glDisable(GL_LIGHTING);

		// LIGHT 0
		glPushMatrix();
		glColor4fv(&_diffuse[_LIGHT0_]);
		glTranslatef(-145, 0, 0);
		glutSolidSphere(10.0f, 10, 10);
		glPopMatrix();

		// LIGHT 1
		glPushMatrix();
		glColor4fv(&_diffuse[_LIGHT1_]);
		glTranslatef(145, 0, 0);
		glutSolidSphere(10.0f, 10, 10);

		glPopMatrix();
		glPopAttrib();

	}
	
	//enable lighting
	glEnable(GL_LIGHTING);

	/*set and enable the lights*/
	//light1
	GLfloat l_0_Position[4] = { -145, 0, 0, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, l_0_Position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &_ambient[_LIGHT0_]);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &_diffuse[_LIGHT0_]);
	glLightfv(GL_LIGHT0, GL_SPECULAR, &_specular[_LIGHT0_]);
	glEnable(GL_LIGHT0);

	//light2
	GLfloat l_1_Position[4] = { 145, 0, 0, 1.0f};
	glLightfv(GL_LIGHT1, GL_POSITION, l_1_Position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, &_ambient[_LIGHT1_]);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, &_diffuse[_LIGHT1_]);
	glLightfv(GL_LIGHT1, GL_SPECULAR, &_specular[_LIGHT1_]);
	glEnable(GL_LIGHT1);

}


void Lights::HandleKey(unsigned char key, int state, int x, int y)
{
	// press p to visuallize or unvisualize the lights
	if (!state) return;

	switch (key)
	{
	case 'p':
		visualiseLights();
		break;
	}
}

void  Lights::visualiseLights()
{ 
	isVisualized = !isVisualized;
}

