#include <stdio.h>
#define MAXLINE 1000


int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
    printf("\n\nLa línea más larga que se ha escrito es:\n\n%s\n\n", longest);
  else
    printf("No se ha escrito ninguna línea.\n\n");

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
