#include "gl2es.h"

#include <matrix.h>
#include <math.h>

static
void glRotate(float_t angle, float_t x, float_t y, float_t z)
{
	// normalize x y z
	float_t l = 1.0f / sqrt(x*x + y*y + z*z);
	x = x*l; y = y*l; z = z*l;

	// calculate sin/cos
	angle *= 3.1415926535f/180.f;
	const float_t s = sin(angle); 
	const float_t c = cos(angle);
	const float_t c1 = 1 - c;

	// build the matrix
	float_t tmp[16] = {
		x*x*c1+c, y*x*c1+z*s, x*z*c1-y*s, 0,
		x*y*c1-z*s, y*y*c1+c, y*z*c1+x*s, 0,
		x*z*c1+y*s, y*z*c1-x*s, z*z*c1+c, 0,
		0,0,0,1
	};

	glMultMatrixf(tmp);

	(void) 0;
}

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	glRotate((float_t)angle, (float_t)x, (float_t)y, (float_t)z);
}

__attribute__((visibility("default")))
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	glRotate((float_t)angle, (float_t)x, (float_t)y, (float_t)z);
}
