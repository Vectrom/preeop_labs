/*
  Celem zadania jest napisanie kopiowalnej polaczonej listy.
  Zadanie posiada kilka haczykow. W szczegolnosci konstruktor kopiujacy, 
  metode zwracajaca referencje do obiektu, na rzecz ktorego jest wywolana a takze enumeracje.

  UWAGA: Prosze dobrze wykorzystac kod, ktory sie napisalo! Copy/paste jest czystym zlem.
  UWAGA: Klasy powinny zapewniac enkapsulacje (takze klasa Node).
  UWAGA: Prosze przemyslec "poprawnosc const" od poczatku.
 */
#include <iostream>
#include "List.h"


void findAndPrint(const List& l, int elValue) {
  const Node* n = l.find(elValue);
  if ( n )
    std::cout << "Znaleziono " << n->data() << std::endl;
  else
    std::cout << "Brak " << elValue << std::endl;
}

int main() {
  List a;
  a.insert(10, List::Begin); // wkladamy na poczatek
  a.insert(11, List::End); // na koniec
  a.insert(2,  List::Begin); // znow na poczatek
  a.insert(13, List::End);
  a.insert(7).insert(6); // po wyniki mozna poznac gdzie dodane sa elementy 7 i 6
  
  a.print();
  findAndPrint(a, 3);
  findAndPrint(a, 7);

  List b(a);
  b.insert(99);
  std::cout << "Lista a" << std::endl;
  a.print();
  std::cout << "Lista b" << std::endl;
  b.print();
  // tu uruchamiaja sie destruktory
}
/* wyniki 
[  2 10 11 13 7 6] 
Brak 3
Znaleziono 7
Lista a
[  2 10 11 13 7 6] 
Lista b
[  2 10 11 13 7 6 99] 

 */
