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
	for (unsigned long index = 0; index < sizeof(arr) / sizeof(arr[0]); index++)
	{
		if (arr[index] == num)
			return(num);
	}
	throw NotCoincidenceExeption();
};


#endif