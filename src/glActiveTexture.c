#include <gl2es.h>

__attribute__((visibility("default")))
void glActiveTexture(GLenum texture)
{
	GL2.active_texture = texture - GL_TEXTURE0;
	gles_glActiveTexture(texture);

	(void) 0;
}
