#include "gl2es.h"

__attribute__((visibility("default")))
void glGetIntegerv(GLenum pname, GLint *params)
{
	VLOG("%p: glGetIntegerv(%04x,%p)\n", &GL2, pname, params);
	if (!params) return;

	switch (pname) {
		case GL_MATRIX_MODE:
			*params = GL2.matrix_mode;
			break;
		case GL_SHADE_MODEL:
			*params = GL2.shade_model;
			break;

		case GL_VR:
			ILOG("  GL_VR: %d\n", GL2.vr.present);
			*params = GL2.vr.present;
			break;
		case GL_VR_HINT:
			ILOG("  GL_VR_HINT: %d\n", GL2.vr.enabled);
			*params = GL2.vr.enabled;
			break;
		case GL_VBO_SIZE: {
			ILOG("  GL_VBO_SIZE\n");
			int selected = GL2.lists_selected;
			list_t* list = List(selected);
			*params = list->size * sizeof(attrib_t);
			break;
		}
		default:
			esGetIntegerv(pname, params);
	}
	(void) 0;
}
