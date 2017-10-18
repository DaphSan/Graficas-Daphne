#include "InputFile.h"
#include "Shader.h"

Shader::Shader()
{
	_shaderHandle = 0;
}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type)
{
	//USAR _SHaderHandle
	if (_shaderHandle != 0)
	{ 
		glDeleteShader(_shaderHandle); 
	}

	else
	{
		//Aqui lee 
		InputFile ifile;
		ifile.Read(path);
		std::string contenido = ifile.GetContents();
		//Aqui convierte vertexSource en Chart pa' que lo lea
		const GLchar *contenido_c = (const GLchar*)contenido.c_str();
		GLuint _shaderHandle = glCreateShader(type); //????????
		
		//los otros metodos de la libreria
		glShaderSource(_shaderHandle, 1, &contenido_c, nullptr);
		glCompileShader(_shaderHandle);
	}
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}
