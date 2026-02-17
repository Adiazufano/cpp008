/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:22:19 by aldiaz-u          #+#    #+#             */
/*   Updated: 2026/02/17 12:35:40 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(10);
	v.push_back(25);
	v.push_back(88);
	v.push_back(2);

	int r;
	try
	{
		r = easyfind(v, 20);
		cout << r << endl;
	}
	catch (exception &e)
	{
		std::cerr << e.what() << endl;
	}
}