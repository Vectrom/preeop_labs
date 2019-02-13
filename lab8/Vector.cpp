#include <iostream>
#include "Vector.h"


	Vector::Vector(const int size, const int defaultValue) {
		_size = size;
		_vector = new int[_size];
		for(int i = 0; i < _size; i++)
			_vector[i] = defaultValue;
	}

	Vector::~Vector() {
		delete[] _vector;
	}

	void Vector::print() const {
		for(int i = 0; i < _size; i++)
			std::cout << _vector[i] << " ";
	}

	void Vector::mul(const int value) {
		for(int i = 0; i < _size; i++)
			_vector[i] *= value;
	}

	Vector & Vector::add(const int value) {
		for(int i = 0; i < _size; i++)
			_vector[i] += value;
		return *this;
	}

	void Vector::add(Vector & vectorToAdd) {
		for(int i = 0; i < _size; i++)
			_vector[i] += vectorToAdd.at(i);
	}

	int & Vector::at(const int index) {
		return _vector[index];
	}