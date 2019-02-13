#pragma once
/**
* @class itr
* @brief Klasa będąca iteratorem pozwalających przeglądać tablicę int 
*/
class itr {
	public:
		/**
		* @fn itr
		* @brief Konstruktor. Ustawia składowe obiektu na takie jak przekazane przez parametr
		* @param tab Wskaźnik do tablicy, po której zamierza się iterować
		* @param count Ilość liczb po których chcemy iterować
		*/
		itr(int *tab, const int &count) : _tab(tab), _count(count) {}

		/**
		* @fn operator*
		* @brief Przeciążenie operatora *.
		* @return Stała referencja do liczby, na którą obecnie wskazuje iterator.
		*/
		const int &operator*() const;
		
		/**
		* @fn operator++
		* @brief Przeciążenie operatora ++. Operator ten przechodzi do następnego elementu tablicy i zmniejsza ilość liczb pozostałych do przeiterowania.
		*/

		void operator++();
		
		/**
		* @fn operator bool
		* @brief Przeciążenie operatora konwersji bool()..
		* @return true jeśli pozostał jeszcze jakiś element do przeiterowania, false w przeciwnym razie.s
		*/
		operator bool();

	private:
		int *_tab;
		int _count;
};