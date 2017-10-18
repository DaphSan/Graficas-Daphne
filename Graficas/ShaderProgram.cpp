#include "ShaderProgram.h"
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <vector>
#version 330

GLuint shaderProgram;

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_programHandle);
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string name, GLenum type)
{
	//create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(name, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	glAttachShader(_programHandle, _attachedShaders);

	glLinkProgram(_programHandle);

	ShaderProgram::DeleteAndDetachShaders;
}

void ShaderProgram::Activate()
{
	glBindAttribLocation(_programHandle, 1, _attachedShaders);
}

void ShaderProgram::Deactivate()
{
	glBindVertexArray(_programHandle);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	name = std::to_string(locationIndex);
}

void ShaderProgram::DeleteAndDetachShaders()
{
	if (_attachedShaders.size != 0)
	{
		glDeleteShader(Shader);
	}

	delete[] _attachedShaders;
}

void ShaderProgram::DeleteProgram()
{
	ShaderProgram::DeleteAndDetachShaders;
	delete[] ShaderProgram::_programHandle;
}




void ShaderProgram::setUniformf(std::string name, float value)
{
	in vec3 name;
	gl_Position = vec4(name, value);
}

void ShaderProgram::setUniformf(std::string name, float x, float y)
{
	in vec3 name;
	gl_Position = vec4(name, x, y);
}

void ShaderProgram::setUniformf(std::string name, float x, float y, float z)
{
	in vec3 name;
	gl_Position = vec4(name, x, y, z);
}

void ShaderProgram::setUniformf(std::string name, float x, float y, float z, float w)
{
	in vec3 name;
	gl_Position = vec4(name, x, y, z, w);
}
