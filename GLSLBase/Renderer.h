#pragma once

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Dependencies\glew.h"
#include "Dependencies\wglew.h"
#include "Dependencies\glm/glm.hpp"
#include "Dependencies\glm/gtc/matrix_transform.hpp"
#include "Dependencies\glm/gtx/euler_angles.hpp"

class Renderer
{
public:
	Renderer(int windowSizeX, int windowSizeY);
	~Renderer();

	GLuint CreatePngTexture(char * filePath);
	GLuint CreateBmpTexture(char * filePath);
	   
	void Test();
	void Lecture2();
	void Lecture3();
	void Lecture3_3();
	void Lecture4_FSSandbox();
	void Lecture4_Raindrop();
	void Lecture4_Radar();
	void Lecture5_LineSegment();
	void Lecture5_FullRect();
	void Lecture6_Sandbox();
	void Lecture9();
	void Lecture11();

private:
	void Initialize(int windowSizeX, int windowSizeY);
	bool ReadFile(char* filename, std::string *target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void CreateVertexBufferObjects(); 
	unsigned char * Renderer::loadBMPRaw(const char * imagepath, unsigned int& outWidth, unsigned int& outHeight);

	// count : quad의 개수
	void CreateParticle(int count);

	void CreateLine(int segCount);

	void CreateDummyMesh();

	void CreateFBO(GLuint& texID, GLuint& depthID, GLuint& frameID);

	void DrawFullScreenTexture(GLuint texID);

	bool m_Initialized = false;
	
	unsigned int m_WindowSizeX = 0;
	unsigned int m_WindowSizeY = 0;

	//camera position
	glm::vec3 m_v3Camera_Position;
	//camera lookat position
	glm::vec3 m_v3Camera_Lookat;
	//camera up vector
	glm::vec3 m_v3Camera_Up;

	glm::mat4 m_m4OrthoProj;
	glm::mat4 m_m4PersProj;
	glm::mat4 m_m4Model;
	glm::mat4 m_m4View;
	glm::mat4 m_m4ProjView;

	// 파티클 Vertex 개수
	GLuint m_VBOManyParticleVertexCount = 0;
	GLuint m_VBOLineSegmentCount = 0;
	GLuint m_DummyVertexCount = 0;

	// VBO
	GLuint m_VBORect = 0;
	GLuint m_VBOLecture2 = 0;
	GLuint m_VBOLecture3_2 = 0;
	GLuint m_VBOLecture3_3 = 0;
	GLuint m_VBOManyParticle = 0;
	GLuint m_VBOSandbox = 0;
	GLuint m_VBOLineSegment = 0;
	GLuint m_VBOFullRect = 0;
	GLuint m_VBOTexSandbox = 0;
	GLuint m_VBODummyMesh = 0;
	
	// Shader
	GLuint m_SolidRectShader = 0;
	GLuint m_Lecture3Shader = 0;
	GLuint m_ParticleShader = 0;
	GLuint m_FSSandboxShader = 0;
	GLuint m_LineSegmentShader = 0;
	GLuint m_FullRectShader = 0;
	GLuint m_TexSandboxShader = 0;
	GLuint m_DummyMeshShader = 0;

	// Texture
	GLuint m_SampleTexture = 0;
	GLuint m_RGBTexture = 0;
	GLuint m_FBOTexture0 = 0;
	GLuint m_FBOTexture1 = 0;
	GLuint m_FBOTexture2 = 0;
	GLuint m_FBOTexture3 = 0;
	GLuint m_FBOTexture4 = 0;
	GLuint m_FBOTexture5 = 0;
	GLuint m_FBOTexture6 = 0;
	GLuint m_FBOTexture7 = 0;

	// Depth buffer
	GLuint m_RBDepth0 = 0;
	GLuint m_RBDepth1 = 0;
	GLuint m_RBDepth2 = 0;
	GLuint m_RBDepth3 = 0;
	GLuint m_RBDepth4 = 0;
	GLuint m_RBDepth5 = 0;
	GLuint m_RBDepth6 = 0;
	GLuint m_RBDepth7 = 0;

	// Frame buffer
	GLuint m_FBO0 = 0;
	GLuint m_FBO1 = 0;
	GLuint m_FBO2 = 0;
	GLuint m_FBO3 = 0;
	GLuint m_FBO4 = 0;
	GLuint m_FBO5 = 0;
	GLuint m_FBO6 = 0;
};

