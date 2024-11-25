#include <stdio.h>

#define FALSE 0
#define TRUE 1

/* replace contiguous blanks with one blank*/
main()
{
	int c, bf;

	bf = FALSE;
	while ((c = getchar()) != EOF) {
		if ((bf == FALSE) || (c != ' '))
			putchar(c);
		bf = (c == ' ') ? TRUE : FALSE;
	}

}
