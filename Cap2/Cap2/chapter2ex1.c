#include <stdio.h>
#include <limits.h>
#include <float.h>

/* prints limits of each C type */
main()
{
	char a;
	short b;
	int c;
	long d;
	signed char e;
	signed short f;
	signed int g;
	signed long h;

	float i;
	double j;
	long double k;
	
	printf("LIMITS CALC\n");

	/* signed */
	printf("\n");
	for (a = 1; a > 0; ++a);
	printf("char max: %d\n", --a);
	for (a = -1; a < 0; --a);
	printf("char min: %d\n", ++a);
	printf("\n");
	for (b = 1; b > 0; ++b);
	printf("short max: %d\n", --b);
	for (b = -1; b < 0; --b);
	printf("short min: %d\n", ++b);
	printf("\n");
	printf("int max: %d\n", INT_MAX);
	printf("int min: %d\n", INT_MIN);
	printf("\n");
	printf("long max: %d\n", LONG_MAX);
	printf("long min: %d\n", LONG_MIN);
	printf("\n");

	/* unsigned */
	printf("\n");
	e = 0;
	e = (unsigned char)(e-1);
	printf("unsigned char max: %u\n", (unsigned char)e);
	e = 0;
	printf("unsigned char min: %u\n", e);
	printf("\n");
	f = 0;
	f = (unsigned short)f - 1;
	printf("unsigned short max: %u\n", f);
	f = 0;
	printf("unsigned short min: %u\n", (unsigned short)f);
	printf("\n");
	g = 0;
	g = (unsigned int)g - 1;
	printf("unsigned int max: %u\n", g);
	g = 0;
	printf("unsigned int min: %u\n", (unsigned int)g);
	printf("\n");
	h = 0;
	h = h - 1;
	printf("unsigned long max: %lu\n", h);
	h = 0;
	printf("unsigned long min: %lu\n", h);
	printf("\n");

	/* floats */
	printf("\n");
	printf("float max: %f\n", FLT_MAX);
	printf("float min: %f\n", FLT_MIN);
	printf("float eps: %f\n", FLT_EPSILON);
	printf("\n");
	printf("double max: %f\n", DBL_MAX);
	printf("double min: %f\n", DBL_MIN);
	printf("double eps: %f\n", DBL_EPSILON);
	printf("\n");
	printf("\n");

	return 0;
}
