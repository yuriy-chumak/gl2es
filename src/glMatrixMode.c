#include <gl2es.h>

__attribute__((visibility("default")))
void glMatrixMode(GLenum mode)
{
	GL2.matrix_mode = mode;

	(void) 0;
}
