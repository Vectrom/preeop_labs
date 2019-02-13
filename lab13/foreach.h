#pragma once
#include <functional>
#include "itr.h"
/**
* @class foreach
* @brief Klasa wykonująca operacje na zadanych elementach 
*/
class foreach {
	public:
		/**
		* @fn foreach
		* @brief Konstruktor. Wykonuje funkcję podaną jako parametr, której argumentem są kolejne liczby przekazywane przez iterator
		* @param iterator Iterator
		* @param functor Funkcja, która zostanie wykonana dla każdej z liczb przekazanej przez iterator
		*/
		foreach(itr iterator, std::function<void(int)> functor);
};