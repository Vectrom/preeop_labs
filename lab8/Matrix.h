#pragma once
#include "Vector.h"

/** @class Vector
* @brief Klasa, której obiektami są macierze zbudowane z wektorów
*/
class Matrix {
public:
	/** @fn Matrix
	* @brief Konstruktor obiektu klasy Matrix, tworzy macierz o podanej ilości wierszy, alokuje na nią pamięć i jako każdy wiersz tworzy nowy obiekt klasy Vector 
			 o wielkości równej ilości kolumn i każdym elemencie równym wartości podanej jako parametr
	* @param rows Ilość wierszy macierzy (ilość wektorów w macierzy)
	* @param columns Ilość kolumn macierzy (wielkość każdego z wektorów)
	* @defaultValue Domyślna wartość, którą przyjmują liczby przechowywane w macierzy (każdym z wektorów)
	*/
	Matrix(const int rows, const int columns, const int defaultValue);

	/** @fn ~Matrix
	* @brief Destruktor zwalniający pamięć przydzieloną na każdy z wektorów (wierszy macierzy) oraz na macierz
	*/
	~Matrix();

	/** @fn at
	* @brief Metoda zwracająca referencję do wektora będącego wierszem macierzy o indeksie podanym jako parametr 
	* @param index Index wektora (wiersza macierzy) do którego chcemy zwrócić referencję
	*/
	Vector & at(const int index);

	/** @fn print
	* @brief Metoda wypisująca macierz (elementy oddzielone spacjami, wiersze oddzielone nową linią)
	*/
	void print() const;
	
private:
	Vector ** _matrix; //wskaźnik do macierzy
	int _rows; //ilość wierszy macierzy = ilość wektorów przechowywanych w macierzy
};