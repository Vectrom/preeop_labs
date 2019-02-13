/*
 * Celem zadanie jest napisanie klasy: itr - to jest iterator sluzacy do
 * przegladania zawartosci tablicy intow. Przyklad uzycia jest na poczatku przykladu.
 * Funkcja foreach sluzy do wykonania pewnych operacji na iterowanych elementach. 
 * Nie znamy dziedziczenia wiec trzeba uzyc innej techniki, mianowicie klasy 
 * funktorow sa rzutowalne na std::function, zatem bedzie mozna przekazac rozne 
 * obiekty funktorow jako drugi argument do f. foreach jesli tylko odbieramy std::function 
 * Oczywiscie ilosc argumentow funktora i typ zwracany musi sie zgadzac z typem 
 * w szablonie std::function.
 *
 * Funktory sum,average w przestrzeni numutils sluza
 * do zbierania statystyk z przegladniecia tablicy. 
 *
 * Skompilowac z flagami -g -Wall do pliku test.
 */

#include <iostream>
#include "foreach.h"
#include "itr.h"
#include "numutils.h"

int main() {
  using namespace std;
  int array[7] = {2,2,3,3,7,1,0};

  numutils::sum sum1;
  numutils::average average;
  numutils::minmax minmax;

  cout << " wypiszmy 3 od 3ciego " << endl;
  itr z(array+3, 3);
  while ( z ) {
    std::cout << *z << std::endl;
    ++z;
  }

  cout << " wypiszmy " << endl;
  for ( itr it = itr(array, 7) ; it ; ++it )  {
    cout << *it << endl;
  }

  // std::ref uzyte jest tutuaj aby przekazac funktor przez referencje,
  // w przeciwnym razie std::function kopiuje ten funktor i operacje
  // na nim wykonywane nie maja wplywu na obiekt, ktory zostal przkazany.
  // To znaczy jego atrybuty (np. suma) nie sa zmieniane.
  
  foreach(itr(array, 7), std::ref(sum1)); 
  sum1(2); // dodajemy jeszcze jeden UWAGA wazna podpowiedz!
  cout << "suma "<<sum1.result() << endl;

  foreach(itr(array, 7), std::ref(average));
  cout << "srednia " << average.result() << endl;
  
}
/* wynik
 wypiszmy 3 od 3ciego 
3
7
1
 wypiszmy 
2
2
3
3
7
1
0
suma 20
srednia 2.57143
 */
