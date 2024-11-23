#include <stdio.h>

/* histogram of characters */
main()
{
	int c, i, j, size;
	int maxcount = 'z' - 'a' + 1;
	int count[maxcount];

	for (i = 0; i < maxcount; ++i)
		count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			++count[c - 'a'];
		else if (c >= 'A' && c <= 'Z')
			++count[c - 'A'];
	}
	size = 0;
	for (i = 0; i < maxcount; ++i)
		if (size < count[i])
			size = count[i];


	for (i = size; i > 0; --i) {
		for (j = 0; j < maxcount; ++j) {
			if (i <= count[j])
				printf(" #");
			else
				printf("  ");
		}
		printf("\n");
	}
	for (j = 0; j < maxcount; ++j) {
		printf(" %c", j + 'A');
	}
	printf("\n");
}
