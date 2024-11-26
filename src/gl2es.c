#include "log.h"

#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
//#include <GLES3/gl3ext.h>

#include <EGL/egl.h>
#include <GL2/gl.h>

#include <string.h>
#include <stdlib.h>

#ifndef GL2ES_LIBRARY_SO_NAME
#  define GL2ES_LIBRARY_SO_NAME "libgl2es.so"
#endif

// shaders

static
void check_chader(GLint shader) {
	GLint compiled;
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE) {
    	GLsizei length = 0;
    	GLchar message[999];
    	glGetShaderInfoLog(shader, sizeof(message), &length, message);
		ELOG("shader error: %s", message);
	}
}

static
GLint create_program(char* code)
{
	GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
	{
		const GLchar* codes[] = { "#define __VERTEX_SHADER__", code };
		glShaderSource(vshader, 2, codes, NULL);
		glCompileShader(vshader);  check_chader(vshader);
	}
	// ILOG("vshader = %d", vshader);

	GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
	{
		const GLchar* codes[] = { "#define __FRAGMENT_SHADER__", code };
		glShaderSource(fshader, 2, codes, NULL);
		glCompileShader(fshader);  check_chader(fshader);
	}
	// ILOG("fshader = %d", fshader);


	GLuint program = glCreateProgram();
	glAttachShader(program, vshader);
	glAttachShader(program, fshader);
	glLinkProgram(program);
	GLint linked;

	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (linked != GL_TRUE) {
    	GLsizei length = 0;
    	GLchar message[999];
    	glGetProgramInfoLog(program, sizeof(message), &length, message);
		ELOG("program error: %s", message);
	}
	glDetachShader(program, vshader);
	glDetachShader(program, fshader);

	// ILOG("program = %d", program);
	return program;
}

GLint glUsePredefinedProgram0(GLint* program, char* code)
{
	if (*program == 0)
		*program = create_program(code);
	glUseProgram(*program);
	return *program;
}

GLint glUsePredefinedProgram(int id)
{
	switch (id) {
		case PP_VERTEX_COLOR: {
			#include "vc.b"    // vertices + color
			return glUsePredefinedProgram0(&GL2.vc, vc);
		}
		case PP_VERTEX_COLOR_TEXTURE0: {
			#include "vct0.b"    // vertices + color + texture0
			return glUsePredefinedProgram0(&GL2.vct0, vct0);
		}

		default:
			ELOG("glUsePredefinedProgram(%d): unknown ID", id);
	}
	return 0;
}

// global GL2 state
state_t GL2;

// init GL function(s)
// context already created and activated
void Init()
{
	memset(&GL2, 0, sizeof(GL2));

	// create default display list for (glBegin/glEnd)
	GL2.lists = calloc(0, sizeof(list_t)); // yes zero
	glGenLists(1);

	// default matrix mode
	GL2.matrix_mode = GL_MODELVIEW;
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
	if (proc == 0)
		proc = eglGetProcAddress(procname);
	return proc;
}
