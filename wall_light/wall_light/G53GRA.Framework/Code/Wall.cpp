#include "Wall.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

void Wall::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glDisable(GL_COLOR_MATERIAL);

	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 0.f, 0.f, 0.f, 1.0f };
	float shininess = 128.0f;
	float _ambient[] = { 0.5f, 0.5f, 0.5f, 0.5f };

	glScalef(scale[0], scale[1], scale[2]);

	glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
	glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, static_cast<GLfloat*>(diffuse));
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(_ambient));

	float side_length = 0.01f;

	for(float i = -3.0f; i <= 3.0f; i += side_length) {
		for (float j = -2.0f; j <= 2.0f; j += side_length) {

			glBegin(GL_TRIANGLES);
		
			//set the normal vector
			glNormal3f(0.0f, 0.0f, 1.0f);

			//draw two triangles as a square
			glVertex3f(i, j, -100.0f);
			glVertex3f(i + side_length, j, -100.0f);
			glVertex3f(i + side_length, j + side_length, -100.0f);

			glVertex3f(i, j, -100.0f);
			glVertex3f(i + side_length, j + side_length, -100.0f);
			glVertex3f(i, j + side_length, -100.0f);
		
			glEnd();
		}
	}

	glPopAttrib();
	glPopMatrix();
	
}