/* Celem zadania jest napisanie rozszerzanlnego wektora liczb calkowitych.
 Waznym aspektem takiego wektora jest polityka zajmowania pamieci (np wzrost liniowy czy wykladniczy).

 Domniemany (defaultowy) wektor jest zaalokowany na 5 elementow i po przekroczeniu objetosci nastepuje realokacja 
 i wektor posiada zaalokowane miejsce dla 10 elementow. Gdy chcemy dodac element 11-ty nastepuje ponowna 
 realokacja i wektor posiada 15 miejsc, itd.

 Implementacja ma umozliwiac tez podanie funkcji zwracajacej wymagany rozmiar po realokacji. W tym wariancie mozemy tez zadac wstepny rozmiar. 
 
 Jako sposob przechowywania danych nalezy uzyc tablicy alokowanej dynamicznie za pomoca new.

 Prosze kompilowac do pliku wykonywalnego rtest z opcjami -Wall -g.
*/

#include <iostream>
using namespace std;

#include "ext.h"
#include "ext.h"

int new_size(int sz) {
  return 2*sz;
}

int main() {
  struct Ext extLin;
  struct Ext extExp;
  init(&extLin);
  initWithSizeAndPolicy(&extExp, 2, new_size);
  
  for ( int i = 0; i < 21; i++ ) {
    cout << "rozmiar Lin "<< size(&extLin)
	 << " Exp " << size(&extExp) // ilosc uzywanych miejsc w tablicy
	 << " pojemosc Lin " << capacity(&extLin) // ilesc miejsc dostepnych zanim musi dojsc do nastepnej alokacji
	 << " Exp " << capacity(&extExp) << endl;
    insert(&extLin, i); // dodajemy na koncu
    insert(&extExp, i);
  }

  for ( int i = 0; i < size(&extLin); i++ ) {
    cout << "pod indeksem "<<  i
	 << " " << at(&extLin, i) // pobieramy spod indeksu i
	 << " Exp " << at(&extExp, i) << endl;    
  }

  clear(&extLin);
  clear(&extExp);
}
/* wynik dzialania
rozmiar Lin 0 Exp 0 pojemosc Lin 5 Exp 2
rozmiar Lin 1 Exp 1 pojemosc Lin 5 Exp 2
rozmiar Lin 2 Exp 2 pojemosc Lin 5 Exp 4
rozmiar Lin 3 Exp 3 pojemosc Lin 5 Exp 4
rozmiar Lin 4 Exp 4 pojemosc Lin 5 Exp 8
rozmiar Lin 5 Exp 5 pojemosc Lin 10 Exp 8
rozmiar Lin 6 Exp 6 pojemosc Lin 10 Exp 8
rozmiar Lin 7 Exp 7 pojemosc Lin 10 Exp 8
rozmiar Lin 8 Exp 8 pojemosc Lin 10 Exp 16
rozmiar Lin 9 Exp 9 pojemosc Lin 10 Exp 16
rozmiar Lin 10 Exp 10 pojemosc Lin 15 Exp 16
rozmiar Lin 11 Exp 11 pojemosc Lin 15 Exp 16
rozmiar Lin 12 Exp 12 pojemosc Lin 15 Exp 16
rozmiar Lin 13 Exp 13 pojemosc Lin 15 Exp 16
rozmiar Lin 14 Exp 14 pojemosc Lin 15 Exp 16
rozmiar Lin 15 Exp 15 pojemosc Lin 20 Exp 16
rozmiar Lin 16 Exp 16 pojemosc Lin 20 Exp 32
rozmiar Lin 17 Exp 17 pojemosc Lin 20 Exp 32
rozmiar Lin 18 Exp 18 pojemosc Lin 20 Exp 32
rozmiar Lin 19 Exp 19 pojemosc Lin 20 Exp 32
rozmiar Lin 20 Exp 20 pojemosc Lin 25 Exp 32
pod indeksem 0 0 Exp 0
pod indeksem 1 1 Exp 1
pod indeksem 2 2 Exp 2
pod indeksem 3 3 Exp 3
pod indeksem 4 4 Exp 4
pod indeksem 5 5 Exp 5
pod indeksem 6 6 Exp 6
pod indeksem 7 7 Exp 7
pod indeksem 8 8 Exp 8
pod indeksem 9 9 Exp 9
pod indeksem 10 10 Exp 10
pod indeksem 11 11 Exp 11
pod indeksem 12 12 Exp 12
pod indeksem 13 13 Exp 13
pod indeksem 14 14 Exp 14
pod indeksem 15 15 Exp 15
pod indeksem 16 16 Exp 16
pod indeksem 17 17 Exp 17
pod indeksem 18 18 Exp 18
pod indeksem 19 19 Exp 19
pod indeksem 20 20 Exp 20
 */
