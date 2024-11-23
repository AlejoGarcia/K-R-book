#include <stdio.h>

main() {
	char a = 'c';
	short b = 244;
	int c = 12323323;
	long d = 23232123123123;
	float e = 5.0/3.0;
	double f = 13.0/7.0;

	printf("El tamaño del char 'a' es %d y contiene el valor %d(%c).\n", (int)sizeof(a), a, a);
	printf("El tamaño del short (short int) 'b' es %d y contiene el valor %d.\n", (int)sizeof(b), b);
	printf("El tamaño del int 'c' es %d y contiene el valor %d.\n", (int)sizeof(c), c);
	printf("El tamaño del long (long int) 'd' es %d y contiene el valor %ld.\n", (int)sizeof(d), d);
	printf("El tamaño del float 'e' es %d y contiene el valor %f.\n", (int)sizeof(e), e);
	printf("El tamaño del double 'f' es %d y contiene el valor %f.\n", (int)sizeof(f), f);
}

