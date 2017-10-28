
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					06/09/2017

Autor:					A01169892 Daphne Sánchez Flores

	EXAMEN SEGUNDO REGISTRO
*************************************************************/
#include <iomanip>
#include "Transform.h"
#include <iostream>

Transform rotation;
Transform translation;
Transform scale;
Transform combined;

void PrintTransform(Transform& t)
{

	glm::mat4 modelMatrix = t.GetModelMatrix();
	for (size_t i = 0; i<modelMatrix.length(); i++)
	{
		for (size_t j = 0; j<modelMatrix.length(); j++)
		{
			std::cout << std::setw(10) << std::left << modelMatrix[j][i] << "";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Initialize()
{
	rotation.SetRotation(45, 90, 30);
	PrintTransform(rotation);

	translation.SetPosition(3, 5, -7);
	PrintTransform(translation);

	scale.SetScale(2, 3, 4);
	PrintTransform(scale);

	combined.SetRotation(45, 90, 30);
	combined.SetPosition(3, 5, -7);
	combined.SetScale(2, 3, 4);
	PrintTransform(combined);

}
int main(int argc, char* argv[])
{
	Initialize();
	std::cin.get();
	return 0;
}