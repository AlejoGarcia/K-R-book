#include <stdio.h>

#define MAXLINE 1000
#define MAXCOL	80

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void substring(char to[], char from[], int pos, int size);
void fold_line(char line[], int foldfactor);
void detab_line(char line[], int tabstop);
void entab_line(char line[], int tabstop);
void insert_string(char line[], char source[], int pos, int num);
void insert_chars(char line[], int pos, char val, int rep);
void delete_chars(char line[], int pos, int rep);


main()
{
	int len;		
	char line[MAXLINE]; 	

	while ((len = my_getline(line, MAXLINE)) > 0) {
		fold_line(line, MAXCOL);
		printf("%s", line);
	}
	return 0; 
}


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


void copy(char to[], char from[])
{
	int i;
	
	for (i = 0; (to[i] = from[i]) != '\0'; i++);
}

 
void substring(char to[], char from[], int p, int n)
{
	int i;

	for (i = 0; i < n  && (to[i] = from[p + i]) != '\0'; ++i);
	to[i] = '\0';
}


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


void delete_chars(char s[], int p, int n)
{
	int i;

	for (i = p; s[i + n] != '\0'; ++i)
	       s[i] = s[i + n];	
	s[i] = '\0';
}
