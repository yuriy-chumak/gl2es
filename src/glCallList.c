#include "gl2es.h"

#include <assert.h>
#include <matrix.h>

// TODO: override glGetAttribLocation, change "gl_" prefix to predefined "g2_", etc.

__attribute__((visibility("default")))
void glCallList(GLuint id)
{
	VLOG("glCallList(%d)\n", id);
	// assert (GL2.current_list == 0)
	list_t* list = List(id);

	// shader program
	GLint saved, program = 0;
	esGetIntegerv(GL_CURRENT_PROGRAM, &program); // or just glGetIntegerv ?
	saved = program;

	// texturing
	GLint texture0 = 0;
	esGetIntegerv(GL_TEXTURE_BINDING_2D, &texture0);

	// use default program if no exists one
	// use different programs in different situations (vct if has active texture)
	if (program == 0) {
		VLOG("use our own program\n");
		if (texture0 == 0)
			program = glUsePredefinedProgram(PP_VERTEX_COLOR);
		else
		if (texture0 > 0) // todo: more programs for more than 1 texture
			program = glUsePredefinedProgram(PP_VERTEX_COLOR_TEXTURE0);
		else // default simplest program
			program = glUsePredefinedProgram(PP_VERTEX_COLOR);
	}
	VLOG("  use program = %d\n", program);
	VLOG("  list->count = %zu, list->count * sizeof(attrib_t) = %zu\n", list->count, list->count * sizeof(attrib_t));

	// Attributes
	glBindBuffer(GL_ARRAY_BUFFER, list->vbo);
	glBufferData(GL_ARRAY_BUFFER, list->count * sizeof(attrib_t), list->attribs, GL_STATIC_DRAW);

#define ATTRIBUTE(name, field) {\
	GLint attribute = glGetAttribLocation(program, name);\
	VLOG(name " = %d\n", attribute);\
	if (attribute != -1) {\
		esEnableVertexAttribArray(attribute);\
		esVertexAttribPointer(attribute,\
				sizeof(list->attribs[0].field)/sizeof(float_t),\
				GL_FLOAT, GL_FALSE, sizeof(attrib_t),\
				(void*)offsetof(attrib_t, field));\
	}}
	ATTRIBUTE("g2_Vertex", vertex)
	ATTRIBUTE("g2_Color", color)
	ATTRIBUTE("g2_SecondaryColor", color2)
	ATTRIBUTE("g2_Normal", normal)
	ATTRIBUTE("g2_MultiTexCoord0", texcoord[0])
	// ATTRIBUTE("g2_MultiTexCoord1", texcoord[1])
	// ATTRIBUTE("g2_MultiTexCoord2", texcoord[2])
	// ATTRIBUTE("g2_MultiTexCoord3", texcoord[3])
	// ATTRIBUTE("g2_MultiTexCoord4", texcoord[4])
	// ATTRIBUTE("g2_MultiTexCoord5", texcoord[5])
	// ATTRIBUTE("g2_MultiTexCoord6", texcoord[6])
	// ATTRIBUTE("g2_MultiTexCoord7", texcoord[7])
	ATTRIBUTE("g2_FogCoord", fogcoord)
#undef ATTRIBUTE

	// Uniforms
	GLint loc = -1;
	// todo: upload when program changed and matrix changed, not the every time
	loc = glGetUniformLocation(program, "g2_ModelViewMatrix");
	VLOG("g2_ModelViewMatrix = %d\n", loc);
	if (loc != -1) {
		// in case of VR we should multiply modelview matrices
	// 	if (GL2.vr.enabled) {
	// 		float_t model_view[16];
	// 		matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
	// 		esUniformMatrix4fv(loc, 1, GL_FALSE, model_view);
	// 	}
	// 	else
			esUniformMatrix4fv(loc, 1, GL_FALSE, GL2.gm.model_view);
	}

	loc = glGetUniformLocation(program, "g2_ModelViewProjectionMatrix");
	VLOG("g2_ModelViewProjectionMatrix = %d", loc);
	if (loc != -1) {
		float_t mvp[16];
	// 	if (GL2.vr.enabled) {
	// 		float_t model_view[16];
	// 		matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
	// 		matrix_mul_matrix(GL2.vr.projection, model_view, mvp);
	// 	}
	// 	else
			matrix_mul_matrix(GL2.gm.projection, GL2.gm.model_view, mvp);
		VLOG("   %f %f %f %f\n", mvp[0], mvp[4], mvp[8], mvp[12]);
		VLOG("   %f %f %f %f\n", mvp[1], mvp[5], mvp[9], mvp[13]);
		VLOG("   %f %f %f %f\n", mvp[2], mvp[6], mvp[10],mvp[14]);
		VLOG("   %f %f %f %f\n", mvp[3], mvp[7], mvp[11],mvp[15]);
		esUniformMatrix4fv(loc, 1, GL_FALSE, mvp);
	}

	// loc = glGetUniformLocation(program, "g2_ProjectionMatrix");
	// VLOG("g2_ProjectionMatrix = %d", loc);
	// if (loc != -1) {
	// 	// use either projection or vr projection matrix
	// 	if (GL2.vr.enabled)
	// 		esUniformMatrix4fv(loc, 1, GL_FALSE, GL2.vr.projection);
	// 	else
	// 		esUniformMatrix4fv(loc, 1, GL_FALSE, GL2.gm.projection);
	// }

	// loc = glGetUniformLocation(program, "g2_TextureMatrix");
	// VLOG("g2_TextureMatrix = %d", loc);
	// if (loc != -1) {
	// 	GLsizei count = sizeof(GL2.gm.texture)/sizeof(GL2.gm.texture[0]);
	// 	esUniformMatrix4fv(loc, count, GL_FALSE,
	// 		(GLfloat*)GL2.gm.texture);
	// }

	// // https://web.archive.org/web/20140205124406/http://www.arcsynthesis.org/gltut/Illumination/Tut09%20Normal%20Transformation.html
	// // gl_NormalMatrix нужна только при неконформных преобразованиях (glScale с разными аргументами)
	// loc = glGetUniformLocation(program, "g2_NormalMatrix");
	// VLOG("g2_NormalMatrix = %d", loc);
	// if (loc != -1) {
	// 	float_t nm[16];
	// 	if (GL2.vr.enabled) {
	// 		float_t model_view[16];
	// 		matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
	// 		matrix_inverse3_transpose(model_view, nm);
	// 	}
	// 	else
	// 		matrix_inverse3_transpose(GL2.gm.model_view, nm);
	// 	esUniformMatrix4fv(loc, 1, GL_FALSE, nm);
	// }

	// // GLint loc = glGetUniformLocation(program, "g2_LightSource[0].position");
	// // if (loc != -1) {
	// // 	esUniform4fv(loc, 1, &GL2.lights[0].position);
	// // }

	// loc = glGetUniformLocation(program, "tex0");
	// if (loc != -1) {
	// 	esUniform1f(loc, 0);
	// }


	// ... others, others, others...
	// TODO: Quads
	assert (list->mode == GL_POINTS ||
			list->mode == GL_LINE_STRIP     || list->mode == GL_LINE_LOOP    || list->mode == GL_LINES ||
			list->mode == GL_TRIANGLE_STRIP || list->mode == GL_TRIANGLE_FAN || list->mode == GL_TRIANGLES);
	glDrawArrays(list->mode, 0, list->count);

	// restore original data
	glUseProgram(saved);
	
	(void) 0;
}