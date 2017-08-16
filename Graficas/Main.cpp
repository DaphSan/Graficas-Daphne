
/*************************************************************

Materia:				Gráficas Computacionales

Fecha:					15/08/2017

Autor:					A01169892 Daphne Sánchez Flores

*************************************************************/

#include<iostream>

//Ejercicio 1
int PerimetroRectangulo(int base, int altura) {
	return 2 * (base + altura);
}

//Ejercicio 2
float AreaTriangulo(float base, float altura) {
	return (base * altura) / 2;
}

//Ejercicio 3
int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2 && numero1 > numero3) {
		return numero1; 
	}
	else if (numero1 > numero2 && numero1 < numero3) {
		return numero3; 
	}
	else
	{
		if (numero1 < numero2 && numero2 < numero3) {
			return numero3;
		}
		else
			return numero2;
	}
}

//Ejercicio 4
int Menor(int numero1, int numero2, int numero3) {
	if (numero1 < numero2 && numero1 < numero3) {
		return numero1;
	}
	else if (numero1 < numero2 && numero1 > numero3) {
		return numero3;
	}
	else
	{
		if (numero1 > numero2 && numero2 > numero3) {
			return numero3;
		}
		else
			return numero2;
	}
}

//Ejercicio 5
void FilaEstrellas(int n) {
	int i = 0;
	while (i < n) {
		std::cout << "*";
		i++;
	}
	std::cout << " " << std::endl;
}

//Ejercicio 6
void MatrizEstrellas(int n) {
	int i = 0;
	for (int j=0; j<n ; j++){
		i = 0;
		while (i < n-1) {
			std::cout << "*";
			i++;
		}
		std::cout<< "*" << std::endl;
	}
}

//Ejercicio 7
void PiramideEstrellas(int n) {
	int i = 0;
	for (int j = 0; j<n; j++) {
		i = 0;
		while (i < j) {
			std::cout << "*";
			i++;
		}
		std::cout << "*" << std::endl;
	}
}

//Ejercicio 8 
//int i es cantidad en x <---->
void FlechaEstrellas(int n) {
	int i = 0;
	for (int j = 0; j<n; j++) {
		i = 0;
		while (i < j) {
			std::cout << "*";
			i++;
		}
		std::cout << "*" << std::endl;
	}

	for (int j = 0; j < n-1; j++) {
		int i = n-2;
		while (i > j) {
			std::cout << "*";
			i--;
		}
		std::cout << "*" << std::endl;
	}
}

//Ejercicio 9 
void Fibonacci(int n) {
	int a = 0;
	int b = 1;
	int c = a;
	int i = 0;
	while (i < n) {
		std::cout << b << " ";
		c = a + b;
		a = b;
		b = c;
		i++;
	}
}

//Ejercicio 10
//x es la cantidad de divisores del ciclo, solo puede tener 2: 
// 1 por sí mismo y otro por ser dividido entre 1
bool EsPrimo(int numero) {
	int x = 0;
	for (int i = 1; i <= numero; i++) {
		if (numero % i == 0) {
			x++;
		}
	}
	if (x == 2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::cout << "hola mundo" << std::endl;

	int p = PerimetroRectangulo(5, 3);
	std::cout << p << std::endl;

	float a = AreaTriangulo(5.0f, 3.0f);
	std::cout << a << std::endl;

	int mayor = Mayor(5, 9, 1);
	std::cout << mayor << std::endl;

	int menor = Menor(5, 9, 1);
	std::cout << menor << std::endl;

	FilaEstrellas(5);
	std::cout << "   " << std::endl;

	MatrizEstrellas(4);
	std::cout << "   " << std::endl;

	PiramideEstrellas(6);
	std::cout << "   " << std::endl;

	FlechaEstrellas(3);
	std::cout << "   " << std::endl;

	Fibonacci(9);
	std::cout << "   " << std::endl;

	bool primo = EsPrimo(11);
	if (primo == false) {
		std::cout << "False" << std::endl;
	}
	else {
		std::cout << "True" << std::endl;
	}

	std::cin.get();
	return 0;
}