#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <string>
#include <vector>
#include <exception>

using std::cout;
using std::endl;
using std::exception;

class NotCoincidenceExeption : public exception
{
	const char* what() const throw()
	{
		return ("Exception: not coincidence");
	}
};

template<typename T> int easyfind(T arr, int num)
{
	/*se usa sizeof(arr) / sizeof(arr[0]) para calcular el tamaño del contenedor funciona solamente si se pasa el contenedor de froma estatica
	porque lo que hace es dividir loo bytes totales entro los de 1 solo elemento para obtener la cantidad de elementos*/
	for (unsigned long index = 0; index < sizeof(arr) / sizeof(arr[0]); index++)
	{
		if (arr[index] == num)
			return(num);
	}
	throw NotCoincidenceExeption();
};


#endif