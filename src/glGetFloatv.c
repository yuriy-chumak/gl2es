#include <GL2/gl.h>

__attribute__((visibility("default")))
void glGetFloatv(GLenum pname, GLfloat *params)
{
	DLOG("glGetFloatv(0x%x, %p)", pname, params);
	if (!params) return;

	switch (pname) {
		// GL matrices
		case GL_PROJECTION_MATRIX:
			VLOG("   GL_PROJECTION_MATRIX");
			memcpy(params, GL2.gm.projection, sizeof(matrix_t));
			break;
		case GL_MODELVIEW_MATRIX:
			VLOG("   GL_MODELVIEW_MATRIX");
			memcpy(params, GL2.gm.model_view, sizeof(matrix_t));
			break;

		case GL_TEXTURE_MATRIX:
			VLOG("   GL_TEXTURE_MATRIX");
			GLenum i = GL2.active_texture;
			memcpy(params, GL2.gm.texture[i], sizeof(matrix_t));
			break;

		// VR matrices
		case VR_PROJECTION_MATRIX:
            VLOG("   VR_PROJECTION_MATRIX");
			memcpy(params, GL2.vr.projection, sizeof(matrix_t));
			break;
		case VR_MODELVIEW_MATRIX:
            VLOG("   VR_MODELVIEW_MATRIX");
			memcpy(params, GL2.vr.view, sizeof(matrix_t));
			break;

		default:
			gles_glGetFloatv(pname, params);
	}
	(void) 0;
}
