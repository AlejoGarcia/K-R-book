#include <stdio.h>

#define FALSE 0
#define TRUE 1

/* replace each tab by '\t', each backspace '\b' and each backslash by '\\' */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t'){
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else 
			putchar(c);
	}
}
