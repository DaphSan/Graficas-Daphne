#include <IL/il.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture2D.h"


Camera _camera;
Mesh _mesh;
Transform _transformPadre;
Transform _transformHijo1;
Transform _transformHijo2;
Transform _transformHijo3;
Transform _transformHijo4;
Transform _transformNieto;
Transform _transformJoint1;
Transform _transformJoint2;
Transform _transformJoint3;
Transform _transformJoint4;
Transform _transformJointNieto;
Transform _transformSuelo;

ShaderProgram _shaderProgram;
Texture2D myTexture;
Texture2D myTexture2;
glm::vec3 lPosition;
glm::vec3 lColor;
glm::vec3 cPosition;
float angulozneg = 0;
float angulozpos = 0;
float anguloxneg = 0;
float anguloxpos = 0;
float anguloxposnieto = 0;
float delta = -0.01;

// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-12.0f, -1.0f, 12.0f));
	positions.push_back(glm::vec3(12.0f, -1.0f, 12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, 12.0f));
	positions.push_back(glm::vec3(-12.0f, 1.0f, 12.0f));
	// Cara lateral derecha
	positions.push_back(glm::vec3(12.0f, -1.0f, 12.0f));
	positions.push_back(glm::vec3(12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, -12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, 12.0f));
	//Cara trasera
	positions.push_back(glm::vec3(12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(-12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(-12.0f, 1.0f, -12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, -12.0f));
	// Cara lateral izquierda
	positions.push_back(glm::vec3(-12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(-12.0f, -1.0f, 12.0f));
	positions.push_back(glm::vec3(-12.0f, 1.0f, 12.0f));
	positions.push_back(glm::vec3(-12.0f, 1.0f, -12.0f));
	// Cara superior
	positions.push_back(glm::vec3(-12.0f, 1.0f, 12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, 12.0f));
	positions.push_back(glm::vec3(12.0f, 1.0f, -12.0f));
	positions.push_back(glm::vec3(-12.0f, 1.0f, -12.0f));
	// Cara inferior
	positions.push_back(glm::vec3(-12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(12.0f, -1.0f, -12.0f));
	positions.push_back(glm::vec3(12.0f, -1.0f, 12.0f));
	positions.push_back(glm::vec3(-12.0f, -1.0f, 12.0f));

	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// Cara trasera
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral izquierda
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// Cara superior
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	// Cara inferior
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//Normales
	std::vector<glm::vec3> normales;
	// Cara frontal
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normales.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	// Cara lateral derecha
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normales.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Trasera
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f)); //8
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f)); //9
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));//10
	normales.push_back(glm::vec3(0.0f, 0.0f, -1.0f));//11

													 //Cara lateral izquierda
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));//12
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));//13
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));//14
	normales.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));//15

													 //Cara Arriba
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //16
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //17
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//18
	normales.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//19

													//Cara abajo
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));//20
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));//21
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));//22
	normales.push_back(glm::vec3(0.0f, -1.0f, 0.0f));//23


													 //Lista de TEXTURAS
	std::vector<glm::vec2> texturas;
	// Cara frontal
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	// Cara lateral derecha
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));

	// Cara trasera
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	// Cara lateral izquerda
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));

	// Cara arriba
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));
	// Cara abajo
	texturas.push_back(glm::vec2(0.0f, 1.0f));
	texturas.push_back(glm::vec2(0.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 0.0f));
	texturas.push_back(glm::vec2(1.0f, 1.0f));


	//Vector de Posicion de la luz
	lPosition = glm::vec3(25.0f, 50.0f, 25.0f);

	//Vector de Color de la luz
	lColor = glm::vec3(1.0f, 1.0f, 1.0f);

	//Posicion de la camara
	cPosition = _camera.GetPosition();



	std::vector<unsigned int> indices = { 0,1,2,0,2,3,4,5,6,4,6,7,8,9,10,8,10,11,12,13,14,12,14,15,16,17,18,16,18,19,20,21,22,20,22,23,24,25,26,24,26,27 };

	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normales, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(texturas, GL_STATIC_DRAW, 3);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("PhongShading.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("PhongShading.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");
	_shaderProgram.LinkProgram();


	//POSICION DE TODOS LOS CUBOS
	_transformPadre.SetPosition(0.0f, -8.0f, -50.0f);
	_transformJoint1.SetPosition(-12.0f, 0.0f, 0.0f);
	_transformHijo1.SetPosition(-12.0f, 0.0f, 0.0f);
	_transformJoint2.SetPosition(12.0f, 0.0f, 0.0f);
	_transformHijo2.SetPosition(12.0f, 0.0f, 0.0f);
	_transformJoint3.SetPosition(0.0f, 0.0f, -12.0f);
	_transformHijo3.SetPosition(0.0f, 0.0f, -12.0f);
	_transformJoint4.SetPosition(0.0f, 0.0f, 12.0f);
	_transformHijo4.SetPosition(0.0f, 0.0f, 12.0f);
	_transformJointNieto.SetPosition(0.0f, 0.0f, -12.0f);
	_transformNieto.SetPosition(0.0f, 0.0f, -12.0f);
	_transformSuelo.SetPosition(0.0f, -10.0f, 0.0f);


	myTexture.LoadTexture("metalbox.jpg");
	myTexture2.LoadTexture("Fox.png");

}

