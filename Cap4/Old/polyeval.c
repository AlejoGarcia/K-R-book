#include <stdio.h>

float polyval(int* poly, float x, int deg) {
	float res = 0.0;
	int i = 0;
        float acc = 1.0;

	for (i = 0; i < deg; i++) {
		res += acc * poly[deg - 1 - i];
		acc *= x;
	}
	
	return res;
}


int main (void) {
	int poly[] = {1,0,5,4};
	int n = 4;
	float xval = 0.1;
	float y = polyval(poly, xval, n);

	printf("Para el polinomio dado el valor de x: %f vale %f\n", xval, y);
	return 0;
}
