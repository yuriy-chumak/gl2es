#include <gl2es.h>

#include <assert.h>
#include <matrix.h>

__attribute__((visibility("default")))
void glCallList(GLuint id)
{
	list_t* list = List(id);

	GLint program = 0;
	gles_glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	// Attributes
#define ATTRIBUTE(name, field) {\
	GLint attribute = glGetAttribLocation(program, name);\
	if (attribute != -1) {\
		gles_glVertexAttribPointer(attribute,\
				sizeof(list->attribs[0].field)/sizeof(float_t),\
				GL_FLOAT, GL_FALSE, sizeof(attrib_t),\
				&list->attribs[0].field);\
		gles_glEnableVertexAttribArray(attribute);\
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
	// todo: upload when program changed and matrix changed, not every time
	loc = glGetUniformLocation(program, "g2_ModelViewMatrix");
	if (loc != -1) {
		// in case of VR we should multiply modelview matrices
		if (GL2.vr.enabled) {
			float_t model_view[16];
			matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
			gles_glUniformMatrix4fv(loc, 1, GL_FALSE, model_view);
		}
		else
			gles_glUniformMatrix4fv(loc, 1, GL_FALSE, GL2.gm.model_view);
	}

	loc = glGetUniformLocation(program, "g2_ModelViewProjectionMatrix");
	if (loc != -1) {
		float_t mvp[16];
		if (GL2.vr.enabled) {
			float_t model_view[16];
			matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
			matrix_mul_matrix(GL2.vr.projection, model_view, mvp);
		}
		else
			matrix_mul_matrix(GL2.gm.projection, GL2.gm.model_view, mvp);
		gles_glUniformMatrix4fv(loc, 1, GL_FALSE, mvp);
	}

	loc = glGetUniformLocation(program, "g2_ProjectionMatrix");
	if (loc != -1) {
		// use either projection or vr projection matrix
		if (GL2.vr.enabled)
			gles_glUniformMatrix4fv(loc, 1, GL_FALSE, GL2.vr.projection);
		else
			gles_glUniformMatrix4fv(loc, 1, GL_FALSE, GL2.gm.projection);
	}

	loc = glGetUniformLocation(program, "g2_TextureMatrix");
	if (loc != -1) {
		GLsizei count = sizeof(GL2.gm.texture)/sizeof(GL2.gm.texture[0]);
		gles_glUniformMatrix4fv(loc, count, GL_FALSE,
			(GLfloat*)GL2.gm.texture);
	}

	// https://web.archive.org/web/20140205124406/http://www.arcsynthesis.org/gltut/Illumination/Tut09%20Normal%20Transformation.html
	// gl_NormalMatrix ?????????? ???????????? ?????? ???????????????????????? ?????????????????????????????? (glScale ?? ?????????????? ??????????????????????)
	loc = glGetUniformLocation(program, "g2_NormalMatrix");
	if (loc != -1) {
		float_t nm[16];
		if (GL2.vr.enabled) {
			float_t model_view[16];
			matrix_mul_matrix(GL2.vr.view, GL2.gm.model_view, model_view);
			matrix_inverse3_transpose(model_view, nm);
		}
		else
			matrix_inverse3_transpose(GL2.gm.model_view, nm);
		gles_glUniformMatrix4fv(loc, 1, GL_FALSE, nm);
	}

	// GLint loc = glGetUniformLocation(program, "g2_LightSource[0].position");
	// if (loc != -1) {
	// 	gles_glUniform4fv(loc, 1, &GL2.lights[0].position);
	// }

	// ... others, others, others...
	// TODO: Quads
	assert (GL2.begin_mode == GL_POINTS ||
			GL2.begin_mode == GL_LINE_STRIP || GL2.begin_mode == GL_LINE_LOOP || GL2.begin_mode == GL_LINES ||
			GL2.begin_mode == GL_TRIANGLE_STRIP || GL2.begin_mode == GL_TRIANGLE_FAN || GL2.begin_mode == GL_TRIANGLES);
	glDrawArrays(list->mode, 0, list->count);

	(void) 0;
}