#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include <IL/il.h>

class Shader
{
public:
	Shader();
	~Shader();

	void CreateShader(std::string path, GLenum type);

	GLuint GetHandle();

private:
	GLuint _shaderHandle;
};