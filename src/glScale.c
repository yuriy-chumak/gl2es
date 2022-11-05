#include <gl2es.h>

#include <matrix.h>
#include <math.h>

static
void glScale(float_t x, float_t y, float_t z)
{
	float_t tmp[16] = {
		x,0,0,0,
		0,y,0,0,
		0,0,z,0,
		0,0,0,1
	};
	glMultMatrixf(tmp);

	(void) 0;
}

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glScalef(GLfloat x, GLfloat y, GLfloat z)
{
	glScale((float_t)x, (float_t)y, (float_t)z);
}

__attribute__((visibility("default")))
void glScaled(GLdouble x, GLdouble y, GLdouble z)
{
	glScale((float_t)x, (float_t)y, (float_t)z);
}
