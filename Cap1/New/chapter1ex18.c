#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print lines removing trailing blanks and spaces*/
main()
{
	int len;		/* current line length */
	char line[MAXLINE]; 	/* current line */

	while ((len = my_getline(line, MAXLINE)) > 0) {
		for (len = len - 2; len >= 0 && (line[len] == '\t' || line[len] == ' '); --len);
		++len;
		line[len] = '\n';
		++len;
		line[len] = '\0';
		if (len > 1)
			printf("%s", line);
	}
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
