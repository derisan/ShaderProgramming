#version 450

in vec3 a_Position;
in vec4 a_Color;

uniform float u_Time;

out vec4 v_Color;

void main()
{
	gl_Position = vec4(u_Time * a_Position, 1);
	v_Color = a_Color;
}
