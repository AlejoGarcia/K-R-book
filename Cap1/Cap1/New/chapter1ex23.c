#include <stdio.h>

#define MAXLINE 1000	/* max line length acceptable */
#define NUMSYMBS	5 	/* number of symbols */
#define LIT1 0 		/* symbol \' */
#define LIT2 1		/* symbol \" */
#define COM1 2		/* symbol // */
#define COM2 3		/* symbol /\* */
#define COM3 4		/* symbol *\/ */
#define STATEINIT	0 	/* initial state */
#define STATELIT1	1 	/* inside literal type 1 */
#define STATELIT2	2 	/* inside literal type 2 */
#define STATECOMM	3	/* inside a commment */

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

/* deletes all coments */
main()
{
	int len;		/* length of current line */
	int index;		/* index to process line */
	char line[MAXLINE];	/* current line */
	char auxline[MAXLINE];	/* auxiliar print line */
	char state;		/* current state */
	int symindex[NUMSYMBS];	/* symbols index */
	int nextsymb;		/* current next symbol */
	int j;			/* aux variable */

	state = STATEINIT;
	while ((len = my_getline(line, MAXLINE)) > 0) { /* read line */
		/* process line */
		index = 0;
		while (index < len) {
			/* find next symbol */
			symindex[LIT1] = find_pattern(line, "\'", index, len - 1); 
			j = find_pattern(line, "\\\'", index, len - 1); 
			while (j + 1 == symindex[LIT1]) {
				symindex[LIT1] = find_pattern(line, "\'", j + 2, len - 1); 
				j = find_pattern(line, "\\\'", j + 2, len - 1); 
			}
			symindex[LIT2] = find_pattern(line, "\"", index, len - 1); 
			j = find_pattern(line, "\\\"", index, len - 1); 
			while (j + 1 == symindex[LIT2]) {
				symindex[LIT2] = find_pattern(line, "\"", j + 2, len - 1); 
				j = find_pattern(line, "\\\"", j + 2, len - 1); 
			}
			symindex[COM1] = find_pattern(line, "//", index, len - 1); 
			symindex[COM2] = find_pattern(line, "/*", index, len - 1); 
			symindex[COM3] = find_pattern(line, "*/", index, len - 1); 

			nextsymb = -1;
			for (j = 0; j < NUMSYMBS; ++j)
				if (symindex[j] >= 0 && (nextsymb < 0 || symindex[j] < symindex[nextsymb]))
					nextsymb = j;

			if (nextsymb < 0) {
				/* if there is no symbol get to the end of line */
				if (state != STATECOMM) {
					substring(line, auxline, index, len - index);
					printf("%s", auxline);
				}
				index = len;
			} else {
				/* apply action till next symbol */
				if (state != STATECOMM) {
					substring(line, auxline, index, symindex[nextsymb] - index);
					printf("%s", auxline);
					if (nextsymb == LIT1)
						printf("\'");
					else if (nextsymb == LIT2)
						printf("\"");
				}

				/* move to next symbol or end of line */
				if (nextsymb == LIT1 || nextsymb == LIT2)
					index = symindex[nextsymb] + 1;
				else if (nextsymb == COM1)
					index = len;
				else if (nextsymb == COM2 || nextsymb == COM3)
					index = symindex[nextsymb] + 2;
				else
					index = len;

				/* change states */
				if (state == STATEINIT) {
					if (nextsymb == LIT1) {
						state = STATELIT1;
					} else if (nextsymb == LIT2) {
						state = STATELIT2;
					} else if (nextsymb == COM2) {
						state = STATECOMM;
					}
				} else if (state == STATELIT1) {
					if (nextsymb == LIT1) {
						state = STATEINIT;
					}
				} else if (state == STATELIT2) {
					if (nextsymb == LIT2) {
						state = STATEINIT;
					}
				} else if (state == STATECOMM) {
					if (nextsymb == COM3) {
						state = STATEINIT;
					}
				}
			}
			/* check if line end to exit processing */
		}
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
