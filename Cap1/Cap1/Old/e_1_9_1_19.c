#include <stdio.h>
#define MAXLINE 1000


int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

main()
{
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}


int my_getline(char line[], int maxline)
{
  int c, count;

  for (count = 0; (count < maxline -1) && (c = getchar()) != EOF && c != '\n'; count++)
    line[count] = c;

  if (c == '\n')
    line[count++] = c;
  line[count] = '\0';

  return count;
}

void copy(char to[], char from[])
{
  int count;

  for (count = 0; (to[count] = from[count]) != '\0'; count++);
}

void reverse(char s[])
{
  int i, f;
  char aux;

  for (f = 0; s[f] != '\n' && s[f] != '\0'; f++);
  f--;
  i = 0;

  while (i < f) {
    aux = s[i];
    s[i++] = s[f];
    s[f--] = aux;
  }
}
