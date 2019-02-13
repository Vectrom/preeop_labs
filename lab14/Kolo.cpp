#include <iostream>
#include "Kolo.h"

Kolo::Kolo(const int &r) : _r(r) {}

const double Kolo::polePow() const {
	return 3.1415*_r*_r;
}

void Kolo::wypisz(std::ostream& o) const {
	o << "Kolo o promieniu:" << _r << std::endl;
}