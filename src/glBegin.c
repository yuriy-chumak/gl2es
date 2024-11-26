#include <GL2/gl.h>

__attribute__((visibility("default")))
void glBegin(GLenum mode)
{
	DLOG("glBegin(%04x)", mode);
	int selected = GL2.lists_selected;
	list_t* list = List(selected);
	list->mode = mode;

	// текущий список не компилируемый, поэтому перезапускаем на каждый glBegin
	if (selected == 0) {
		list->count = 0;
	}

	(void) 0;
}