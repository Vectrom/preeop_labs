// Macierze
// 
// To jest powtorzenie zadania 1go tylko w wersji obiektowej.
// Nalezy napisac dwie klasy Vector i Matrix i opatrzyc je odpowiednimi operacjami.
// 
// Prosze zastanowic sie jaka jest relacja miedzy klasami Vector i Matrix. 
// A w szczegolnosci jak mozna oszczedzic sobie duzego wysilku uzywajac
// jednej z pow. klas w drugiej.
//
// Pomocne moze byc przeczytanie kodu demonstrujacego operacje na obiekcie dim4. 
// 
// Jak zwykle przed napisaniem kazdej deklaracji nalezy zadbac o const-correctness.
//
// Prosze nie zmieniac nazwy tego pliku. Kompilowac z opcja -Wall. 
// 

#include <iostream>
#include "Matrix.h"
#include "Matrix.h"

#include "Vector.h"


int main() {
  using namespace std;
  Vector xyz(3 , 1.); // wektor o wp. [1,1,1]
  cout << "wejsciowy wektor   "; xyz.print(); cout << endl;
  xyz.mul(2);
  cout << "wejsciowy wektor   "; xyz.print(); cout << endl;
  xyz.add(5).add(1);
  cout << "wejsciowy wektor   "; xyz.print() ; cout << endl;


  Vector x(3, 4.);
  x.at(0) = 1;
  x.at(2) = -1; 
  cout << "wyjsciowy wektor X "; x.print(); cout << endl;

  xyz.add( x );

  Matrix dim4(4,4, 2); // macierz 4 x 4 wypelniona 2-jkami
  dim4.at(0).mul(2); // 0 wiersz monozymy przez 2 (to wazna linia, pokazuje jak zbudowany jest obiekt klasy Matrix)
  dim4.at(1).add(-2); // od 1 wiersza odejmujemy 2 
  
  const Matrix& cdim4 = dim4;
  cdim4.print();

}
/* wynik
wejsciowy wektor   1 1 1 
wejsciowy wektor   2 2 2 
wejsciowy wektor   8 8 8 
wyjsciowy wektor X 1 4 -1 
4 4 4 4 
0 0 0 0 
2 2 2 2 
2 2 2 2
 */
