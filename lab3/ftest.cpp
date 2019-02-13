/*
  Celem zadania jest napisanie pomocnej struktory, ktora pozwoli 
  na przechowanie funkcji i jej argumentu.
  
  Tak przechowane funkcje mozna wywolac z argumentem wczesniej zadanym - "call"
  
  badz mozna dostarczyc nowych wartosci argumentow - "callWithArg"
  
  Kompilowac z flagami -Wall -g do pliku ftest

 */

#include <iostream>

#include "fstore.h"
#include "fstore.h"

int printit( int arg ) {
  std::cout << "XXX " <<  arg << " XXX" << std::endl;
  return 0;
}

int mul2( int arg ) {  
  return arg * 2;
}

int add2( int arg ) {  
  return arg + 2;
}


int main() {
  fstore f1;
  init( &f1,  printit, 7 );
  call( &f1 );

  fstore nf[2];
  init( &(nf[0]), mul2, 6 );
  init( &(nf[1]), add2, 7 );

  for ( int i = 0; i < 2; ++i ) {
    std::cout << call( &nf[i] ) << "\n";
  }

  for ( int i = 1; i >= 0; --i ) {
    std::cout << callWithArg( &nf[i], 10 ) << "\n";
  }        
}
/* wynik
XXX 7 XXX
12
9
12
20
 */
