#include "gl2es.h"
#include <limits.h>

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

		// The params parameter returns four values: the red, green, blue, and alpha values of the current color.
		// Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value.
		case GL_CURRENT_COLOR:
			params[0] = GL2.color.x * INT_MAX;
			params[1] = GL2.color.y * INT_MAX;
			params[2] = GL2.color.z * INT_MAX;
			params[3] = GL2.color.w * INT_MAX;
			break;

		// custom params
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
