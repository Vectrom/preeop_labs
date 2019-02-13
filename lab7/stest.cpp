/*
 Celem zadania jest porownanie implementacji z uzyciem klas i struktur.
 Zadanie jest wariantem poprzednego.

 
 UWAGA: W zadaniu nie mozna uzyc klasy std::string. Tj. musi byc to zrobione na char*.
 UWAGA: W klasie MyString mozen miec wiecej przydatnych method niz te, ktore sa uzyte w przykladzie.

 */

#include <iostream>
#include "MyString.h"
#include "MyString.h"

int main() {
  
  MyString s1("witaj");
  std::cout << s1.str() << std::endl;

  const MyString s2("swiecie");
  
  s1.join(s2); // zmieniamy wnetrze klasy
  std::cout << s1.str() << std::endl;

  s1.replace("jest");

  MyString s3("ciekawie");
  std::cout << "przed zamiana: " << s1.str()  << " " << s3.str() << std::endl;
  swap(s1, s3);
  std::cout << "po zamianie: " << s1.str()  << " " << s3.str() << std::endl;

}
/* wyniki
witaj
witajswiecie
przed zamiana: jest ciekawie
po zamianie: ciekawie jest
- deleting jest
- deleting swiecie
- deleting ciekawie
   
*/
