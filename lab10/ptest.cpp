/* Tematem zadania jest zmiennosc obiektow stalych i konwersja niejawna.

   Zeby zdanie nie bylo nudne jest dodakowe cwiczenie z zabawy wskaznikami.

   UWAGA: Konwersje z int do std::string mozna zrobic kozystajac z funkcji std::to_string( int ).
   UWAGA: Obiekty klasy std::string mozna konkatenowac za pomoca +
 */

#include <iostream>
#include "Person.h"


bool byNameInv( const Person& p1, const Person& p2 ) {
  return not Person::byName( p1, p2 );
}

int main() {
  typedef const Person CPerson;  
  CPerson  *staff[4];
  staff[0] = new CPerson("Ewa", 56);
  staff[1] = new CPerson("Anna", 45);
  staff[2] = new CPerson("Piotr", 34);
  staff[3] = new CPerson("Pawel", 55);

  std::cout << static_cast<std::string>(*staff[3]) << std::endl; 

  
  for ( int i = 0; i < 4; ++i ) 
    staff[i]->print();

  staff[0]->swapID( staff[2] );
  std::cout << "Po zamianie\n";

  for ( int i = 0; i < 4; ++i ) 
    staff[i]->print();

  {
    CPerson** s1 =  Person::sort( staff, staff+4,  Person::byID );
    std::cout << "Po sortowaniu po ID\n";  
    for ( int i = 0; i < 4; ++i ) 
      s1[i]->print();    
    delete s1;
  }
  
  {
    CPerson** s1 = Person::sort( staff, staff+4,  byNameInv );
    std::cout << "Po sortowaniu byNameInv\n";  
    for ( int i = 0; i < 4; ++i ) 
      s1[i]->print();
    delete s1;
  }
  
  for ( int i = 0; i < 4; ++i ) 
    delete staff[i];
    
}
/* wynik
Pawel 55 3
Ewa lat: 56 ID: 0
Anna lat: 45 ID: 1
Piotr lat: 34 ID: 2
Pawel lat: 55 ID: 3
Po zamianie
Ewa lat: 56 ID: 2
Anna lat: 45 ID: 1
Piotr lat: 34 ID: 0
Pawel lat: 55 ID: 3
Po sortowaniu po ID
Piotr lat: 34 ID: 0
Anna lat: 45 ID: 1
Ewa lat: 56 ID: 2
Pawel lat: 55 ID: 3
Po sortowaniu byNameInv
Piotr lat: 34 ID: 0
Pawel lat: 55 ID: 3
Ewa lat: 56 ID: 2
Anna lat: 45 ID: 1
*/
