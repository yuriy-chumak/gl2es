#pragma once
#include "es.h"

#include "log.h"

// typedef double GLdouble;
// typedef double GLclampd;

// VR Support
#define VR_PROJECTION        (0x10000 + GL_PROJECTION)
#define VR_MODELVIEW         (0x10000 + GL_MODELVIEW)

#define VR_PROJECTION_MATRIX (0x10000 + GL_PROJECTION_MATRIX)
#define VR_MODELVIEW_MATRIX  (0x10000 + GL_MODELVIEW_MATRIX)

#define GL_VR_HINT           (0x12001)
#define GL_VR                (0x10C33) // GL_STEREO+0x10000

// !the name and value can be changed!
#define GL_VBO_SIZE          (0x12002)

// default inexact type
#include <float_t.h>

// OpenGL Display Lists
#include <lists.h>

// OpenGL states:
typedef struct {
	int current_list; //? rename to active_list

	float4_t color; // glColor

	// Display Lists (todo: stucture lists_t ?)
	list_t*lists;
	size_t lists_count;
	size_t lists_selected; // todo: rename to lists_current ?
	GLenum lists_mode; // mode between glNewList() and glEndList()

	// Matrices
	struct {
		matrix_t projection;
		matrix_t model_view;
		matrix_t texture[2]; // пока-что 2 матрицы, больше не надо
	} gm; // global matrices
	GLenum matrix_mode; // glMatrixMode()

	struct {
		int present; // VR
		int enabled; // VR_HINT, use vr projection/view matrices
		matrix_t projection;
		matrix_t view;
	} vr; // virtual reality

	// Matrix Stack
	// todo: struct
	float_t *stack; // по 16 элементов
	size_t stack_size;
	size_t stack_top;

	// Texturing
	// GLint texturing; // glEnable/glDisable(GL_TEXTURE_2D)
	GLenum active_texture; // активный текстурный юнит

	// todo: texture, color

	// Lights
	struct {
		int enabled;
		float4_t position;
		// ...
	} lights[2];

	// Shaders
	GLint vc, vct0;

} state_t;

// shaders.c:
// todo: make ubershader and compile with different options
//       once required (using #define and bitmask for features)
#define PP_VERTEX_COLOR 1 // only color
#define PP_VERTEX_COLOR_TEXTURE0 2 // color with texture
GLint glUsePredefinedProgram(int program);


extern state_t GL2;
