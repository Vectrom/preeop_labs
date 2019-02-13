/*
 Celem zadania jest napisanie kilku klas ziwaznych relacja
 dziedziczenia.  Klasy te opisuja elementarne ksztalty. Kazdy ksztalk
 posiada jakies polimorficzne metody i konieczna infrastrukture.
 
 Kompilwac z opcjami -Wall -g do pliku stest
 UWAGA: Przed rozpoczeciem pisania prosze przeczytac zadanie do konca.
 UWAGA: W tym zadaniu: PI to 3.1415. Wzor na pole trojkata: sqrt( x(x-a)(x-b)(x-c) ) 
 gdzie "x" to polowa obwodu trojkata.
 
 */

#include <iostream>
#include "Kwadrat.h"
#include "Kolo.h"
#include "Trojkat.h"

int main() {
  Kwadrat k(4);
  Trojkat t(3,2,4);
  const Kolo    ko(3);

  wypisz(k); // ma wypisac: Kwadrat o boku: 4
  wypisz(t); // ma sypisac: Trojkat o bokach: 3 2 4
  wypisz(ko);// ma wypisac: Kolo o promieniu: 3

  Ksztalt* b = new Kwadrat(7);
  wypisz(*b);
  delete b;
  
  b = new Kolo(7);
  wypisz(*b);
  delete b;
  
  const Ksztalt* wszystkie[] = {&k, &k, &ko, &t, &ko}; // obiekty powtorzone celowo
  for ( int idx = 0; idx < sizeof(wszystkie)/sizeof(Ksztalt*); ++idx ) {
    const Ksztalt* k = wszystkie[idx];
    k->wypisz(std::cout); 
    std::cout << k->polePow() << std::endl;
  }  
}
/* wynik
Kwadrat o boku:4
Trojkat bokach:3 2 4
Kolo o promieniu:3
Kwadrat o boku:7
Kolo o promieniu:7
Kwadrat o boku:4
16
Kwadrat o boku:4
16
Kolo o promieniu:3
9.4245
Trojkat bokach:3 2 4
2.90474
Kolo o promieniu:3
9.4245

 */
