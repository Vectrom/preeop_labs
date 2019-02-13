#pragma once
#include <iostream>

// Klasa Ksztalt jest klasą abstrakcyjną, której obiekty są jakimiś kształtami
// Klasy Kwadrat, Kolo i Trojkat dziedziczą z klasy Ksztalt, poniewaz dzieki temu mozliwe jest zastosowanie metod wirtualnych
// Dzieki temu jesli wykonujemy metodę z obiektu na który wskazuje wskaźnik klasy bazowej (Ksztalt) wykonana zostanie odpowiednia metoda dla danego ksztaltu
// (w tym przypadku metoda zwracajaca pole powierzchni danej figury lub wypisująca informacje o danym obiekcie (nazwa i dlugosc boku/bokow/promienia))
// Przyklad takiego uzycia jest w funkcji void wypisz(const Ksztalt & ksztalt); która wykonuje odpowiednią metodę void wypisz(std::ostream& o) dla obiektu
// a także w mainie podczas wykonywania funkcji polePow(); (wykonuje sie odpowiednia metoda w zaleznosci od obiektu).
class Ksztalt {
	public:
		virtual const double polePow() const = 0;
		virtual void wypisz(std::ostream& o) const = 0;
		friend void wypisz(const Ksztalt & ksztalt);
		virtual ~Ksztalt() = default;
};

