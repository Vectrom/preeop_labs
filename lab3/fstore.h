#pragma once

typedef struct _fstore {
	int (*function)(int);
	int argument; 
} fstore;

/**
@fn init
@brief funkcja inicjalizująca strukturę
@param f wskaźnik do struktury przechowującej wskaźnik do funkcji i argument
@param function wskaźnik do funkcji, którą chcemy umieścić w strukturze
@param arg argument, który chcemy umieścić w strukturze
*/
void init(fstore *f, int (*func)(int), int arg);


/**
@fn call
@brief funkcja wywołująca funkcję przechowywaną w strukturze z argumentem wcześniej zadanym
@param f wskaźnik do struktury przechowującej wskaźnik do funkcji i argument
@return liczba otrzymana w wyniku działania funkcji przechowywanej przez strukturę z wcześniej zadanym argumentem
*/
int call(fstore *f);

/**
@fn call
@brief funkcja wywołująca funkcję przechowywaną w strukturze z argumentem podanym jako parametr
@param f wskaźnik do struktury przechowującej wskaźnik do funkcji i argument
@param arg argument z którym chcemy wywołać funkcję przechowaną w strukturze
@return liczba otrzymana w wyniku działania funkcji przechowywanej przez strukturę z argumentem podanym jako parametr
*/
int callWithArg(fstore *f, int arg);