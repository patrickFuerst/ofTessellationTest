#version 400 core

#define POSITION		0
#define COLOR			1
#define NORMAL			2
#define TEXCOORD		3

precision highp float;
precision highp int;
layout(std140, column_major) uniform;

uniform mat4 MVP;

layout(location = POSITION) in vec3 Position;
layout(location = COLOR) in vec4 Color;
layout(location = NORMAL) in vec3 Normal;


out vertex
{
    vec4 Color;
    vec3 Normal;
    vec3 TexCoord;
}Out;



void main()
{	
	gl_Position = MVP * vec4(Position,  1.0);
	Out.Color = vec4(Normal,1.0);
	Out.Normal = Normal;
}
