#include <iostream>
#include "Kwadrat.h"

Kwadrat::Kwadrat(const int &a) : _a(a){}

const double Kwadrat::polePow() const {
	return _a*_a;
}

void Kwadrat::wypisz(std::ostream& o) const {
	o << "Kwadrat o boku:" << _a << std::endl;
}