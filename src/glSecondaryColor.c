#include "gl2es.h"
#include <lists.h>

static
void glSecondaryColor(float_t r, float_t g, float_t b, float_t a)
{
	int selected = GL2.lists_selected;
	list_t* list = List(selected);
	attrib_t* attrib = List_Attrib(list, list->count);

	attrib->color2.r = r;
	attrib->color2.g = g;
	attrib->color2.b = b;
	attrib->color2.a = a;

	(void) 0;
}

// -=( OpenGL )=--------------------
//	https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glSecondaryColor.xml
#include <limits.h>

#define RED 1
#define GREEN 1
#define BLUE 1
#define ALPHA 1

// - 3 -
#define GLSECONDARYCOLOR3(suffix,type,ceiling) \
	__attribute__((visibility("default")))\
	void glSecondaryColor3##suffix(type red, type green, type blue)\
	{\
		(void) glSecondaryColor((float_t)red/(float_t)ceiling,\
		                        (float_t)green/(float_t)ceiling,\
		                        (float_t)blue/(float_t)ceiling,\
		                        (float_t)ALPHA);\
	}\
	__attribute__((visibility("default")))\
	void glSecondaryColor3##suffix##v(const type *rgb)\
	{\
		(void) glSecondaryColor((float_t)rgb[0]/(float_t)ceiling,\
		                        (float_t)rgb[1]/(float_t)ceiling,\
		                        (float_t)rgb[2]/(float_t)ceiling,\
		                        (float_t)ALPHA);\
	}

GLSECONDARYCOLOR3(b,  GLbyte,   SCHAR_MAX)
GLSECONDARYCOLOR3(s,  GLshort,   SHRT_MAX)
GLSECONDARYCOLOR3(i,  GLint,      INT_MAX)
GLSECONDARYCOLOR3(f,  GLfloat,          1) // Floating-point values are mapped directly.
GLSECONDARYCOLOR3(d,  GLdouble,         1) // Floating-point values are mapped directly.
GLSECONDARYCOLOR3(ub, GLubyte,  UCHAR_MAX)
GLSECONDARYCOLOR3(us, GLushort, USHRT_MAX)
GLSECONDARYCOLOR3(ui, GLuint,    UINT_MAX)