void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/////////////////////////////////////////////////////////////////////////////////CUBO SUELO
	//_transformPadre.Rotate(0.0f, -0.01f, 0.0f, true);
	_transformSuelo.SetScale(10.0f, 0.5f, 10.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transformSuelo.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformSuelo.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();

	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();

	_shaderProgram.Deactivate();



	/////////////////////////////////////////////////////////////////////////////////CUBO PADRE
	_transformPadre.Rotate(0.0f, -0.01f, 0.0f, true);
	_transformPadre.SetScale(0.5f, 0.5f, 0.5f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transformPadre.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix());
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	////////////////////////////////////////////////////////////////////////////7JOINT 1

	angulozneg = angulozneg + delta;
	if (angulozneg <= -90.0f)
	{
		delta = 0.01;

	}
	if (angulozneg >= 0)
	{
		delta = -0.01;
	}
	_transformJoint1.SetRotation(0.0f, 0.0f, angulozneg);
	_transformJoint1.SetScale(1.0f, 1.0f, 1.0f);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformJoint1.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	/////////////////////////////////////////////////////////////////////////////CUBO HIJO1

	//_transformHijo1.Rotate(0.0f, 0.0f, -0.01f, true);
	_transformHijo1.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint1.GetModelMatrix()*_transformHijo1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix()*_transformJoint1.GetModelMatrix()*_transformHijo1.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	////////////////////////////////////////////////////////////////////////////7JOINT 2

	angulozpos = angulozpos - delta;
	if (angulozpos >= 90.0f)
	{
		delta = -0.01f;
	}
	if (angulozpos <= 0)
	{
		delta = 0.01f;
	}
	_transformJoint2.SetRotation(0.0f, 0.0f, angulozpos);
	_transformJoint2.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformJoint2.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	/////////////////////////////////////////////////////////////////////////////CUBO HIJO2
	//_transformHijo2.Rotate(0.0f, -0.01f, 0.0f, true);
	_transformHijo2.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint2.GetModelMatrix()*_transformHijo2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix()*_transformJoint2.GetModelMatrix()* _transformHijo2.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	////////////////////////////////////////////////////////////////////////////7JOINT 3

	//anguloxpos = anguloxpos + 0.01f;
	anguloxpos = anguloxpos - delta;
	if (angulozpos >= 90.0f)
	{
		delta = -0.01f;
	}
	if (angulozpos <= 0)
	{
		delta = 0.01f;
	}
	_transformJoint3.SetRotation(anguloxpos, 0.0f, 0.0f);
	_transformJoint3.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformJoint3.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	/////////////////////////////////////////////////////////////////////////////CUBO HIJO3
	//_transformHijo3.Rotate(0.0f, -0.01f, 0.0f, true);
	_transformHijo3.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix()*_transformHijo3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix()*_transformHijo3.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	////////////////////////////////////////////////////////////////////////////7JOINT 4

	//anguloxneg = anguloxneg - 0.01f;
	anguloxneg = anguloxneg + delta;
	if (angulozneg <= -90.0f)
	{
		delta = 0.01;

	}
	if (angulozneg >= 0)
	{
		delta = -0.01;
	}
	_transformJoint4.SetRotation(anguloxneg, 0.0f, 0.0f);
	_transformJoint4.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformJoint4.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	/////////////////////////////////////////////////////////////////////////////CUBO HIJO4
	//_transformHijo4.Rotate(0.0f, -0.01f, 0.0f, true);
	_transformHijo4.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint4.GetModelMatrix()*_transformHijo4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix()*_transformJoint4.GetModelMatrix()*_transformHijo1.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();

	////////////////////////////////////////////////////////////////////////////7JOINT Nieto

	//anguloxposnieto = anguloxposnieto + 0.01f;
	anguloxposnieto = anguloxposnieto - delta;
	if (angulozpos >= 90.0f)
	{
		delta = -0.01f;
	}
	if (angulozpos <= 0)
	{
		delta = 0.01f;
	}
	_transformJointNieto.SetRotation(anguloxpos, 0.0f, 0.0f);
	_transformJointNieto.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix()*_transformHijo3.GetModelMatrix()*_transformJointNieto.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformJointNieto.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	/////////////////////////////////////////////////////////////////////////////CUBO Nieto
	_transformNieto.SetScale(1.0f, 1.0f, 1.0f);


	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()  * _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix()*_transformHijo3.GetModelMatrix()*_transformJointNieto.GetModelMatrix()*_transformNieto.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transformPadre.GetModelMatrix()*_transformJoint3.GetModelMatrix()*_transformHijo3.GetModelMatrix()*_transformJointNieto.GetModelMatrix()*_transformNieto.GetModelMatrix());
	//Poniendole luz BLANCA lColor y mandandola al Frag como LightColor 
	_shaderProgram.SetUniformf("LightColor", lColor);
	_shaderProgram.SetUniformf("LightPosition", lPosition);
	_shaderProgram.SetUniformf("CameraPosition", cPosition);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_shaderProgram.SetUniformi("MixTexture", 1);
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	_shaderProgram.Deactivate();


	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)//AQUI ACTUALIZAMOS LA RESOLUCION Y TAMAÑO DEL VIEWPORT
{
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float)width / (float)height);
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	//Iniciamos DEVIL
	ilInit();
	//Cambiamos el punto de origen de las texturas
	ilEnable(IL_ORIGIN_SET);
	//Ponemos el punto de origen en la esquina inferior izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}