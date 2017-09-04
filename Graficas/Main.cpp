
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					22/08/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/

#include<iostream>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include <glm/glm.hpp> //libreria de matemmaticas para graficas
#include <vector> //listas= arreglo pero mas boonito

//identificador del manager de VBO's para 1 geometria para un conjunto de vertices
GLuint vao;

//solo se configura una vez en el programa, función que inicializa toda
//la memoria del programa
void Initialize()
{	//vamos a crear una lista que almacene las posiciones
	//en 2 dimensiones de un triangulo.
	//Esto es CPU y RAM
	std::vector<glm::vec2> positions;

	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	//vamos a crear una ista para almacenar colores RGB
	std::vector<glm::vec3> colors; //<tipo de vector: 3 datos> nombre de la lista;
	//RGB EN FLOATS
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //rojo
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //verde
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //azul

	//Creamos un VAO y almacenamos el id en la variable vao.
	//este es el manager de VBO's
	glGenVertexArrays(1, &vao); //se crea 1 y se guarda en &vao (sí, con "&")
	//todos los VBO's que se creen a partir de este punto y hasta
	//que desactivemos este bound, se van a asociar a este manager.
	glBindVertexArray(vao);

	//equivale a un entero sin signo. ahi guardamos el
	//identificador del VBO de posiciones
	GLuint positionsVBO;
	//creamos un BO y almacenamos el identificador en la variable positions VBO
	glGenBuffers(1, &positionsVBO);

	//le decimos a OpenGL que lo que queremos utilizar como un atributo.
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);

	//Asignamos los datos al buffer y los mandamos a la tarjeta de video
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)* positions.size(), positions.data(), GL_STATIC_DRAW);

	//Quiero activar el atributo con indice 0 en la tarjeta de video
	glEnableVertexAttribArray(0);
	
	//configuramos el atributo con indice 0 en la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	//Desactivamos el uso 
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//ya no quiero usar el VAO. ya no se asociaran mas VBOs a este vao
	glBindVertexArray(0);

}

void MainLoop()
{
	//borramos el buffer de color y profundidad siempre al
	//inicio de un nuevo frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TO DO: hacer el render

	//PASO 1  AUN NO LO PODEMOS HACER!!


	//PASO2: ACTIVAR UN vao
	glBindVertexArray(vao);

	//PASO 3: DIBUJAMOS
	glDrawArrays(GL_TRIANGLES, 0, 3); //(que usamos para dibujar, desde qué lugar de la lista, cuantos elementos)

	//PASO 4: DESACTIVAMOS EL VAO
	glBindVertexArray(0);

	//PASO 5: AUN NO LO PODEMOS HACER!


	//Intercambiar los buffer (el que se estaba
	//rendereando con el que se estaba mostrando.
	glutSwapBuffers();
}


int main(int argc, char * argv[]) 
{	//inicializamos freeglut.
	//Freeglut se encarga de generar y manejar ventanas.
	// usamos freeglut para crear una ventana donde vamos a dibujar
	glutInit(&argc, argv);
	

	//teenmos que informar que queremos trabajar con el pipline clasico (OpenGL viejito)
	// programable (OpenGl moderno)
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//freeglut nos permite configurar eventos que ocurren en la ventana
	//uno de ellos es cuando alguien cierra la venta
	//cuando alguien cierre la ventana, dejamos de renderear y termina el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);


	// Configuramos el framebuffer. En este caso estamos
	//solicitando un buffer de color true color RGBA, un buffer de profundidad, y
	//un segundo buffer para renderear (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	//creamos y abrimos la ventana con un titulo personalizado.
	glutCreateWindow("Hello Wolrd OpenGL");

	
	//Asociar una función de render. Esta funcion se mandara a llamar
	//para dibujar un frame
	glutDisplayFunc(MainLoop);

	//inicializamos GLEW.
	//esta libreria se encarga de obtener el API de
	//OpenGL de nuestra tarjeta de video.
	glewInit();

	//configurar OpenGl
	//Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f,1.0f);

	//configurar la memoria que la aplicacion va a necesitar
	Initialize();

	//iniciamos la aplicacion gráfica.
	//el main se pausará en esta linea hasta que se cierre
	//la ventana de OpenGL
	glutMainLoop();

	return 0;
}