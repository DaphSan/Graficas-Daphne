#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

class Shader {
	private:
	GLuint _shaderHandle;

	public:
		Shader();
		~Shader();
		void CreateShader(std::string path, GLenum type);
		GLuint GetHandle();
};