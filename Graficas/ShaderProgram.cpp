#include "ShaderProgram.h"
#include "Shader.h"
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <vector>


ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
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
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());
}

void ShaderProgram::DeleteAndDetachShaders()
{
	for (size_t i = 0; i < _attachedShaders.size(); i++)
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());

	_attachedShaders.clear();
}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}

/*
void ShaderProgram::setUniformf(std::string name, float value)
{
	in vec3 name;
	gl_Position = vec4(name, x, y);
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
*/
