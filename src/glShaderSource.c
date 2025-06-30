#include "gl2es.h"

__attribute__((visibility("default")))
void glShaderSource(
    GLuint shader, 
    GLsizei count, 
    const GLchar * const * string, 
    const GLint * length)
{
	ILOG("glShaderSource()\n");
	(void) esShaderSource(shader, count, string, length);
}

// TODO: add glHint() for "precision mediump float;", for example