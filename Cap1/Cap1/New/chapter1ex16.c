#include <stdio.h>

#define MAXLINE 30

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line even if its bigger than the MAXLINE showing only what MAXLINE allows */
main()
{
	int size;		/* current read size */
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char buffer[MAXLINE]; 	/* current input data */
	char line[MAXLINE]; 	/* current line start */
	char longest[MAXLINE]; 	/* longest input line saved here */

	max = 0;
	while ((size = my_getline(buffer, MAXLINE)) > 0) {
		len = size;
		copy(line, buffer);
		while (size >= (MAXLINE - 1)) {
			size = my_getline(buffer, MAXLINE);
			len = len + size;
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max >= MAXLINE) /* longest line bigger than buffer */
		printf("Longest size: %d; Longest string start: %s...\n", max, longest);
	else if (max > 0) /* there was a line at least */
		printf("Longest size: %d; Longest string: %s", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assumes to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	for (i = 0; (to[i] = from[i]) != '\0'; ++i);
}
