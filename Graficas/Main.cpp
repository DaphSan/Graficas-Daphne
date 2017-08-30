
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					22/08/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/

#include<iostream>
#include<GL/glew.h>
#include<GL/freeglut.h>

void MainLoop()
{
	//borramos el buffer de color y profundidad siempre al
	//inicio de un nuevo frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//WARNING!!!! esto es OpenGl clásico y no lo vamos a volver a usar
	//en todo el semestre.
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);

	glEnd();
	//FIN DEL WARNING

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
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

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

	//iniciamos la aplicacion gráfica.
	//el main se pausará en esta linea hasta que se cierre
	//la ventana de OpenGL
	glutMainLoop();

	return 0;
}