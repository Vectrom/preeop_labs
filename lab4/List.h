#pragma once
#include <cstring>
/**
@struct Node Struktura pojedynczego elementu listy
@var next Wskaźnik do następnego elementu listy
@var data Wskaźnik do łańcucha znakowego umieszczonego w tym elemencie
*/
typedef struct Node {
	struct Node * next;
	char * data;
} Node;

/**
@struct Node Struktura pojedynczej listy połączonej
@var head Wskaźnik do głowy (pierwszego elementu) listy
@var tail Wskaźnik do ogona (ostatniego elementu) listy
*/

typedef struct List {
	struct Node * head;
	struct Node * tail;
} List;

/**
@fn prepare
@brief Funkcja przygotowująca listę i ustawiająca jej głowę i ogon na wartość nullptr
@param list_pointer Wskaźnik do listy, którą chcemy przygotować
*/
void prepare(List * list_pointer);

/**
@fn add
@brief Funkcja dodająca łańcuch znakowy podany jako parametr na koniec listy
@param list_pointer Wskaźnik do listy, do której chcemy dodać element
*/
void add(List * list_pointer, const char * buffer);

/**
@fn empty
@brief Funkcja sprawdzająca czy lista jest pusta.
@param list_pointer Wskaźnik do listy
@return true dla pustej listy, false dla listy niepustej.
*/
bool empty(const List * list_pointer);

/**
@fn dump
@brief Funkcja wyświetlająca łańcuchy znakowe dodane do listy oddzielone spacjami
@param list_pointer Wskaźnik do listy, z której łańcuchy znakowe chcemy wyświetlić.
*/
void dump(const List * list_pointer);

/**
@fn clear
@brief Funkcja zwalniająca pamięć zaalokowaną na potrzeby listy i ustawiająca jej głowę i ogon na nullptr
@param list_pointer Wskaźnik do listy, którą chcemy wyczyścić i zwolnić pamięć
*/
void clear(List * list_pointer);

/**
@fn new_node
@brief Funkcja przygotowująca nowy element listy, alokująca pamięć na niego i kopiująca do niego łańcuch znakowy podany jako parametr
@param Wskaźnik do łańcuch znaków, który chcemy umieścić w nowym elemencie listy
@return Wskaźnik do nowoutworzonego elementu listy.
*/
Node * new_node(const char * buffer);