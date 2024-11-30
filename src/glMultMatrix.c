#include <GL2/gl.h>

#include <matrix.h>

static
void glMultMatrix(float_t* m)
{
	DLOG("glMultMatrix(%p), matrix_mode = %04x", m, GL2.matrix_mode);
	switch (GL2.matrix_mode) {
		case GL_PROJECTION:
			matrix_mul_matrix(GL2.gm.projection, m, GL2.gm.projection);
			break;
		case GL_MODELVIEW:
			matrix_mul_matrix(GL2.gm.model_view, m, GL2.gm.model_view);
			break;
		case VR_PROJECTION:
			matrix_mul_matrix(GL2.vr.projection, m, GL2.vr.projection);
			break;
		case VR_MODELVIEW:
			matrix_mul_matrix(GL2.vr.view, m, GL2.vr.view);
			break;
		case GL_TEXTURE: {
			GLenum i = GL2.active_texture;
			matrix_mul_matrix(GL2.gm.texture[i], m, GL2.gm.texture[i]);
			break;
		}
		default:
			ELOG("glMultMatrix error: Unsupported matrix mode %x", GL2.matrix_mode);
	}

	(void) 0;
}

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glMultMatrixf(const GLfloat* m)
{
	float_t matrix[16] = {
		(float_t)m[ 0], (float_t)m[ 1], (float_t)m[ 2], (float_t)m[ 3],
		(float_t)m[ 4], (float_t)m[ 5], (float_t)m[ 6], (float_t)m[ 7],
		(float_t)m[ 8], (float_t)m[ 9], (float_t)m[10], (float_t)m[11],
		(float_t)m[12], (float_t)m[13], (float_t)m[14], (float_t)m[15]
	};
	(void) glMultMatrix(matrix);
}

__attribute__((visibility("default")))
void glMultMatrixd(const GLdouble* m)
{
	float_t matrix[16] = {
		(float_t)m[ 0], (float_t)m[ 1], (float_t)m[ 2], (float_t)m[ 3],
		(float_t)m[ 4], (float_t)m[ 5], (float_t)m[ 6], (float_t)m[ 7],
		(float_t)m[ 8], (float_t)m[ 9], (float_t)m[10], (float_t)m[11],
		(float_t)m[12], (float_t)m[13], (float_t)m[14], (float_t)m[15]
	};
	(void) glMultMatrix(matrix);
}
