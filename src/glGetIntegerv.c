#include <GL2/gl.h>

__attribute__((visibility("default")))
void glGetIntegerv(GLenum pname, GLint *params)
{
	ILOG("%p: glGetIntegerv(%04x,%p)", &GL2, pname, params);
	if (!params) return;

	switch (pname) {
		case GL_MATRIX_MODE:
			*params = GL2.matrix_mode;
			break;
		case GL_VR:
			ILOG("  GL_VR: %d", GL2.vr.present);
			*params = GL2.vr.present;
			break;
		case GL_VR_HINT:
			ILOG("  GL_VR_HINT: %d", GL2.vr.enabled);
			*params = GL2.vr.enabled;
			break;

		default:
			gles_glGetIntegerv(pname, params);
	}
	(void) 0;
}
