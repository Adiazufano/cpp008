#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
/*std::stack ya es un template con 2 parametros:
	T -> que es el tipo de los elementoos
	container -> el contenedor subyacente
	stack hereda de un contenedor llamado c
	que por defecto es deque<T> este contenedor si tiene iteradores */

using std::cout;
using std::endl;
using std::stack;

template <typename T>
class MutantStack : public stack<T>
{
	public:
		MutantStack() : stack<T>(){};
		MutantStack(const MutantStack& other) : stack<T>(other){};
		MutantStack<T>& operator=(const MutantStack& other)
		{
			stack<T>::operator=(other);
			return *this;
		};
		~MutantStack(){};
	/*Declarar los iteradores y definir los metodos
		1 definir tipo de iterador con typedef
		2 los metodos
		hay que declarar el  iterador debido a que no es mio lo rescato del contenedor interno 
		y los metodos debo implementarlos porque el propio stack los oculta*/
	typedef typename stack<T>::container_type::iterator iterator;//el typedef apunta al iterador del deque no al de stack ya que no tiene iteradores
	typedef typename stack<T>::container_type::iterator const_iterator;//el typedef apunta al iterador del deque no al de stack ya que no tiene iteradores
	typedef typename stack<T>::container_type::reverse_iterator reverse_iterator;//el typedef apunta al iterador del deque no al de stack ya que no tiene iteradores
	typedef typename stack<T>::container_type::reverse_iterator const_reverse_iterator;//el typedef apunta al iterador del deque no al de stack ya que no tiene iteradores

	iterator begin()
	{
		return this -> c.begin();
	}

	iterator end()
	{
		return this -> c.end();
	}

	const_iterator begin() const
	{
		return this -> c.begin();
	}

	const_iterator end() const
	{
		return this -> c.end();
	}

	reverse_iterator rbegin()
	{
		return this -> c.rbegin();
	}

	reverse_iterator rend()
	{
		return this -> c.rend();
	}

	const_reverse_iterator rbegin() const
	{
		return this -> c.rbegin();
	}

	const_reverse_iterator rend() const
	{
		return this -> c.rend();
	}
};
#endif