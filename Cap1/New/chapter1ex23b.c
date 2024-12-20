#include <stdio.h>

#define MAXLINE 1000	/* max line length acceptable */

#define STATEINIT	0 	/* initial state */
#define STATELIT1	1 	/* inside literal type 1 */
#define STATELIT2	2 	/* inside literal type 2 */
#define STATECOM1	3	/* inside a commment type 1 */
#define STATECOM2	4	/* inside a commment type 2 */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void substring(char line[], char sub[], int pos, int size);
int find_pattern(char line[], char pattern[], int x, int y);
void fold_line(char line[], int foldfactor);
void detab_line(char line[], int tabstop);
void entab_line(char line[], int tabstop);
void insert_string(char line[], char source[], int pos, int num);
void insert_chars(char line[], int pos, char val, int rep);
void delete_chars(char line[], int pos, int rep);

/* deletes all coments; version 2 */
main()
{
	char c;			/* current char */
	char p;			/* prev char */
	char state;		/* current state */
	int noprint;		/* no print times */

	state = STATEINIT;
	p = '\0';
	noprint = 0;
	while ((c = getchar()) != EOF) {
		if (state == STATEINIT) {
			if (c == '\'' && p != '\\') 
				state = STATELIT1;
			else if (c == '\"' && p != '\\')
				state = STATELIT2;
			else if (c == '*' && p == '/')
				state = STATECOM1;
			else if (c == '/' && p == '/')
				state = STATECOM2;
		} else if (state == STATELIT1) {
			if (c == '\'' && p != '\\') 
				state = STATEINIT;
		} else if (state == STATELIT2) {
			if (c == '\"' && p != '\\') 
				state = STATEINIT;
		} else if (state == STATECOM1) {
			if (c == '/' && p == '*') {
				state = STATEINIT;
				noprint = 2;
			}
		} else if (state == STATECOM2) {
			if (c == '\n') {
				state = STATEINIT;
				noprint = 1;
			}
		} 

		if (state < STATECOM1 && noprint <= 0 && p != '\0')
			printf("%c", p);
		--noprint;
		if (noprint < 0)
			noprint = 0;
		p = c;
	}
	if (state < STATECOM1 && noprint <= 0 && p != '\0')
		printf("%c", p);
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

/* substring: copy s into w only from position p and for n elements */ 
void substring(char s[], char w[], int p, int n)
{
	int i;

	for (i = 0; i < n  && (w[i] = s[p + i]) != '\0'; ++i);
	w[i] = '\0';
}

/* find_pattern: returns index of first appareance of pattern p in string s 
 * just looking in the range from x to y */
int find_pattern(char s[], char p[], int x, int y)
{
	int i, j, r;

	r = -1;
	for (i = x; r < 0 && i <= y && s[i] != '\0'; ++i) {
		j = 0;
		while (s[i + j] == p[j] && p[j] != '\0')
			++j;
		if (p[j] == '\0')
			r = i;
	}
	return r;
}

/* fold_line: folds line respecting spaces when possible */
void fold_line(char s[], int f)
{
	int i, lf, lb, c;

	lf = 0;
	lb = -1;
	for (i = 0; (c = s[i]) != '\0' && c != '\n'; ++i) {
		if (c == ' ' || c == '\t')
			lb = i;
		if (i >= lf + f) {
			if (lb < 0) {
				i = i - 4;
				insert_string(s, " -/-\n", i, 5);
				lf = i + 5;
			} else {
				s[lb] = '\n';
				lf = lb + 1;
				lb = -1;
			}
			i = lf;
		}
	}
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

/* insert_string: insert string d in string s at pos p at most n characters; assumes s is large enought */
void insert_string(char s[], char d[], int p, int n)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i);
	while (i >= p) {
		s[i + n] = s[i];
		--i;
	}
	for (i = 0; i < n; ++i)
		s[p + i] = d[i];
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
