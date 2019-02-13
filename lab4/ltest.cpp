/* W zadaniu prosze napisac liste polaczona jednokierunkowo, sluzaca do przechowywania napisow (lancuchow znakow).
   UWAGA. Napisy musza byc kopiowane do alokowanej pamieci. Nalezy tez zadbac o zwolnienie pamieci przy czyszczeniu listy (sprawdzic z valgrind-em).
   UWAGA. Niektore z funkcji nie zmieniaja listy (np. dump) i z tego powodu powinny odbierac staly wskaznik do struktury List.

   Kompilwac koniecznie z flagami -Wall -g
   Plik wykonywalny prosze nazwac "ltest".   
 */


#include <iostream>
#include "List.h"
#include "List.h"

int main() {
  List testList;
  prepare(&testList);
  const List* lptr = &testList;
  char buffer[100];
  
  strcpy(buffer, "Ala");
  add(&testList, buffer);
  
  strcpy(buffer, "ma");
  add(&testList, buffer);
  
  strcpy(buffer, "kota.");
  add(&testList, buffer);

  std::cout << "empty() " << empty(lptr) << std::endl;
  std::cout << lptr->head->data << std::endl;
  std::cout << lptr->head->next->data << std::endl;
  dump(lptr);
  std::cout << "\n";

  
  List testList2;
  prepare(&testList2);
  strcpy(buffer, "Maraton to");
  add(&testList2, buffer);

  strcpy(buffer, "wyczyn");
  add(&testList2, buffer);


  
  clear(&testList);
  std::cout << "empty() " << empty(lptr) << std::endl;
  dump(lptr);
  std::cout << "\n";
  
  
  dump(&testList2);
  std::cout << "\n";
  
  clear(&testList2);
}
/* wynik
empty() 0
Ala
ma
Ala ma kota. 
empty() 1

Maraton to wyczyn 
 */
