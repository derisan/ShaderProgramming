#version 450

in vec4 v_Color;
in vec2 v_TexCoord;

out vec4 FragColor;

void main()
{
	float dis = distance(vec2(0), v_TexCoord);

	if(dis < 0.05) // ��ƼŬ�� �� ���� ���̴� 0.1
		FragColor = v_Color;
	else
		FragColor = vec4(0);
}
