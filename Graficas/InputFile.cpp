#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>


//este booleano me dirá si sí lo pudo abrir o no
bool InputFile::Read(std::string texto) {

	std::fstream iFile(texto, std::fstream::in);

	bool leido = false;

	if (iFile.is_open())
	{
		std::stringstream contenido;

		contenido << iFile.rdbuf();
		_contents = contenido.str();
		leido = true;
	}

	else
	{	leido = false;
	}
	return leido;
	iFile.close();
}

std::string InputFile::GetContents() {
	return _contents;
	
}