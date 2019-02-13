#pragma once
/**
* @namespace numutils
* @brief Przestrzeń nazw, w której znajdują się klasy służący do zbierania statystyk z przeglądania tablicy
*/
namespace numutils {
	/**
	* @class sum
	* @brief Klasa, której obiekty reprezentują sumę liczb przekazanych do nich za pomocą funktorów
	*/
	class sum {
		public:
			/**
			* @fn operator()
			* @brief Obiekty tej klasy są wykorzystywana jako funktory. Przekazanie liczby przy użyciu funktora zwiększa składową w tym obiekcie (sumę - _result) 
			* 		 o tę liczbę 
			* @param number Liczba o którą chcemy zwiększyć sumę
			*/
			void operator()(const int &number);

			/**
			* @fn result()
			* @brief Getter
			* @return Stała referencja do składowej obiektu będącej sumą wcześniej przekazanych liczb
			*/
			const int &result() const {return _result;}

		private:
			int _result = 0;
	};
	/**
	* @class average
	* @brief Klasa, której obiekty reprezentują średnią liczb przekazanych do nich za pomocą funktorów
	*/
	class average {
		public:

			/**
			* @fn operator()
			* @brief Obiekty tej klasy są wykorzystywana jako funktory. Przekazanie liczby przy użyciu funktora zwiększa składową w tym obiekcie (sumę - _sum) 
			*		 o tę liczbę oraz ilość przekazanych liczb (_count) o 1
			* @param number Liczba o którą chcemy zwiększyć sumę
			*/
			void operator()(const int &number);

			/**
			* @fn result()
			* @brief Getter
			* @return Średnia wcześniej przekazanych liczb.
			*/
			const double result() const {return _count ? (double)_sum / _count : 0;}

		private:
			int _sum = 0;
			int _count = 0;
	};

	class minmax {}; //klasa nieużywana, natomiast stworzono obiekt tego typu w mainie w itest.cpp	
}