#include <gl2es.h>

__attribute__((visibility("default")))
void glHint(GLenum target, GLenum mode)
{
	switch (target) {
		case GL_VR: // ?
			GL2.vr.present = mode;
			break;
		case GL_VR_HINT: // TODO: move to glEnable/glDisable ?
			GL2.vr.enabled = mode;
			break;
		default:
			gles_glHint(target, mode);
			break;
	}

	(void) 0;
}
