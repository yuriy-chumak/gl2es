#pragma once

// default inexact type
#include <float_t.h>

#include <stddef.h>

// todo: optimize attrib structure to actually used attributes
// that can be done for the first "glVertex" call

//__attribute__((packed, aligned(4)))
typedef struct attrib_t {
	float4_t vertex;   // gl_Vertex
	float4_t color;    // gl_Color
	float4_t color2;   // gl_SecondaryColor
	float4_t texcoord[2]; // gl_MultiTexCoord{0}, остальные не используем
	float3_t normal;   // gl_Normal   (here because unaligned)
	float_t  fogcoord; // gl_FogCoord (currently unused)
} attrib_t;

typedef struct list_t { // todo: begin, end, ptr? without size, etc.?
	size_t size;  // общий размер буфера
	size_t count; // количество размещенных вершин
	GLenum mode;  // режим вывода (на данный момент разные моды одновременно не поддерживаются)
	struct list_t* next; // TBD. новый (прилинкованный) список для нового режима вывода
	GLuint vbo;
	attrib_t* attribs;
	// ...
} list_t;

list_t* List(size_t number);
attrib_t* List_Attrib(list_t* list, size_t number);

// OpenGL:
GLuint glGenLists(GLsizei range);
