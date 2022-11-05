#include <gl2es.h>

#include <matrix.h>
#include <math.h>

static
void glLight(GLenum light, GLenum pname, float_t *param)
{
	switch (pname) {
		case GL_POSITION: {
			float_t matrix[16];
			if (GL2.vr.enabled)
				matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, matrix);
			matrix_mul_vector(
				GL2.vr.enabled ? matrix : GL2.gm.model_view,
				param,
				(float*)&GL2.lights[light - GL_LIGHT0].position);
			break;
		}
		default:
			ELOG("Unsupported glLight param");
	}

	(void) 0;
}

// GLAPI void GLAPIENTRY glLighti( GLenum light, GLenum pname, GLint param );
GLAPI void GLAPIENTRY glLightfv( GLenum light, GLenum pname,
                                 const GLfloat *params );
// GLAPI void GLAPIENTRY glLightiv( GLenum light, GLenum pname,
//                                  const GLint *params );

// -=( OpenGL )=--------------------

__attribute__((visibility("default")))
void glLightf(GLenum light, GLenum pname, GLfloat param)
{
	float_t p = (float_t)param;
	glLight(light, pname, &p);
}
__attribute__((visibility("default")))
void glLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
	switch (pname) {
		case GL_POSITION: {
			float_t p[4] = {(float_t)params[0],
							(float_t)params[1],
							(float_t)params[2],
							(float_t)params[3]};
			glLight(light, pname, p);
			break;
		default:
			ELOG("Unsupported glLight param");
		}
	}
}
