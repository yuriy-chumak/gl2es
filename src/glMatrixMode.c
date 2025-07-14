#include "gl2es.h"

__attribute__((visibility("default")))
void glMatrixMode(GLenum mode)
{
	VLOG("%p: glMatrixMode(%04x), %04x -> %04x", &GL2, mode, GL2.matrix_mode, mode);
	GL2.matrix_mode = mode;

	(void) 0;
}
