/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:50:57 by aldiaz-u          #+#    #+#             */
/*   Updated: 2026/02/17 17:36:27 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main() {
    // --- TEST 1: Caso básico del enunciado ---
    std::cout << "--- Test 1: Basico ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- TEST 2: Prueba de fuego (15,000 números) ---
    std::cout << "\n--- Test 2: 15,000 numeros con rango ---" << std::endl;
    try {
        Span bigSpan(15000);
        std::vector<int> bigData;
        
        std::srand(std::time(0)); // Semilla para aleatorios
        for (int i = 0; i < 15000; ++i) {
            bigData.push_back(std::rand());
        }

        // Usamos tu funcion de rango (la que usa iteradores)
        bigSpan.addNumbers(bigData.begin(), bigData.end());

        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- TEST 3: Gestion de errores (Llenar de mas) ---
    std::cout << "\n--- Test 3: Excepcion cuando esta lleno ---" << std::endl;
    try {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3); // Esto deberia lanzar excepcion
    } catch (const std::exception& e) {
        std::cout << "Excepcion capturada correctamente: " << e.what() << std::endl;
    }

    // --- TEST 4: Gestion de errores (Pocos elementos) ---
    std::cout << "\n--- Test 4: Excepcion con 1 solo elemento ---" << std::endl;
    try {
        Span lonely(10);
        lonely.addNumber(42);
        std::cout << lonely.shortestSpan() << std::endl; // Deberia fallar
    } catch (const std::exception& e) {
        std::cout << "Excepcion capturada correctamente: " << e.what() << std::endl;
    }

	// --- TEST EXTRA: ¿Por qué falla el rango? ---
    std::cout << "\n--- Test Extra: Acumulación ---" << std::endl;
    try {
        Span sp(15000);
        sp.addNumber(42); // El size ya es 1
        
        std::vector<int> v(15000, 1); // Intentamos meter 15,000 más
        // 1 + 15,000 > 15,000 -> LANZA "span is full"
        sp.addNumbers(v.begin(), v.end()); 
    } catch (const std::exception& e) {
        std::cout << "Fallo esperado: " << e.what() << std::endl;
    }
    return 0;
}