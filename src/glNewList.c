#include <GL2/gl.h>
#include <lists.h>

__attribute__((visibility("default")))
void glNewList(GLuint id, GLenum mode)
{
	GL2.lists_mode = mode;
	GL2.lists_selected = id;

	list_t* list = List(id);
	list->count = 0;
}
