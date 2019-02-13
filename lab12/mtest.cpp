// Tablica asocjacyjna
//
// To taka tablica, ktorej indeksy sa nieograniczone do kolejnych liczb calkowitych
//  0...N a nawet nie musza byc liczbami. W tym przypadku sa napisami. 
// W zadaniu nalezy napisac tablice asocjacyjna gdzie indeksem jest napis 
// (wybiegamy w przyszlosc, prosze uzyc klasy string).
// a wartosci sa dwojakiego typu albo int.
//

// Klasa Map powinna deklarowac pomocne typy key_type (indeks)
// i value_type(wartosci).
//
// 
// Implementacja wnetrza moze byc prosta tablica rozszerzana podczas kazdej 
// operacji insert() (badz podczas odwolania sie za pomoca []) 
// Prosze przemyslec zawartosc klasy troche. 
//
// Prosze nie zmieniac nazwy tego pliku.
// Prosze koniecznie kompilowac z opcja -Wall. 
//

#include <iostream>
#include <string>


#include "Map.h"


int main() {
  using namespace std;
  Map m;
  m.insert("hello", 4009 ); 
  m.insert("hello2", 509 ); 
  m.print(".. przed nadpisaniem");
  m["hello3"] = 7887; // tu nastapi dodanie elementu do tablicy
  m["hello2"] = 7; // tu mamy nadpisanie zawartosci
  m.print(".. po nadpisaniu");

  const Map& cm = m;  // testujemy staly interfejs

  cout << "Co tam pod hello2 " << cm["hello2"] << endl;
  cout << "Czy jest hello4 " << cm.contains("hello4") << endl;
  Map::key_type k = "hello3"; // testujemy przedstawienie typow
  cout << "Czy jest hello3 " << cm.contains(k) << endl;
  Map::value_type v = cm[k];
  cout << "Czy jest pod: " << k  << " " << v << endl;
}

/* wyniki 
.. przed nadpisaniem k: hello v: 4009
.. przed nadpisaniem k: hello2 v: 509
.. po nadpisaniu k: hello v: 4009
.. po nadpisaniu k: hello2 v: 7
.. po nadpisaniu k: hello3 v: 7887
Co tam pod hello2 7
Czy jest hello4 0
Czy jest hello3 1
Czy jest pod: hello3 7887


 
 */
