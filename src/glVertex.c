#include "gl2es.h"
#include <lists.h>

#include <stdlib.h>
#include <string.h>
// todo: process glMultMatrix etc in the lists

static
void glVertex(float_t x, float_t y, float_t z, float_t w)
{
	VLOG("glVertex(%f, %f, %f, %f)\n", x, y, z, w);
	int selected = GL2.lists_selected;

	list_t* list = List(selected);
	attrib_t* attrib;
	attrib = List_Attrib(list, list->count);

	// set vertex data
	attrib->vertex.x = x;
	attrib->vertex.y = y;
	attrib->vertex.z = z;
	attrib->vertex.w = w;

	// copy color data
	attrib->color.r = GL2.color.r;
	attrib->color.g = GL2.color.g;
	attrib->color.b = GL2.color.b;
	attrib->color.a = GL2.color.a;

	// VLOG("  color = vec4(%f, %f, %f, %f)\n", attrib->color.r, attrib->color.g, attrib->color.b, attrib->color.a);

	list->count++;
	// VLOG("  list->count = %zu\n", list->count);

	// grow attribs vector if needed
	size_t size = list->size;
	size_t count = list->count;
	if (count >= size) {
		size_t new_size = count + count/3;
		list->attribs = realloc(list->attribs, new_size * sizeof(attrib_t));
		list->size = new_size;
	}

	if (list->mode == GL_QUADS && list->count % 6 == 4) {
		glVertex(x, y, z, w);
		glVertex(x, y, z, w);
		// 1,2,3  4,x,x

		int i = list->count;
		list->attribs[i-1] = list->attribs[i-3];
		// 1,2,3  4,x,4
#ifndef COMPATIBLE_QUADS
		list->attribs[i-2] = list->attribs[i-4];
		// 1,2,3  4,3,4
		list->attribs[i-3] = list->attribs[i-6];
		// 1,2,3  1,3,4
#else	// slower
		list->attribs[i-2] = list->attribs[i-4];
		// 1,2,3  4,3,4
		list->attribs[i-3] = list->attribs[i-5];
		// 1,2,3  4,3,4
		list->attribs[i-4] = list->attribs[i-1];
		// 1,2,4  2,3,4
#endif
	}

	(void) 0;
}

// -=( OpenGL )=--------------------
//	https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glVertex.xml
#define X 0
#define Y 0
#define Z 0
#define Q 1

// - 2 -
#define GLVECTEX2(suffix,type) \
	__attribute__((used, visibility("default")))\
	void glVertex2##suffix(type x, type y)\
	{\
		(void) glVertex((float_t)x, (float_t)y, (float_t)Z, (float_t)Q);\
	}\
	__attribute__((used, visibility("default")))\
	void glVertex2##suffix##v(const type *v)\
	{\
		(void) glVertex((float_t)v[0], (float_t)v[1], (float_t)Z, (float_t)Q);\
	}

GLVECTEX2(s, GLshort)
GLVECTEX2(i, GLint)
GLVECTEX2(f, GLfloat)
GLVECTEX2(d, GLdouble)

// - 3 -
#define GLVECTEX3(suffix,type) \
	__attribute__((used, visibility("default")))\
	void glVertex3##suffix(type x, type y, type z)\
	{\
		(void) glVertex((float_t)x, (float_t)y, (float_t)z, (float_t)Q);\
	}\
	__attribute__((used, visibility("default")))\
	void glVertex3##suffix##v(const type *v)\
	{\
		(void) glVertex((float_t)v[0], (float_t)v[1], (float_t)v[2], (float_t)Q);\
	}

GLVECTEX3(s, GLshort)
GLVECTEX3(i, GLint)
GLVECTEX3(f, GLfloat)
GLVECTEX3(d, GLdouble)

// - 4 -
#define GLVECTEX4(suffix,type) \
	__attribute__((used, visibility("default")))\
	void glVertex4##suffix(type x, type y, type z, type w)\
	{\
		(void) glVertex((float_t)x, (float_t)y, (float_t)z, (float_t)w);\
	}\
	__attribute__((used, visibility("default")))\
	void glVertex4##suffix##v(const type *v)\
	{\
		(void) glVertex((float_t)v[0], (float_t)v[1], (float_t)v[2], (float_t)v[3]);\
	}

GLVECTEX4(s, GLshort)
GLVECTEX4(i, GLint)
GLVECTEX4(f, GLfloat)
GLVECTEX4(d, GLdouble)
