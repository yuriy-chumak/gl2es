#include <GL2/gl.h>

#include <stdlib.h>
#include <assert.h>

#include <lists.h>

__attribute__((visibility("default")))
void glEndList(void)
{
	assert (GL2.lists_selected != 0);

	// free the space after end of real list size
	list_t* list = List(GL2.lists_selected);
	size_t count = list->count;
	list->attribs = realloc(list->attribs, count * sizeof(attrib_t));
	list->size = count;
	VLOG("glEndList(GL2.lists_selected): Generated %zu vertices", count);

	if (GL2.lists_mode == GL_COMPILE_AND_EXECUTE)
		glCallList(GL2.lists_selected);

	GL2.lists_mode = 0;
	GL2.lists_selected = 0;
}
