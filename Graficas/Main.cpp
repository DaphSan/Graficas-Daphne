
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					06/09/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp> 
#include <vector> 

GLuint vao;

void Initialize()
{

	std::vector<glm::vec2> positions;
	
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(234.0)), 1.0 * glm::sin(glm::radians(234.0))));
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(306.0)), 1.0 * glm::sin(glm::radians(306.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(306.0)), 0.5 * glm::sin(glm::radians(306.0))));
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(18.0)), 1.0 * glm::sin(glm::radians(18.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(18.0)), 0.5 * glm::sin(glm::radians(18.0))));
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(90.0)), 1.0 * glm::sin(glm::radians(90.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(90.0)), 0.5 * glm::sin(glm::radians(90.0))));
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(162.0)), 1.0 * glm::sin(glm::radians(162.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(162.0)), 0.5 * glm::sin(glm::radians(162.0))));
	positions.push_back(glm::vec2(1.0 * glm::cos(glm::radians(234.0)), 1.0 * glm::sin(glm::radians(234.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(234.0)), 0.5 * glm::sin(glm::radians(234.0))));
	positions.push_back(glm::vec2(0.5 * glm::cos(glm::radians(306.0)), 0.5 * glm::sin(glm::radians(306.0))));
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	

	GLuint positionsVBO;
	glGenBuffers(1, &positionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)* positions.size(), positions.data(), GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);
	}

void MainLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 12); 
	
	glBindVertexArray(0);

	glutSwapBuffers();
}


int main(int argc, char*argv[]) 
{
	glutInit(&argc, argv);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	
	glutCreateWindow("Hello World OpenGL");


	glutDisplayFunc(MainLoop);

	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	Initialize();
	glutMainLoop();

	return 0;
}
