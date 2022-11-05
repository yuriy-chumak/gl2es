#include <gl2es.h>

#include <matrix.h>

static
void glTranslate(float_t x, float_t y, float_t z)
{
	float_t tmp[16] = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		x,y,z,1
	};
	glMultMatrixf(tmp);

	(void) 0;
}

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	glTranslate((float_t)x, (float_t)y, (float_t)z);
}

__attribute__((visibility("default")))
void glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
	glTranslate((float_t)x, (float_t)y, (float_t)z);
}
