#version 100
precision mediump float;

#ifdef __VERTEX_SHADER__
// vertex shader
attribute vec4 g2_Vertex;
attribute vec4 g2_Color;

uniform mat4 g2_ModelViewProjectionMatrix;

varying vec4 color;
void main() {
	gl_Position = g2_ModelViewProjectionMatrix * g2_Vertex;
	color = g2_Color;
}
#endif

#ifdef __FRAGMENT_SHADER__
// fragment shader
varying vec4 color;
void main(void) {
	gl_FragColor = color;
}
#endif
