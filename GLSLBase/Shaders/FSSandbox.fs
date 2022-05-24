#version 450

in vec4 v_Color;

out vec4 FragColor;

void main()
{
	float dist = distance(v_Color.xy, vec2(0.5)); // 텍스쳐 좌표의 중앙
	vec4 newColor = vec4(0);

	if(dist < 0.5)
		newColor = vec4(1);
	else
		newColor = vec4(0);

	FragColor = newColor;
}
