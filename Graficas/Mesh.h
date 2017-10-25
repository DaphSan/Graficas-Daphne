#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh
{
public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount); //cuantos vertices son
	void Draw(GLenum primitive); //qué tipo de geometria es

	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex); //una lista que recibe posiciones, tipo de uso y el indice que queremos prender
	void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex); //almacena elementos con 3 componentes <x,y,z>
	void SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex);
	
private:
	GLuint _vertexArrayObject; //este es el manager de vertices
	GLuint _positionsVertexBufferObject; //bufer de un atributo , ayuda a comunicar datos de cpu con la tarjeta de video
	GLuint _colorsVertexBufferObject; //lo mismo pero con colores
	GLint _vertexCount; //guarda la cantidad de vertices para ocupar
	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data,
		GLenum usage, GLuint locationIndex, const GLint components); 
	// tipo de dato, tipo de dato, apuntador constante a los elementos de la lista, tipo de uso de la memoria, 
	//indice del atributo que vamos a prender, entero constante con el numero de componentes que vamos a tener


};
