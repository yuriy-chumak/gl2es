#include <GL2/gl.h>
#include <string.h>

matrix_t identity = {
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
};

__attribute__((visibility("default")))
void glLoadIdentity(void)
{
	DLOG("%p: glLoadIdentity(), matrix_mode = %04x", &GL2, GL2.matrix_mode);
	switch (GL2.matrix_mode) {
		case GL_PROJECTION:
			memcpy(GL2.gm.projection, identity, sizeof(matrix_t));
			break;
		case GL_MODELVIEW:
			memcpy(GL2.gm.model_view, identity, sizeof(matrix_t));
			break;
		case VR_PROJECTION:
			memcpy(GL2.vr.projection, identity, sizeof(matrix_t));
			break;
		case VR_MODELVIEW:
			memcpy(GL2.vr.view, identity, sizeof(matrix_t));
			break;
		case GL_TEXTURE: {
			GLenum i = GL2.active_texture;
			memcpy(GL2.gm.texture[i], identity, sizeof(matrix_t));
			break;
		}
		default:
			ELOG("glLoadIdentity error: Unsupported matrix mode %x", GL2.matrix_mode);
	}

	(void) 0;
}
