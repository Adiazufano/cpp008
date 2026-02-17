/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:33:19 by aldiaz-u          #+#    #+#             */
/*   Updated: 2026/02/17 17:31:36 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
	storage.reserve(N);
	cout << "Span default constructor" << endl;
}

Span::Span(unsigned int n) : N(n)
{
	storage.reserve(n);
	cout << "Span constructor" << endl;
}

Span::Span(const Span& other) : N(other.N)
{
	storage.reserve(N);
	cout << "Span copy constructor" << endl;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		storage = other.storage;
	}
	
	return (*this);
}

Span::~Span()
{
	cout << "Span destructor" << endl;
}

void	Span::addNumber(int N)
{
	if (storage.size() > static_cast<size_t>(N) - 1)
		throw std::out_of_range("Span is full");
	storage.push_back(N);
}

int	Span::shortestSpan()
{
	if (storage.size() < 2)
		throw SizeToShortException();
	std::sort(storage.begin(), storage.end());
	int	min_diff = storage[1] - storage[0];
	
	for (size_t index = 1; index < storage.size() - 1; index++)
	{
		int diff = storage[index + 1] - storage[index];
			if (diff < min_diff)
				min_diff = diff;
	}
	return(min_diff);
}

int	Span::longestSpan()
{
	if (storage.size() < 2)
		throw SizeToShortException();
	int min = *min_element(storage.begin(), storage.end());
	int max = *max_element(storage.begin(), storage.end());
	
	return(max - min);
}