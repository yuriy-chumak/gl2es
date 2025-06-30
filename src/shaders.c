#include "gl2es.h"

static
GLint create_program(char* code)
{
	// VLOG("create_program(...)\n");
	GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
	{
		const GLchar* codes[] = {
			//"#version 110",
			"precision mediump float;\n",
			//"precision lowp float;\n"
			"#define VERTEX_SHADER\n",
			code };
		glShaderSource(vshader, sizeof(codes)/sizeof(*codes), codes, NULL);
		glCompileShader(vshader);

		GLint compiled = 0;
		glGetShaderiv(vshader, GL_COMPILE_STATUS, &compiled);
		VLOG("  compiled(%d): %d\n", vshader, compiled);
		if (compiled != GL_TRUE) {
			GLsizei length = 0;
			GLchar message[999];
			glGetShaderInfoLog(vshader, sizeof(message), &length, message);
			ELOG("vertex shader error: %s\n", message);
		}
	}
	// VLOG("vshader = %d\n", vshader);

	GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
	{
		const GLchar* codes[] = {
			//"#version 110",
			"precision mediump float;\n",
			// "precision lowp float;\n"
			"#define FRAGMENT_SHADER\n",
			code };
		glShaderSource(fshader, sizeof(codes)/sizeof(*codes), codes, NULL);
		glCompileShader(fshader);

		GLint compiled;
		glGetShaderiv(fshader, GL_COMPILE_STATUS, &compiled);
		if (compiled != GL_TRUE) {
			GLsizei length = 0;
			GLchar message[999];
			glGetShaderInfoLog(fshader, sizeof(message), &length, message);
			ELOG("fragment shader error: %s\n", message);
		}
	}
	// ILOG("fshader = %d\n", fshader);

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
		ELOG("program error: %s\n", message);
	}
	glDetachShader(program, vshader);
	glDetachShader(program, fshader);

	VLOG("program = %d\n", program);
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
	VLOG("glUsePredefinedProgram(%d)\n", id);
	switch (id) {
		case PP_VERTEX_COLOR: {
		#	include "vc.b"    // vertices + color
			return glUsePredefinedProgram0(&GL2.vc, vc);
		}
		case PP_VERTEX_COLOR_TEXTURE0: {
		#	include "vct0.b"    // vertices + color + texture0
			return glUsePredefinedProgram0(&GL2.vct0, vct0);
		}

		default:
			ELOG("glUsePredefinedProgram(%d): unknown ID", id);
	}
	return 0;
}
