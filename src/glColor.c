#include <GL2/gl.h>

#include <lists.h>

static
void glColor(float_t r, float_t g, float_t b, float_t a)
{
	int selected = GL2.lists_selected;
	list_t* list = List(selected);
	attrib_t* attrib = List_Attrib(list, list->count);

	attrib->color.r = GL2.color.r = r;
	attrib->color.g = GL2.color.g = g;
	attrib->color.b = GL2.color.b = b;
	attrib->color.a = GL2.color.a = a;

	(void) 0;
}

// -=( OpenGL )=--------------------
//	https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glColor.xml
#include <limits.h>

#define RED 1
#define GREEN 1
#define BLUE 1
#define ALPHA 1

// - 3 -
#define GLCOLOR3(suffix,type,ceiling) \
	__attribute__((visibility("default")))\
	void glColor3##suffix(type red, type green, type blue)\
	{\
		(void) glColor((float_t)red/(float_t)ceiling,\
		               (float_t)green/(float_t)ceiling,\
		               (float_t)blue/(float_t)ceiling,\
		               (float_t)ALPHA);\
	}\
	__attribute__((visibility("default")))\
	void glColor3##suffix##v(const type *rgb)\
	{\
		(void) glColor((float_t)rgb[0]/(float_t)ceiling,\
		               (float_t)rgb[1]/(float_t)ceiling,\
		               (float_t)rgb[2]/(float_t)ceiling,\
		               (float_t)ALPHA);\
	}

GLCOLOR3(b,  GLbyte,   SCHAR_MAX)
GLCOLOR3(s,  GLshort,   SHRT_MAX)
GLCOLOR3(i,  GLint,      INT_MAX)
GLCOLOR3(f,  GLfloat,          1) // Floating-point values are mapped directly.
GLCOLOR3(d,  GLdouble,         1) // Floating-point values are mapped directly.
GLCOLOR3(ub, GLubyte,  UCHAR_MAX)
GLCOLOR3(us, GLushort, USHRT_MAX)
GLCOLOR3(ui, GLuint,    UINT_MAX)

// - 4 -
#define GLCOLOR4(suffix,type,ceiling) \
	__attribute__((visibility("default")))\
	void glColor4##suffix(type red, type green, type blue, type alpha)\
	{\
		(void) glColor((float_t)red/(float_t)ceiling,\
		               (float_t)green/(float_t)ceiling,\
		               (float_t)blue/(float_t)ceiling,\
		               (float_t)alpha/(float_t)ceiling);\
	}\
	__attribute__((visibility("default")))\
	void glColor4##suffix##v(const type *rgb)\
	{\
		(void) glColor((float_t)rgb[0]/(float_t)ceiling,\
		               (float_t)rgb[1]/(float_t)ceiling,\
		               (float_t)rgb[2]/(float_t)ceiling,\
		               (float_t)rgb[3]/(float_t)ceiling);\
	}

GLCOLOR4(b,  GLbyte,   SCHAR_MAX)
GLCOLOR4(s,  GLshort,   SHRT_MAX)
GLCOLOR4(i,  GLint,      INT_MAX)
GLCOLOR4(f,  GLfloat,          1) // Floating-point values are mapped directly.
GLCOLOR4(d,  GLdouble,         1) // Floating-point values are mapped directly.
GLCOLOR4(ub, GLubyte,  UCHAR_MAX)
GLCOLOR4(us, GLushort, USHRT_MAX)
GLCOLOR4(ui, GLuint,    UINT_MAX)
