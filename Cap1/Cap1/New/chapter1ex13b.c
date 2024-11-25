#include <stdio.h>

#define MAXCOUNT 10

/* Word length histogram (vertical) */
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

	size = 0;
	for (i = 0; i < MAXCOUNT; ++i)
		if (size < count[i])
			size = count[i];


	for (i = size; i > 0; --i) {
		for (j = 0; j < MAXCOUNT; ++j) {
			if (i <= count[j])
				printf("\t#");
			else
				printf("\t ");
		}
		printf("\n");
	}
	for (j = 0; j < MAXCOUNT; ++j) {
		printf("\t%d", j);
	}
	printf("\n");
}
