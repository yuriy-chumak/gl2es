#include "log.h"

#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl3ext.h>

#include <EGL/egl.h>

#include <gl2es.h>
#include <string.h>
#include <stdlib.h>

state_t GL2;

void Init()
{
	memset(&GL2, 0, sizeof(GL2));

	// create default display list for (glBegin/glEnd)
	GL2.lists = calloc(0, sizeof(list_t)); // yes zero
	glGenLists(1);

	// create default matrix stack
	GL2.stack = calloc(0, sizeof(float_t) * 16);

	//  the initial value for the current color
	GL2.color.r = 1;
	GL2.color.g = 1;
	GL2.color.b = 1;
	GL2.color.a = 1;

	// ...
}

void Done()
{

}

#include <dlfcn.h>

__attribute__((visibility("default")))
void* gl2GetProcAddress(char const * procname)
{
	static void* gl2es = 0;
	if (gl2es == 0)
		gl2es = dlopen("libgl2es.so", RTLD_LAZY);
	void* proc = 0;
	if (gl2es != 0)
		proc = dlsym(gl2es, procname);
	if (proc == 0)
		proc = eglGetProcAddress(procname);
	return proc;
}
