#include "Mesh.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

Mesh::Mesh()
{ //constructor inicializa los valores por default de las variables
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;

}

Mesh::~Mesh()
{	
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	_vertexCount = 0;
}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	
//Intento de "crear un VAO y guardar el identificadoor en _vertexArrayObject
	glGenVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{ //metodo draw hace bind del vao y dibuja los vertices de la malla
	glBindVertexArray(_vertexArrayObject);

	//la funcion original es glDrawArrays(GLenum mode<que es el tipo de primitiva
	// GLint first<indicie inicial de los VBO>, GLsizei count <numero de vertices a dibujar>
	glDrawArrays(primitive, 0, _vertexCount);

	//unbind del vao
	glBindVertexArray(_vertexArrayObject);

}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() ==_vertexCount)
	{
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2)*positions.size(), positions.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex)
{
	if (positions.size() > 0 && positions.size() == _vertexCount)
	{
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3)*positions.size(), positions.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{
	if (colors.size() > 0 && colors.size() == _vertexCount)
	{
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3)*colors.size(), colors.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex)
{
	if (colors.size() > 0 && colors.size() == _vertexCount)
	{
		SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec2)*colors.size(), colors.data(), usage, locationIndex, 4);
	}
}
void Mesh::SetAttributeData(GLuint &buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLint components)
{
	if (buffer != 0)
	{
		glDeleteBuffers(1, &buffer); //cuantos buffers y qué bbuffer quieres borrar
	}
	//glBindVertexArray(_vertexArrayObject);
	else
	{
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//y esto haha
	glBindVertexArray(0);
	}
}
