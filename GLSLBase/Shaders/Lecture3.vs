#version 450

in vec3 a_Position;

uniform float u_Time;

void main()
{
	gl_Position = vec4(u_Time * a_Position, 1);
}
