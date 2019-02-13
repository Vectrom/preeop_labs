#pragma once
#include "Ksztalt.h"

class Kwadrat : public Ksztalt {
	public:
		Kwadrat(const int &a);
		const double polePow() const;
		void wypisz(std::ostream& o) const;
	private:
		int _a;
};

