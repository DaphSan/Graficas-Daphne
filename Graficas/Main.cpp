
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					22/08/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/

#include<iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
//#include <string>


int main() {
	std::cout << "Hello world" << std::endl;

	Circle killme;

	std::cout << killme.GetRadius() << std::endl;
	std::cout << killme.GetColor() << std::endl;
	killme.SetColor("orange");
	std::cout << killme.GetColor() << std::endl;


//Actividad 3
	std::cout << "Actividad 3" << std::endl;
	Rectangle rectangulo;

	std::cout << "base = "; std::cout << rectangulo.GetWidth() << std::endl;
	std::cout << "altura = "; std::cout << rectangulo.GetHeight() << std::endl;
	std::cout << "area = "; std::cout << rectangulo.GetArea() << std::endl;
	std::cout << "perimetro = "; std::cout << rectangulo.GetPerimeter() << std::endl;

	std::cout << "nuevos datos" << std::endl;

	rectangulo.SetWidth(4.0);
	rectangulo.SetHeight(5.0);

	std::cout << "base = "; std::cout << rectangulo.GetWidth() << std::endl;
	std::cout << "altura = "; std::cout << rectangulo.GetHeight() << std::endl;
	std::cout << "area = "; std::cout << rectangulo.GetArea() << std::endl;
	std::cout << "perimetro = "; std::cout << rectangulo.GetPerimeter() << std::endl;
	

//Actividad 4
	Employee empleado(1169892, "Daphne", "Sanchez", 200);
	std::cout << empleado.Print() << std::endl;

	empleado.SetSalary(400);
	std::cout << "salario con porcentaje: " + std::to_string(empleado.RaiseSalary(50)) << std::endl;
	std::cout << "salario anual: " + std::to_string(empleado.GetAnnualSalary()) << std::endl;
	std::cin.get();
	return 0;
}