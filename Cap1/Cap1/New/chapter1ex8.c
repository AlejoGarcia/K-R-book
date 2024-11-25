#include <stdio.h>

/* counts blanks, tabs and newlines in input */
main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}

	printf("# of blanks:\t%d\n", nb);
	printf("# of tabs:\t%d\n", nt);
	printf("# of newlines:\t%d\n", nl);
}
