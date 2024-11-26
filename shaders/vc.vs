#version 100
precision mediump float;

attribute vec4 g2_Vertex;
attribute vec4 g2_Color;

uniform mat4 g2_ModelViewProjectionMatrix;

varying vec4 color;
void main() {
	gl_Position = g2_ModelViewProjectionMatrix * g2_Vertex;
	color = g2_Color;
}
