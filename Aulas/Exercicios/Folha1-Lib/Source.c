
#include "Header.h"

int Soma(int x, int y) {
	return x + y;
}

int SomaII(int* a, int* b) {
	return (*a + *b);
}

int* SomaIII(int* a, int* b) {
	int r;
	r = *a + *b;
	return (&r);
}
