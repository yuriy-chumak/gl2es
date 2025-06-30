#include "gl2es.h"
#include <lists.h>

static
void glNormal(float_t nx, float_t ny, float_t nz)
{
	int selected = GL2.lists_selected;
	list_t* list = List(selected);
	attrib_t* attrib;

	attrib = List_Attrib(list, list->count);
	attrib->normal.x = nx;
	attrib->normal.y = ny;
	attrib->normal.z = nz;

	(void) 0;
}

// -=( OpenGL )=--------------------
//	https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glNormal.xml
#include <limits.h>

#define X 0
#define Y 0
#define Z 0

// Byte, short, or integer arguments are converted to floating-point format with
//	a linear mapping that maps the most positive representable integer value to
//	1.0 and the most negative representable integer value to -1.0

// Normals specified with glNormal need not have unit length.

// - 3 -
#define GLNORMAL3(suffix,type,ceiling)\
	__attribute__((visibility("default")))\
	void glNormal3##suffix(type nx, type ny, type nz)\
	{\
		(void) glNormal((float_t)nx/(float_t)ceiling, \
		                (float_t)ny/(float_t)ceiling, \
		                (float_t)nz/(float_t)ceiling);\
	}\
	__attribute__((visibility("default")))\
	void glNormal3##suffix##v(const type *v)\
	{\
		(void) glNormal((float_t)v[0]/(float_t)ceiling, \
		                (float_t)v[1]/(float_t)ceiling, \
		                (float_t)v[2]/(float_t)ceiling);\
	}

GLNORMAL3(b, GLbyte, SCHAR_MAX)
GLNORMAL3(s, GLshort, SHRT_MAX)
GLNORMAL3(i, GLint,    INT_MAX)
GLNORMAL3(f, GLfloat,        1)
GLNORMAL3(d, GLdouble,       1)
