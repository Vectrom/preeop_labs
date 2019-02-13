#pragma once
#include "Ksztalt.h"

class Trojkat : public Ksztalt {
	public:
		Trojkat(const int &a, const int &b, const int &c);
		const double polePow() const;
		void wypisz(std::ostream& o) const;
	private:
		int _a;
		int _b;
		int _c;
};

