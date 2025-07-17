#include "gl2es.h"
#include <string.h>

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

#define RETURN_MATRIX(matrix) \
	__builtin_choose_expr(__builtin_types_compatible_p (typeof(*params), float_t),\
		memcpy(params, matrix, sizeof(matrix_t)),\
		({for (int p = 0; p < 16; p++) \
			params[p] = matrix[p];}))


__attribute__((visibility("default")))
void GL_FUNCTION_NAME(GLenum pname, GL_ARGUMENT_TYPE *params)
{
	DLOG(TO_STRING(GL_FUNCTION_NAME) "(0x%x, %p)", pname, params);
	if (!params) return;

	switch (pname) {
		// GL matrices
		case GL_PROJECTION_MATRIX:
			VLOG("   GL_PROJECTION_MATRIX");
			RETURN_MATRIX(GL2.gm.projection);
			break;
		case GL_MODELVIEW_MATRIX:
			VLOG("   GL_MODELVIEW_MATRIX");
			RETURN_MATRIX(GL2.gm.model_view);
			break;

		case GL_TEXTURE_MATRIX:
			VLOG("   GL_TEXTURE_MATRIX");
			GLenum i = GL2.active_texture;
			RETURN_MATRIX(GL2.gm.texture[i]);
			break;

		// VR matrices
		case VR_PROJECTION_MATRIX:
            VLOG("   VR_PROJECTION_MATRIX");
			RETURN_MATRIX(GL2.gm.projection);
			break;
		case VR_MODELVIEW_MATRIX:
            VLOG("   VR_MODELVIEW_MATRIX");
			RETURN_MATRIX(GL2.vr.view);
			break;

		// The params parameter returns four values: the red, green, blue, and alpha values of the current color.
		case GL_CURRENT_COLOR:
			params[0] = GL2.color.x;
			params[1] = GL2.color.y;
			params[2] = GL2.color.z;
			params[3] = GL2.color.w;
			break;

		// GL_ACCUM_CLEAR_VALUE 4
		// GL_COLOR_CLEAR_VALUE 4
		// GL_COLOR_WRITEMASK 4
		// GL_CURRENT_COLOR 4
		// GL_CURRENT_NORMAL 3
		// GL_CURRENT_RASTER_COLOR 4
		// GL_CURRENT_RASTER_POSITION 4
		// GL_CURRENT_RASTER_TEXTURE_COORDS 4
		// ...


		// other params
		default:
			// no default handler for glGetDoublev, 
			__builtin_choose_expr(__builtin_types_compatible_p (typeof(*params), float_t),
				esGetFloatv(pname, (GLfloat*)params), (void)0);
	}
	(void) 0;
}
