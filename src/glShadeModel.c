#include "gl2es.h"

__attribute__((visibility("default")))
void glShadeModel(GLenum mode)
{
	VLOG("glShadeModel(%04x)\n", mode);
	GL2.shade_model = mode;

	(void) 0;
}