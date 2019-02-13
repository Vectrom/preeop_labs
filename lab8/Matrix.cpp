#include <iostream>
#include "Matrix.h"
#include "Vector.h"


	Matrix::Matrix(const int rows, const int columns, const int defaultValue) {
		_rows = rows;
		_matrix = new Vector *[_rows];
		for(int i = 0; i < _rows; i++)
			_matrix[i] = new Vector(columns, defaultValue);
	}

	Matrix::~Matrix() {
		for(int i = 0; i < _rows; i++)
			delete _matrix[i];
		delete[] _matrix;
	}

	Vector & Matrix::at(const int index) {
		return *(_matrix)[index];
	}
	
	void Matrix::print() const {
		for(int i = 0; i < _rows; i++){
			_matrix[i]->print();
			std::cout << std::endl;
		}
	}