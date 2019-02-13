#pragma once
/** @class Vector
* @brief Klasa, której obiektami są wektory
*/
class Vector {
public:
	/** @fn Vector
	* @brief Konstruktor obiektu klasy wektor, tworzy wektor o podanej wielkości, alokuje na niego pamięć i uzupełnia go podanymi wartościami
	* @size Rozmiar wektora, który chcemy utworzyć
	* @defaultValue Domyślna wartość, którą przyjmują liczby przechowywane w wektorze
	*/
	Vector(const int size, const int defaultValue);

	/** @fn ~Vector
	* @brief Destruktor obiektu klasy wektor, zwalnia pamięć zaalokowaną na potrzeby obiektu
	*/
	~Vector();

	/** @fn print
	* @brief Metoda wypisująca liczby przechowywane w wektorze oddzielone spacjami
	*/
	void print() const;

	/** @fn mul
	* @brief Metoda mnożąca wektor przez wartość podaną jako parametr (wszystkie liczby przechowywane w wektorze zostaną pomnożone przez tę wartość)
	* @param value Wartość przez którą chcemy pomnożyć wektor
	*/
	void mul(const int value);

	/** @fn add
	* @brief Metoda dodająca do wszystkich liczb przechowywanych w wektorze wartość podaną jako parametr
	* @param value Wartość, którą chcemy dodać do każdej z liczb przechowywanej w wektorze
	* @return Referencja do obiektu na którym metoda jest wykonywana (*this)
	*/
	Vector & add(const int value);

	/** @fn add
	* @brief Metoda dodająca do wektora wektor podany jako parametr
	* @param vectorToAdd Wektor, który chcemy dodać
	*/
	void add(Vector & vectorToAdd);

	/** @fn at
	* @brief Metoda zwracająca referencję do elementu wektora o indeksie podanym jako parametr
	* @param index Index elementu do którego chcemy zwrócić referencję
	*/
	int & at(const int index);
	
private:
	int * _vector; //wskaźnik do wektora
	int _size; //ilość elementów przechowywanych w wektorze

};