#include <stdio.h>

#define MAXLINE 1000

int max;		/* maximum length seen so far */
char line[MAXLINE]; 	/* current input line */
char longest[MAXLINE]; 	/* longest input line saved here */

int my_getline(void);
void copy(void);

/* print longest input line; specialized version */
main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = my_getline()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) /* there was a line at least */
		printf("%s", longest);
	return 0;
}

/* getline: specialized version */
int my_getline(void)
{
	int c, i;
	extern char line[];
	
	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: specialized version */
void copy(void)
{
	int i;
	extern char line[], longest[];
	
	for (i = 0; (longest[i] = line[i]) != '\0'; i++);
}
