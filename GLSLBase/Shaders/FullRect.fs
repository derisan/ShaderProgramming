#version 450

out vec4 FragColor;

in vec2 v_TexCoord;

uniform float u_Time;

const float PI = 3.141592;

void main()
{
	float sinValue = sin(v_TexCoord.x * 2 * PI + u_Time);

	if(v_TexCoord.y * 2 - 1 < sinValue && v_TexCoord.y * 2 - 1 > sinValue - 0.01)
		FragColor = vec4(1);
	else
		FragColor = vec4(0);
}
