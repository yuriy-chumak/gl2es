#include "gl2es.h"

#include <string.h>
#include <matrix.h>

static
void glLoadMatrix(float_t* m)
{
	DLOG("glLoadMatrix(%f, %f, %f, %f)", m[0], m[1], m[2], m[3]);
	DLOG("glLoadMatrix(%f, %f, %f, %f)", m[4], m[5], m[6], m[7]);
	DLOG("glLoadMatrix(%f, %f, %f, %f)", m[8], m[9], m[10], m[11]);
	DLOG("glLoadMatrix(%f, %f, %f, %f)", m[12], m[13], m[14], m[15]);
	switch (GL2.matrix_mode) {
		case GL_PROJECTION:
	                DLOG("   GL_PROJECTION");
			memcpy(GL2.gm.projection, m, sizeof(matrix_t));
			break;
		case GL_MODELVIEW:
	                DLOG("   GL_MODELVIEW");
			memcpy(GL2.gm.model_view, m, sizeof(matrix_t));
			break;
		case VR_PROJECTION:
	                DLOG("   VR_PROJECTION");
			memcpy(GL2.vr.projection, m, sizeof(matrix_t));
			break;
		case VR_MODELVIEW:
	                DLOG("   VR_MODELVIEW");
			memcpy(GL2.vr.view, m, sizeof(matrix_t));
			break;
		case GL_TEXTURE: {
	                DLOG("   GL_TEXTURE");
			GLenum i = GL2.active_texture;
			memcpy(GL2.gm.texture[i], m, sizeof(matrix_t));
			break;
		}
		default:
			ELOG("glLoadMatrix error: Unsupported matrix mode %x", GL2.matrix_mode);
	}

	(void) 0;
}

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glLoadMatrixf(const GLfloat* m)
{
	float_t matrix[16] = {
		(float_t)m[ 0], (float_t)m[ 1], (float_t)m[ 2], (float_t)m[ 3],
		(float_t)m[ 4], (float_t)m[ 5], (float_t)m[ 6], (float_t)m[ 7],
		(float_t)m[ 8], (float_t)m[ 9], (float_t)m[10], (float_t)m[11],
		(float_t)m[12], (float_t)m[13], (float_t)m[14], (float_t)m[15]
	};
	(void) glLoadMatrix(matrix);
}

__attribute__((visibility("default")))
void glLoadMatrixd(const GLdouble* m)
{
	float_t matrix[16] = {
		(float_t)m[ 0], (float_t)m[ 1], (float_t)m[ 2], (float_t)m[ 3],
		(float_t)m[ 4], (float_t)m[ 5], (float_t)m[ 6], (float_t)m[ 7],
		(float_t)m[ 8], (float_t)m[ 9], (float_t)m[10], (float_t)m[11],
		(float_t)m[12], (float_t)m[13], (float_t)m[14], (float_t)m[15]
	};
	(void) glLoadMatrix(matrix);
}
