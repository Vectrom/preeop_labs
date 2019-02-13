#include <iostream>
#include "Map.h"

Map::~Map() {
    if (_elements)
        delete[] _elements;
}

void Map::insert(const Map::key_type &key, const Map::value_type &value) {
    (*this)[key] = value;
}

void Map::print(const Map::key_type &text) const {
    for (int i = 0; i < _size; i++) {
        std::cout << text << " ";
        _elements[i].print();
        std::cout << std::endl;
    }
}

const bool Map::contains(const Map::key_type &key) const {
    for (int i = 0; i < _size; i++) {
        if (key == _elements[i]._key)
            return true;
    }
    return false;
}

Map::value_type &Map::operator[](const Map::key_type &key) {
    for (int i = 0; i < _size; i++) {
        if (key == _elements[i]._key)
            return _elements[i]._value;
    }

    MapElement *tmp = _elements;   

    _size++;
    _elements = new MapElement[_size];

    for (int i = 0; i < _size - 1; i++) {
        _elements[i] = tmp[i];
    }

    if (_size)
        delete[] tmp;

    _elements[_size - 1]._key = key;
    return _elements[_size - 1]._value;
}

const Map::value_type &Map::operator[](const Map::key_type &key) const {
    for (int i = 0; i < _size; i++) {
        if (key == _elements[i]._key)
            return _elements[i]._value;
    }
    return _elements[0]._value;;
}

MapElement::MapElement(const MapElement &element) {
    _key = element._key;
    _value = element._value;
}

void MapElement::print() const {
    std::cout << "k: " << _key << " v: " << _value;
}