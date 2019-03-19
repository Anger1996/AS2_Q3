#include "DisplayableObject.h"
#include "Input.h"

#define _LIGHT0_ 0
#define _LIGHT1_ 4

class Lights :
	public DisplayableObject,
	public Input
{
public:
	Lights();
	~Lights();

	void Display();
	void HandleKey(unsigned char key, int state, int x, int y);

	void visualiseLights();


private:
	GLfloat *_ambient, *_diffuse, *_specular;
	bool isVisualized;
};
