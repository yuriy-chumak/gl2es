#include "gl2es.h"


#include "re.h"
// TODO: precompile regexes
int contain(char* regex, char** sources, int s_count)
{
	int len = 0;
	re_t pattern = re_compile(regex);
	for (int i = 0; i < s_count; i++) {
		if (re_matchp(pattern, sources[i], &len) != -1)
			return 1;
	}
	return 0;
}

// preconfigured gl2es shader options and defines
char* setup[] = {
	"#define GL2ES 1\n"
	"precision highp float;"
	"\n"
};

// 
struct auoi_t {
	char* regex;
	char* string;
} auois[] = {
	// attributes
	{ "gl_Vertex", "attribute vec4 g2_Vertex;" },
	{ "gl_Color",  "attribute vec4 g2_Color;"  },
	{ "gl_SecondaryColor", "attribute vec4 g2_SecondaryColor;" },
	{ "gl_Normal", "attribute vec3 g2_Normal;" },
	{ "gl_MultiTexCoord0", "attribute vec4 g2_MultiTexCoord0;" },
    //   ;;          ;; (if (m/gl_MultiTexCoord1/ shader) "attribute vec4 g2_MultiTexCoord1;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord2/ shader) "attribute vec4 g2_MultiTexCoord2;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord3/ shader) "attribute vec4 g2_MultiTexCoord3;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord4/ shader) "attribute vec4 g2_MultiTexCoord4;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord5/ shader) "attribute vec4 g2_MultiTexCoord5;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord6/ shader) "attribute vec4 g2_MultiTexCoord6;" "")
    //   ;;          ;; (if (m/gl_MultiTexCoord7/ shader) "attribute vec4 g2_MultiTexCoord7;" "")

	// uniforms
	{ "gl_ModelViewMatrix",           "uniform mat4 g2_ModelViewMatrix;" },
	{ "gl_ModelViewProjectionMatrix", "uniform mat4 g2_ModelViewProjectionMatrix;" },
	{ "gl_ProjectionMatrix",          "uniform mat4 g2_ProjectionMatrix;" },
	{ "gl_TextureMatrix",             "uniform mat4 g2_TextureMatrix[8];" },
	// todo: ...Inverse, ...Transpose; ...InverseTranspose
	{ "gl_NormalMatrix",              "uniform mat4 g2_NormalMatrix;" },
    //   ;;          ;; todo: (if (m/gl_LightSource/ shader) "struct g2_LightSourceParameters {
    //   ;;          ;;    // ...
    //   ;;          ;;    vec4 position;
    //   ;;          ;;    // ...
    //   ;;          ;; };
    //   ;;          ;; uniform g2_LightSourceParameters g2_LightSource[2];" "")

	// varyings (output/input)
	{ "gl_FrontColor", "varying vec4 g2_FrontColor;" },
	{ "gl_BackColor", "varying vec4 g2_BackColor;" },
	{ "gl_FrontSecondaryColor", "varying vec4 g2_FrontSecondaryColor;" },
	{ "gl_TexCoord", "varying vec4 g2_TexCoord[1];" }, // 1, not 8 (?)
	{ "gl_FogFragCoord", "varying vec4 g2_FogFragCoord;" },
};

__attribute__((visibility("default")))
void glShaderSource(GLuint shader, GLsizei s_count, const GLchar * const * strings, const GLint * length)
{
	ILOG("glShaderSource(%d, %d, %p, %p)\n", shader, s_count, strings, length);

	GLint shader_type = 0;
	glGetShaderiv(shader, GL_SHADER_TYPE, &shader_type);

	size_t count = 3 // 1 for "#version", 1 for geometry extension, 1 for "#define" shader type
		+ sizeof(setup) / sizeof(*setup)
		+ sizeof(auois) / sizeof(*auois)
		+ s_count;

	GLchar* sources[count];
	GLchar** out = sources;

    // 1. #version must occur before any other statement in the program
    // (if (m/#version +120/ shader) "#version 100\n" "")
	*out++ =
		contain("#version +120", strings, s_count) ? "#version 100\n" :
		// todo: add another supported version
		"\n";

	// 2.1. required extensions
	*out++ =
		shader_type == GL_GEOMETRY_SHADER ? "#extension GL_EXT_geometry_shader: enable\n" : "\n";

    // 2.2. #define shader type (to be used in user shaders)
	*out++ =
		shader_type ==   GL_VERTEX_SHADER ? "#define VERTEX_SHADER\n" :
		shader_type == GL_GEOMETRY_SHADER ? "#define GEOMETRY_SHADER\n" :
		shader_type == GL_FRAGMENT_SHADER ? "#define FRAGMENT_SHADER\n" :
		"\n";

	// 3. setup shader defines and default options
	for (int i = 0; i < sizeof(setup) / sizeof(setup[0]); i++)
		*out++ = setup[i];

	// 4. attributes, uniforms, output...
	for (int i = 0; i < sizeof(auois) / sizeof(*auois); i++) {
		*out++ = contain(auois[i].regex, strings, s_count) ? auois[i].string : "\n";
	};

	// * Rename all gl_Xxx to g2_Xxx except GLES legal ones
	//	 (moved from Lisp to C as native code optimization)
	for (int i = 0; i < s_count; i++) {
		int len = length ? length[i] : strlen(strings[i]) + 1;
		out[i] = alloca(len); memcpy(out[i], strings[i], len);

		char* start = out[i];
		char* end = start + len;
		for (char* p = start; p < end; p++) {
			if (p[0] == 'g' && p[1] == 'l' && p[2] == '_') {
				// gl_Po(sition|intSize|intCoord)
				if (p[3] == 'P' && p[4] == 'o') {
					// gl_Pos(ition)
					if (p[5] == 's') {
						p += 5; continue;
					}
					// gl_PointS(ize)
					if (p[5] == 'i' && p[6] == 'n' && p[7] == 't' && p[8] == 'S') {
						p += 8; continue;
					}
					// gl_PointC(oord)
					if (p[5] == 'i' && p[6] == 'n' && p[7] == 't' && p[8] == 'C') {
						p += 8; continue;
					}
				}
				// gl_Fra(...)
				if (p[3] == 'F' && p[4] == 'r' && p[5] == 'a') {
					p += 3; continue; // todo: p += 5;
				}
				// gl_D(...)
				if (p[3] == 'D') {
					p += 3; continue;
				}

				// nothing found, so rename
				p[1] = '2'; p += 3; continue;
			}
			if (p[0] == '#' && p[1] == 'v' && p[2] == 'e' && p[3] == 'r') { // todo: add "sion"
				p[0] = '/', p[1] = '/'; p += 3; continue;
			}
		}
	}

	for (int i = 0; i < count; i++)
		VLOG("%d: %s", i, sources[i]);

	// GLint* n_length[length ? count : 1];
	// if (length) {
	// 	GLint* len = n_length;
	// 	for (int i = 0; i < count - s_count; i++)
	// 		*len++ = -1;
	// 	for (int i = 0; i < s_count; i++)
	// 		*len++ = length[i];
	// }

	// (void) esShaderSource(shader, count, sources, length ? n_length : NULL);
	(void) esShaderSource(shader, count, sources, NULL);
	return;
}

// TODO: add glHint() for "precision mediump float;", for example