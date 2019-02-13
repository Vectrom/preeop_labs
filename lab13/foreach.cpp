#include <iostream>
#include "foreach.h"

foreach::foreach(itr iterator, std::function<void(int)> functor) {
	while (iterator) {
	    functor(*iterator);
	    ++iterator;
  	}
}