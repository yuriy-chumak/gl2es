#include <gl2es.h>
#include <string.h>
#include <stdlib.h>

__attribute__((visibility("default")))
void glPopMatrix(void)
{
	if (GL2.stack_top == 0)
		return;
	float_t* stack = &GL2.stack[--GL2.stack_top * 4*4];

	switch (GL2.matrix_mode) {
		case GL_PROJECTION:
			memcpy(GL2.gm.projection, stack, sizeof(GL2.gm.projection));
			break;
		case GL_MODELVIEW:
			memcpy(GL2.gm.model_view, stack, sizeof(GL2.gm.model_view));
			break;
		case GL_TEXTURE: {
			GLenum i = GL2.active_texture;
			memcpy(GL2.gm.texture[i], stack, sizeof(GL2.gm.texture[i]));
			break;
		}
		default:
			ELOG("Unsupported matrix mode");
	}

	(void) 0;
}
