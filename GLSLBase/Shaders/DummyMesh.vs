#version 450

in vec3 a_Position;

const float PI = 3.14159;

out vec4 v_Color;

uniform float u_Time;

void main()
{
	vec3 newPos = a_Position;
	float xDis = a_Position.x + 0.5;
	newPos.y += xDis * 0.5 * sin((a_Position.x + 0.5) * 2 * PI - u_Time);
	gl_Position = vec4(newPos, 1);

	v_Color = vec4((sin((a_Position.x + 0.5) * 2 * PI - u_Time) + 1) / 2);
}
