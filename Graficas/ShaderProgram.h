#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <memory>

class ShaderProgram
{
private:
	GLuint _programHandle;
	std::vector<std::unique_ptr<Shader>> _attachedShaders;
	void DeleteAndDetachShaders();
	void DeleteProgram();

public:
	ShaderProgram();
	~ShaderProgram();
	void CreateProgram();
	void AttachShader(std::string path, GLenum type);
	void LinkProgram();
	void Activate();
	void Deactivate();
	void SetAttribute(GLuint locationIndex, std::string name);
	void setUniformf(std::string name, float value);
	void setUniformf(std::string name, float x, float y);
	void setUniformf(std::string name, float x, float y, float z);
	void setUniformf(std::string name, float x, float y, float z, float w);

};