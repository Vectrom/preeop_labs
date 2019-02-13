#pragma once

class MapElement;

/** 
 * @class Map
 * @brief Klasa reprezentująca tablicę asocjacyjną (mapę, słownik)
 **/
class Map {
public:
    typedef std::string key_type;
    typedef int value_type;

/**
 * @fn ~Map
 * @brief Destruktor, zwalnia pamięć zajętą na elementy przechowywane w mapie
 **/
    ~Map();

/**
 * @fn insert
 * @brief Alokuje pamięć i wstawia element o podanym kluczu i wartości do mapy
 * @param key Klucz elementu dodawanaego do mapy
 * @param value Wartość elementu dodawanego do mapy
 **/
    void insert(const key_type &key, const value_type &value);

/**
 * @fn print
 * @brief Wyświetla tekst podany jako parametr oraz zawartość mapy.
 * Każda linia zawiera tekst podany jako parametr oraz klucz i wartość jednego elementu
 * @param text Tekst do wyświetlania przed wyświetleniem zawartości każdego z elementów
 **/
    void print(const key_type &text) const;

/**
 * @fn contains
 * @brief Sprawdza czy element o kluczu podanym jako parametr znajduje się w mapie
 * @param key Klucz elementu, którego obecność w mapie zostaje sprawdzona
 * @return true jeśli element o podanym kluczu znajduje się mapie, false w przeciwnym przypadku
 **/
    const bool contains(const key_type &key) const;

/**
 * @fn operator[]
 * @brief Przeciąża operator [], jeśli w mapie znajduje się element o kluczu podanym jako parametr to zwraca referencję do jego wartości.
 * W przeciwnym wypadku alokuje pamięć na nowy element o podanym kluczu i zwraca referencję do jego wartości.
 * @param key Klucz do elementu do którego wartości zostanie zwrócona referencja
 * @return Referencja do wartości elementu o kluczu podanym jako parametr
 **/
    value_type &operator[](const key_type &key);

/**
 * @fn operator[]
 * @brief Przeciąża operator [], jeśli w mapie znajduje się element o kluczu podanym jako parametr to zwraca stałą referencję do jego wartości.
 * W przeciwnym wypadku zwraca stałą referencję do pierwszego elementu w mapie.
 * @param key Klucz do elementu do którego wartości zostanie zwrócona stała referencja
 * @return Stała referencja do wartości elementu o kluczu podanym jako parametr
 **/
    const value_type &operator[](const key_type &key) const;

private:
    MapElement *_elements = nullptr;
    value_type _size = 0;
};

/** 
 * @class MapElement
 * @brief Klasa pomocnicza reprezentująca pojedynczy element przechowywany w tablicy asocjacyjnej Map
 **/
class MapElement {
    friend class Map;

public:
/**
 * @fn MapElement
 * @brief Ustawienie konstruktora bezargumentowego na konstruktor domyślny
 **/
    MapElement() = default;

/**
 * @fn MapElement
 * @brief Konstruktor kopiujący wartość i klucz elementu przekazanego jako parametr do tych wartości w tworzonym obiekcie
 * @param text Element który ma zostać skopiowany
 **/
    MapElement(const MapElement &element);

/**
 * @fn print
 * @brief Wypisuje klucz i wartość elementu
 **/
    void print() const;

private:
    Map::value_type _value;
    Map::key_type _key;
};