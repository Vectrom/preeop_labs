#pragma once

/** @class MyString
* @brief Klasa, której obiektami są łańcuchy znaków. Można na jej obiektach wykonywać operacje łączenia, zamiany.
*/
class MyString {
	public:
		/** @fn Mystring
		* @brief Konstruktor tworzący nowy obiekt i kopiujący wartość podaną jako parametr do tego obiektu.
		* @param string łańcuch znakowy, który chcemy skopiować do nowo utworzonego obiektu
		*/
		MyString(const char * string);

		/** @fn str
		* @brief Metoda zweacająca wartość łańcucha znakowego zapisanego w obiekcie.
		*/
		char * str() const;

		/** @fn setStr
		* @brief Metoda zmieniająca wartość atrybutu przechowującego łańcuch znaków w obiekcie
		* @param string Wskaźnik do nowego atrybutu, który chcemy zapisać w obiekcie
		*/
		void setStr(char * string);

		/** @fn join
		* @brief Metoda dołączająca łąńcuch znaków w obiekcie podanym jako parametr do łańcucha znaków obiektu na którym jesy wywoływana
		* @param string Obiekt, którego atrybut (łańcuch znaków) chcemy dołączyć do atrybutu obiektu na którym jest wywoływana
		*/
		void join(const MyString & string);

		/** @fn replace
		* @brief Metoda zamieniająca łańcuch znaków zapisany w obiekcie na ten podany jako parametr
		* @param string Łańcuch znaków, który chcemy zapisać w obiekcie zamiast poprzedniego
		*/
		void replace(const char * string);

		/** @fn ~Mystring
		* @brief Destruktur zwalniający pamięć zaalokowaną na łańcuchy znaków i wyświetlający komunikat o jej zwolnieniu.
		*/
		~MyString();

	private:
		char * _string;
};

/** @fn swap
* @brief Funkcja zamieniająca łańcuchy znaków zapisane w dwóch obiektach
*/
void swap(MyString & s1, MyString & s2);