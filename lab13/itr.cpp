#include <iostream>
#include "itr.h"

const int &itr::operator *() const {
	return *_tab;
}

void itr::operator++() {
	_count--;
	_tab++;
}

itr::operator bool() {
	return (bool)_count;
}