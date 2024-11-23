#include <stdio.h>

/* count digits, white space, others... in input */
main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else
			++nother;

	printf("Digits = ");
	for (i = 0; i < 10; ++i)
		printf("n(%d) -> %d\t", i, ndigit[i]);
	printf("\nwhite space -> %d\tother -> %d\n", nwhite, nother);
}
