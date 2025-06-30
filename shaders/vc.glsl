// Just a color Shader
varying vec4 color;

// -=( vertex shader )=--------------------------
#ifdef VERTEX_SHADER

attribute vec4 g2_Vertex;
attribute vec4 g2_Color;

uniform mat4 g2_ModelViewProjectionMatrix;
//uniform mat4 g2_ModelViewMatrix;

void main() {
	//gl_Position = g2_Vertex;
	//gl_Position = g2_ModelViewMatrix * g2_Vertex;
	gl_Position = g2_ModelViewProjectionMatrix * g2_Vertex;

	// output color:
	color = g2_Color;
}
#endif

// -=( fragment shader )=------------------------
#ifdef FRAGMENT_SHADER

void main(void) {
	gl_FragColor = color;
}
#endif
