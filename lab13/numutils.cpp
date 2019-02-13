#include <iostream>
#include "numutils.h"

void numutils::sum::operator()(const int &number) {
	_result += number;
}

void numutils::average::operator()(const int &number) {
	_count++;
	_sum += number;
}
