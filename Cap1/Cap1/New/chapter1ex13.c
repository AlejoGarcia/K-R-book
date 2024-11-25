#include <stdio.h>

#define MAXCOUNT 10

/* Word length histogram (horizontal) */
main()
{
	int c, i, j, size;
	int count[MAXCOUNT];

	size = 0;
	for (i = 0; i < MAXCOUNT; ++i)
		count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (size > 0) {
				if (size >= MAXCOUNT)
					size = MAXCOUNT - 1;
				++count[size];
				size = 0;
			}
		} else {
			++size;
		}
	}

	for (i = 0; i < MAXCOUNT; ++i) {
		printf("%d\t", i);
		for (j = 0; j < count[i]; ++j)
			printf("#");
		printf("\n");
	}
}
