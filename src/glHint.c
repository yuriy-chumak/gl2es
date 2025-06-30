#include "gl2es.h"

__attribute__((visibility("default")))
void glHint(GLenum target, GLenum mode)
{
	ILOG("%p: glHint(%x, %d)", &GL2, target, mode);
	switch (target) {
		case GL_VR: // ?
			GL2.vr.present = mode;
			ILOG("  GL_VR: %d", GL2.vr.present);
			break;
		case GL_VR_HINT: // TODO: move to glEnable/glDisable ?
			GL2.vr.enabled = mode;
			ILOG("  GL_VR_HINT: %d", GL2.vr.enabled);
			break;
		default:
			esHint(target, mode);
			break;
	}

	(void) 0;
}
