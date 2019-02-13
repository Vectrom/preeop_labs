#include "fstore.h"
#include <iostream>

void init(fstore *f, int (*func)(int), int arg) {
	f->function = func;
	f->argument = arg;
}

int call(fstore *f) {
	
	return (f->function)(f->argument);
}

int callWithArg(fstore *f, int arg) {
	
	return (f->function)(arg);
}