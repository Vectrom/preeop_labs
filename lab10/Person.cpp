#include <iostream>
#include <string>
#include "Person.h"

	int Person::_lastID = 0;


	Person::Person(const std::string name, const int & age) :_name(name), _age(age),  _ID(Person::_lastID){
		Person::_lastID++;
	}

	void Person::print() const {
		std::cout << _name << " lat: " << _age << " ID: " << _ID << std::endl;
	}

	void Person::swapID(const Person * p) const {
		int tmp = p->_ID;
		p->_ID = _ID;
		_ID = tmp;

	}

	const Person ** Person::sort(const Person ** from, const Person ** to, sortType type){
		const Person ** sortedTab = new const Person*[to - from];
		for(int i = 0; i < to - from; i++) {
			sortedTab[i] = from[i];
		}
		
		for(int i = 0; i < to - from; i++) {
			const Person * key = sortedTab[i];
			int j = i - 1;
			while (j >= 0 && type(*key, *sortedTab[j])) {
				sortedTab[j + 1] = sortedTab[j];
				j--;
			}
			sortedTab[j + 1] = key;
		}
		return sortedTab;
	}

	bool Person::byName(const Person& p1, const Person& p2) {
		return p1._name < p2._name;
	}

	bool Person::byID(const Person& p1, const Person& p2) {
		return p1._ID < p2._ID;
	}

	Person::operator std::string() const{
		return _name + " " + std::to_string(_age) + " " + std::to_string(_ID);
	}