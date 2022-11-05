#include <gl2es.h>

#include <string.h>

__attribute__((visibility("default")))
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble nearVal, GLdouble farVal)
{
	GLfloat tmp[16];
	memset(tmp, 0, 16*sizeof(GLfloat));

	tmp[0+0] = 2.0f/(right-left);     tmp[0+12] = -(right+left)/(right-left);
	tmp[1+4] = 2.0f/(top-bottom);     tmp[1+12] = -(top+bottom)/(top-bottom);
	tmp[2+8] =-2.0f/(farVal-nearVal); tmp[2+12] = -(farVal+nearVal)/(farVal-nearVal);
	                                  tmp[3+12] = 1.0f;

	glMultMatrixf(tmp);
	(void) 0;
}