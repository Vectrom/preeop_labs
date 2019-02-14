/**
 * Celem zadania jest napisanie klasy StringWrapper
 * Klasa ta posluzyc ma do ulatwienia operacji na napisach.
 * W tym celu do klasy dodano operatory + i * a takze mozna obiekty tej klasy wypisywac.
 * Dostepne sa takze naturalne operatory = i ==.
 *
 * Trudnoscia w zadaniu jest sprawne zarzadzanie pamiecia. 
 * UWAGA: Nie wolno uzywac w implementacji klasy std::string. (zadanie nie na temat 0pkt).
 * Kompilowac z flagami -Wall -g
 */

#include <iostream>

#include <string.h>
#include "StringWrapper.h"

using namespace std;

int main() {
  StringWrapper s0("Witaj Swiecie");  
  StringWrapper s1("Witaj swiecie");
  const StringWrapper s2("Witaj swiecie");  

  if (s0 == s1 )  
    cout << " s0 i s1 sa identyczne" << endl;
  if (s1 == s2 )  
    cout << " s1 i s2 sa identyczne" << endl;
  if (s2 == s1 )  
    cout << " s2 i s1 sa identyczne" << endl;
  // kolejnosc zmiennych w wyr == zmieniona aby wymuscic poprawnosc const

  std::cout << s1 << std::endl;  
  std::cout << s2 +" tu i teraz," << std::endl; 
  StringWrapper sum = s1 + "." + s1 + " - " + s2+"----";
  std::cout << sum << std::endl;

  StringWrapper mult = 2*StringWrapper("*");
  std::cout << mult << " " << (const StringWrapper&)mult*4 << std::endl;
  mult = s1;
  std::cout << "mult " << mult << std::endl;
  
}
/* wynik
 s1 i s2 sa identyczne
 s2 i s1 sa identyczne
Witaj swiecie
Witaj swiecie tu i teraz,
Witaj swiecie.Witaj swiecie - Witaj swiecie----
** ********
mult Witaj swiecie
*/
