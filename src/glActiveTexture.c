#include "gl2es.h"

__attribute__((visibility("default")))
void glActiveTexture(GLenum texture)
{
	GL2.active_texture = texture - GL_TEXTURE0;
	esActiveTexture(texture);

	(void) 0;
}
