#include <GL2/gl.h>
#include <stdlib.h>

#include <lists.h>

#define DEFAULT_COUNT 4

__attribute__((visibility("default")))
GLuint glGenLists(GLsizei range)
{
	ILOG("glGenLists(%d)", range);

	size_t count = GL2.lists_count;
	GL2.lists = realloc(GL2.lists, (count + range) * sizeof(list_t));
	GL2.lists_count = (count + range);

	for (int i = count; i < count + range; i++) {
		list_t* list = List(i);
		list->size = DEFAULT_COUNT;
		list->count = 0;
		list->attribs = malloc(list->size * sizeof(attrib_t));
	}
	return count;
}

// notes: current limitation, no mixed vertices (I mean triangles and points)
