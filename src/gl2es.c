#include "gl2es.h"

#ifndef __WAJIC__
#	include <GLES3/gl3.h>
#	include <GLES2/gl2ext.h>
 //#include <GLES3/gl3ext.h>

#	include <EGL/egl.h>
#else
#	include <GL/gl.h>
#endif

#include <string.h>
#include <stdlib.h>


#ifndef GL2ES_LIBRARY_SO_NAME
#  define GL2ES_LIBRARY_SO_NAME "libgl2es.so"
#endif

#ifndef __WAJIC__

// shaders

#endif
// global GL2 state
state_t GL2;

// init GL function(s)
// context already created and activated
void Init()
{
	// VLOG("Init()\n");
	memset(&GL2, 0, sizeof(GL2));

	// create default display list for (glBegin/glEnd)
	GL2.lists = calloc(0, sizeof(list_t)); // yes zero
	glGenLists(1);

	// default matrix mode
	GL2.matrix_mode = GL_MODELVIEW;
	// setup initial matrices
	GL2.gm.projection[0] = GL2.gm.projection[5] = GL2.gm.projection[10] = GL2.gm.projection[15] = 1;
	GL2.gm.model_view[0] = GL2.gm.model_view[5] = GL2.gm.model_view[10] = GL2.gm.model_view[15] = 1;
	GL2.gm.texture[0][0] = GL2.gm.texture[0][5] = GL2.gm.texture[0][10] = GL2.gm.texture[0][15] = 1;
	GL2.gm.texture[1][0] = GL2.gm.texture[1][5] = GL2.gm.texture[1][10] = GL2.gm.texture[1][15] = 1;

	// create default matrix stack
	GL2.stack = calloc(0, sizeof(float_t) * 16);

	//  the initial value for the current color
	GL2.color.r = 1;
	GL2.color.g = 1;
	GL2.color.b = 1;
	GL2.color.a = 1;
}

void Done()
{

}

// link real GL2ES library
#include <dlfcn.h>

__attribute__((visibility("default")))
void* gl2GetProcAddress(char const * procname)
{
	static void* gl2es = 0;
	if (gl2es == 0)
		gl2es = dlopen(GL2ES_LIBRARY_SO_NAME, RTLD_LAZY);

	void* proc = 0;
	if (gl2es != 0)
		proc = dlsym(gl2es, procname);
	// not found? load a real egl proc
#ifndef __WAJIC__
	if (proc == 0)
		proc = eglGetProcAddress(procname);
#endif
	return proc;
}
