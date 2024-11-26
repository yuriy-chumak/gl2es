#include <GL2/gl.h>

__attribute__((visibility("default")))
void glEnd(void)
{
	DLOG("glEnd()");

	int selected = GL2.lists_selected;
	list_t* list = List(selected);

	// special cases of transforming
	if (list->mode == GL_QUADS)
		list->mode = GL_TRIANGLES;

	if (selected == 0)
		glCallList(0);

	(void) 0;
}
