#version 100
precision mediump float;

#ifdef __VERTEX_SHADER__
// vertex shader
attribute vec4 g2_Vertex;
attribute vec4 g2_Color;
attribute vec4 g2_MultiTexCoord0;

uniform mat4 g2_ModelViewProjectionMatrix;

varying vec4 color;
varying vec4 texcoord0;
void main() {
	gl_Position = g2_ModelViewProjectionMatrix * g2_Vertex;
	color = g2_Color;
	texcoord0 = g2_MultiTexCoord0;
}
#endif

#ifdef __FRAGMENT_SHADER__
// fragment shader
varying vec4 color;
varying vec4 texcoord0;

uniform sampler2D tex0;
void main(void) {
	//gl_FragColor = vec4(texcoord0.s, texcoord0.t, 0, 1); //texture2D(tex0, texcoord0.st);
	gl_FragColor = texture2D(tex0, texcoord0.st);
}
#endif
