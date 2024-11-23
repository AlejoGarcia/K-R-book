#include <stdio.h>

/* show value returned by getchar() */
main()
{
	int c;

	c = getchar() != EOF;

	printf("c value: %d\n", c); 
}
