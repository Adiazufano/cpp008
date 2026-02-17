#ifndef SPAN_HPP
#define SPAN_HPP
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

using std::distance;
using std::vector;
using std::cout;
using std::endl;
using std::min_element;
using std::max_element;
using std::exception;

class Span
{
	private:
		unsigned int N;
		vector<int> storage;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();
		void	addNumber(int N);
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end)
		{
			unsigned int dist = distance(begin, end);
			if (this -> storage.size() + dist > N)
				throw std::out_of_range("span is full");
			this -> storage.insert(this -> storage.end(), begin, end);
		};
		int	shortestSpan();
		int	longestSpan();
		class	SizeToShortException : public exception
		{
			const char* what() const throw()
			{
				return ("Exception: the size is so short");
			}
		};
};
#endif