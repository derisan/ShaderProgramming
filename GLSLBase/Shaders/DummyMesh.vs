#version 450

in vec3 a_Position;

const float PI = 3.14159;

out vec4 v_Color;

void main()
{
	vec3 newPos = a_Position;
	newPos.y += 0.5 * sin((a_Position.x + 0.5) * 2 * PI);
	gl_Position = vec4(newPos, 1);

	v_Color = vec4((sin((a_Position.x + 0.5) * 2 * PI) + 1) / 2);
}
