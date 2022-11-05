#include <gl2es.h>

__attribute__((visibility("default")))
void glGetIntegerv(GLenum pname, GLint *params)
{
	if (!params) return;

	switch (pname) {
		case GL_MATRIX_MODE:
			*params = GL2.matrix_mode;
			break;
		case GL_VR:
			*params = GL2.vr.present;
			break;
		case GL_VR_HINT:
			*params = GL2.vr.enabled;
			break;

		default:
			gles_glGetIntegerv(pname, params);
	}
	(void) 0;
}
