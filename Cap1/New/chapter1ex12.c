#include <stdio.h>

#define IN 1
#define OUT 0

/* Prints input one word per line */
main()
{
	int c;
	int state = OUT;

	while ((c = getchar()) != EOF) {
		if ((c == ' ') || (c == '\t')) {
			if (state == IN) {
				state = OUT;
				putchar('\n');
			}
		} else {
			state = IN;
			putchar(c);
		}
	}
}
