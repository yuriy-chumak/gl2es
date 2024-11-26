#include <GL2/gl.h>
#include <lists.h>

static
void glTexCoord(float_t s, float_t t, float_t p, float_t q)
{
	int selected = GL2.lists_selected;
	list_t* list = List(selected);
	attrib_t* attrib;

	// glTexCoord affects only first("0") texture unit (by standard)
	attrib = List_Attrib(list, list->count);
	attrib->texcoord[0].s = s;
	attrib->texcoord[0].t = t;
	attrib->texcoord[0].p = p;
	attrib->texcoord[0].q = q;

	// ILOG("glTexCoord(%d): [%f %f %f]: %f %f", list->count,
	// 			list->attribs[list->count].vertex.x,
	// 			list->attribs[list->count].vertex.y,
	// 			list->attribs[list->count].vertex.z,
	// 			list->attribs[list->count].texcoord[0].s,
	// 			list->attribs[list->count].texcoord[0].t);
	// ILOG("glTexCoord(%d): %f %f", list->count, s, t);
	(void) 0;
}

// -=( OpenGL )=--------------------
#define S 0
#define T 0
#define P 0
#define Q 1

// - 1 -
#define GLTEXCOORD1(suffix,type) \
	__attribute__((visibility("default")))\
	void glTexCoord1##suffix(type s)\
	{\
		(void) glTexCoord((float_t)s, (float_t)T, (float_t)P, (float_t)Q);\
	}\
	__attribute__((visibility("default")))\
	void glTexCoord1##suffix##v(const type *v)\
	{\
		(void) glTexCoord((float_t)v[0], (float_t)T, (float_t)P, (float_t)Q);\
	}

GLTEXCOORD1(s, GLshort)
GLTEXCOORD1(i, GLint)
GLTEXCOORD1(f, GLfloat)
GLTEXCOORD1(d, GLdouble)

// - 2 -
#define GLTEXCOORD2(suffix,type) \
	__attribute__((visibility("default")))\
	void glTexCoord2##suffix(type s, type t)\
	{\
		(void) glTexCoord((float_t)s, (float_t)t, (float_t)P, (float_t)Q);\
	}\
	__attribute__((visibility("default")))\
	void glTexCoord2##suffix##v(const type *v)\
	{\
		(void) glTexCoord((float_t)v[0], (float_t)v[1], (float_t)P, (float_t)Q);\
	}

GLTEXCOORD2(s, GLshort)
GLTEXCOORD2(i, GLint)
GLTEXCOORD2(f, GLfloat)
GLTEXCOORD2(d, GLdouble)

// - 3 -
#define GLTEXCOORD3(suffix,type) \
	__attribute__((visibility("default")))\
	void glTexCoord3##suffix(type s, type t, type p)\
	{\
		(void) glTexCoord((float_t)s, (float_t)t, (float_t)p, (float_t)Q);\
	}\
	__attribute__((visibility("default")))\
	void glTexCoord3##suffix##v(const type *v)\
	{\
		(void) glTexCoord((float_t)v[0], (float_t)v[1], (float_t)v[2], (float_t)Q);\
	}

GLTEXCOORD3(s, GLshort)
GLTEXCOORD3(i, GLint)
GLTEXCOORD3(f, GLfloat)
GLTEXCOORD3(d, GLdouble)

// - 4 -
#define GLTEXCOORD4(suffix,type) \
	__attribute__((visibility("default")))\
	void glTexCoord4##suffix(type s, type t, type p, type q)\
	{\
		(void) glTexCoord((float_t)s, (float_t)t, (float_t)p, (float_t)q);\
	}\
	__attribute__((visibility("default")))\
	void glTexCoord4##suffix##v(const type *v)\
	{\
		(void) glTexCoord((float_t)v[0], (float_t)v[1], (float_t)v[2], (float_t)v[3]);\
	}

GLTEXCOORD4(s, GLshort)
GLTEXCOORD4(i, GLint)
GLTEXCOORD4(f, GLfloat)
GLTEXCOORD4(d, GLdouble)
