#include <iostream>
#include <cmath>
#include "Trojkat.h"

Trojkat::Trojkat(const int &a, const int &b, const int &c) : _a(a), _b(b), _c(c) {}

const double Trojkat::polePow() const {
	double x = 0.5*(_a + _b + _c);
	return sqrt(x*(x-_a)*(x-_b)*(x-_c));
}

void Trojkat::wypisz(std::ostream& o) const {
	o << "Trojkat bokach:" << _a << " " << _b << " " << _c << std::endl;
}

