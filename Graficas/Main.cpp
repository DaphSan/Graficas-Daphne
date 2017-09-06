
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					06/09/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/
#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char*argv[]) 
{
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);

	if (myFile.Read(filename)== false)
	{
		std::cout << "   " << std::endl;
	}

	else
	{
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;
	}

	std::cin.get();
	return 0;
}
