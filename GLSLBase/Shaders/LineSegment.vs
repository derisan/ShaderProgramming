#version 450

in vec3 a_Position;

uniform float u_Time;

const float PI = 3.141592;

void main()
{
	float newStart = a_Position.x + 1.0; // 0 ~ 2;
	vec4 newPos = vec4(a_Position.x, sin(u_Time + PI * newStart), a_Position.z, 1);
	gl_Position = newPos;
}
