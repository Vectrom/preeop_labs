#pragma once

/** @struct Ext
@brief Struktura rozszerzalnego wektora przechowującego liczby całkowite
@var data wskaźnik do tablicy z danymi
@var data_size ilość liczb przechowywanych w wektorze
@var capacity pojemność wektora w danej chwili
@var function_pointer wskaźnik do funkcji zwracającej pojemność wektora po realokacji
*/
struct Ext {
	int *data;
	int data_size;
	int capacity;
	int (*function_pointer)(int);
};

/** @fn init 
@brief Funkcja inicjalizująca nowy defaultowy wektor (z początkową pojemnością = 5 i z liniowym wzrostem pojemnosci o 5), alokująca pamięć na dane
@param struct_pointer wskaźnik do struktury - wektora, który chcemy zainicjalizować
*/
void init(Ext *struct_pointer);

/** @fn initWithSizeAndPolicy Funkcja inicjalizująca nowy wektor z początkową pojemnością oraz wskaźnikiem do funkcji zwracającej nową pojemność po realokacji podanymi jako parametr i alokująca pamięć na dane
@param struct_pointer wskaźnik do struktury - wektora, który chcemy zainicjalizować
@param size początkowa pojemność wektora z danymi
@param function_pointer wskaźnik do funkcji zwracającej nową pojemność po realokacji
*/
void initWithSizeAndPolicy(Ext *struct_pointer, int size, int (*function_pointer)(int));
                        
/** @fn size
@brief Funkcja zwracająca ilość liczb zapisanych w wektorze
@param struct_pointer wskaźnik do struktury - wektora, którego rozmiar chcemy otrzymać
@return rozmiar wektora na który wskazuje parametr struct_pointer
*/  
int size(Ext *struct_pointer);

/** @fn capacity
@brief Funkcja zwracająca aktualną pojemność wektora
@param struct_pointer wskaźnik do struktury - wektora, którego pojemność chcemy otrzymać 
@return pojemność wektora na który wskazuje parametr struct_pointer
*/  
int capacity(Ext *struct_pointer);

/** @fn insert
@brief Funkcja dodająca nową liczbę całkowitą do wektora, a gdy rozmiar osiągnie maksymalną pojemność - realokująca pamięć na nowe dane
@param struct_pointer wskaźnik do struktury - wektora, do którego chcemy dodać nową liczbę
@param elem liczba całkowita którą chcemy dodać do wektora
*/  
void insert(Ext *struct_pointer, int elem);

/** @fn at
@brief Funkcja zwracająca wartość zapisaną w wektorze pod indeksem podanym jako parametr
@param struct_pointer wskaźnik do struktury - wektora, z którego chcemy pobrać wartość elementu o podanym indexie
@param index index elementu, który chcemy pobrać
@return element znajdujący się w wektorze na pozycji index;
*/  
int at(Ext *struct_pointer, int index);

/** @fn clear
@brief Funkcja zwalniająca pamięć zajętą przez tablicę z danymi zapisanymi w wektorze
@param struct_pointer
*/  
void clear(Ext *struct_pointer);

/** @fn linear_size
@brief Funkcja zwracająca nową pojemność na którą powinniśmy realokować tablicę z danymi dla defaultowego wektora (o 5 większą od poprzedniej)
@param old_size pojemność wektora przed realokacją
@return pojemność na którą powinniśmy realokować tablicę z danymi
*/ 
int linear_size(int old_size);