#pragma once
#include "Ksztalt.h"

class Kolo : public Ksztalt {
	public:
		Kolo(const int &r);
		const double polePow() const;
		void wypisz(std::ostream& o) const;
	private:
		int _r;
};
