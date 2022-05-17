#version 450

in vec3 a_Position;
in vec3 a_Velocity;
in float a_EmitTime;
in float a_LifeTime;
in float a_Amp;
in float a_Period;

uniform float u_Time;
uniform vec3 u_Accel;

bool bLoop = true;
float PI = 3.14f;

void main()
{
	// ��ƼŬ�� �ð�
	float t = u_Time - a_EmitTime;
	float tt = t * t;

	vec3 newPos;

	if(t > 0)
	{
		float temp = t / a_LifeTime;
		float fraction = fract(temp); // �Ҽ��� �Ʒ��� �κи� ����
		t = fraction * a_LifeTime; // fraction�� ���� 0~1 ���̰� �ݺ�
		tt = t * t;

		newPos.x = a_Position.x + t * a_Velocity.x + 0.5 * u_Accel.x * tt;
		newPos.y = a_Position.y + a_Amp * sin(a_Period * t * 2 * PI);
		newPos.z = 0.0f;
	}
	else
	{
		newPos = vec3(-10000);
	}

	gl_Position = vec4(newPos, 1);
}
