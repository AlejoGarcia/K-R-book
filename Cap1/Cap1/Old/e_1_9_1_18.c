#include <stdio.h>
#define MAXLINE 1000


int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
  int len, i;
  char nl, line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len > 1) {
      if (line[len - 1] == '\n')
        nl = 1;
      else
        nl = 0;
      for (i = len - 2; line[i] == ' ' || line[i] == '\t'; i--);
      if (nl == 1)
        line[++i] = '\n';
      line[++i] = '\0';
      printf("%s", line);
    }
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
