#version 450

in vec4 v_Color;

out vec4 FragColor;

uniform vec3 u_Points[10];
uniform float u_Time;

const float PI = 3.14;

vec4 CrossPattern(int line)
{
	vec4 returnValue = vec4(1);

	float xAxis = sin(line * v_Color.x * 2 * PI + PI / 2);
	float yAxis = sin(line * v_Color.y * 2 * PI + PI / 2);
	float resultColor = max(xAxis, yAxis);

	returnValue = vec4(resultColor);
	return returnValue;
}

vec4 DrawDonut()
{
	float dist = distance(v_Color.xy, vec2(0.5)); // ÅØ½ºÃÄ ÁÂÇ¥ÀÇ Áß¾Ó
	vec4 newColor = vec4(0);

	if(dist > 0.48 && dist < 0.5)
		newColor = vec4(1);
	else
		newColor = vec4(0);

	return newColor;
}

vec4 DrawCircle()
{
	float dist = distance(v_Color.xy, vec2(0.5));
	vec4 newColor = vec4(0);

	if(dist < 0.5)
		newColor = vec4(1);
	else
		newColor = vec4(0);

	return newColor;
}

vec4 DrawMultipleCircles(int numCircle)
{
	float dist = distance(v_Color.xy, vec2(0.5)); // 0~0.5
	float temp = sin(numCircle * dist * 4 * PI);

	vec4 newColor = vec4(temp);
	return newColor;
}

vec4 DrawCircles()
{
	vec4 returnColor = vec4(0);

	for(int i =0 ; i < 10 ; ++i)
	{
		float dist = distance(u_Points[i].xy, v_Color.xy);
		float temp = sin(10 * dist * 4 * PI - u_Time * 100);

		if(dist < u_Time)
			returnColor += vec4(temp);
	}

	return returnColor;
}

void main()
{
	//FragColor = CrossPattern(5);
	//FragColor = DrawDonut();
	//FragColor = DrawCircle();
	//FragColor = DrawMultipleCircles(5);
	FragColor = DrawCircles();
}
