#include <GL2/gl.h>
#include <string.h>
#include <stdlib.h>

__attribute__((visibility("default")))
void glPushMatrix(void)
{
	size_t size = GL2.stack_size;
	if (GL2.stack_top == GL2.stack_size) {
		// increase the stack (by 4, we don't expect deep recursion)
		int range = 4;
		GL2.stack = realloc(GL2.stack, (size + range) * sizeof(float_t) * 16);
		GL2.stack_size = (size + range);
	}

	float_t* stack = &GL2.stack[GL2.stack_top++ * 4*4];

	switch (GL2.matrix_mode) {
		case GL_PROJECTION:
			memcpy(stack, GL2.gm.projection, sizeof(GL2.gm.projection));
			break;
		case GL_MODELVIEW:
			memcpy(stack, GL2.gm.model_view, sizeof(GL2.gm.model_view));
			break;
		case GL_TEXTURE: {
			GLenum i = GL2.active_texture;
			memcpy(stack, GL2.gm.texture[i], sizeof(GL2.gm.texture[i]));
			break;
		}
		default:
			ELOG("glPushMatrix error: Unsupported matrix mode %x", GL2.matrix_mode);
	}

	(void) 0;
}
