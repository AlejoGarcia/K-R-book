#include <stdio.h>

#define MAXLINE 1000
#define MAXCOL	11

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void substring(char to[], char from[], int pos, int size);
void detab_line(char line[], int tabstop);
void entab_line(char line[], int tabstop);
void insert_chars(char line[], int pos, char val, int rep);
void delete_chars(char line[], int pos, int rep);

/* folds long input lines without respecting words*/
main()
{
	int len;		/* current line length */
	int fold_index;		/* current number of folds */
	char line[MAXLINE]; 	/* current input line */
	char plot_line[MAXCOL + 1]; 	/* output line */


	while ((len = my_getline(line, MAXLINE)) > 0) {
		if (len > MAXCOL) {
			fold_index = 0;
			while (fold_index + MAXCOL < len - 1) {
				substring(plot_line, line, fold_index, MAXCOL);
				printf("%s -/-\n", plot_line);
				fold_index = fold_index + MAXCOL;
			}
			substring(plot_line, line, fold_index, MAXLINE);
			printf("%s", plot_line);
		} else
			printf("%s", line);
	}
	return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim-1; ++i)
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
	
	for (i = 0; (to[i] = from[i]) != '\0'; i++);
}

/* substring: copy 'from' into 'to' only from position p and for n elements */ 
void substring(char to[], char from[], int p, int n)
{
	int i;

	for (i = 0; i < n  && (to[i] = from[p + i]) != '\0'; ++i);
	to[i] = '\0';
}

/* detab_line: changes tabs for spaces taking tabstop in account */
void detab_line(char s[], int t)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t') {
			delete_chars(s, i, 1);
			insert_chars(s, i, ' ', t - (i % t));
		}
	}
}

/* entab_line: changes spaces for tabs taking tabstop in account */
void entab_line(char s[], int t)
{
	int i, j;

	for (i = 0; s[i] != '\0'; ++i);
	while (i > 0) {
		if (s[i] == ' ' && (i % t) + 1 == t) {
			j = i;
			while (s[j - 1] == ' ' && j % t != 0)
				--j;
			if (j != i) {
				delete_chars(s, j, i - j + 1);
				insert_chars(s, j, '\t', 1);
				i = j;
			}
		}
		--i;
	}
}

/* insert_chars: insert char c in string s at pos p n times; assumes s is large enought */
void insert_chars(char s[], int p, char c, int n)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i);
	while (i >= p) {
		s[i + n] = s[i];
		--i;
	}
	for (i = 0; i < n; ++i)
		s[p + i] = c;
}

/* delete_chars: delete n chars from string s at pos p */
void delete_chars(char s[], int p, int n)
{
	int i;

	for (i = p; s[i + n] != '\0'; ++i)
	       s[i] = s[i + n];	
	s[i] = '\0';
}
