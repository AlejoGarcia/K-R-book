#include <stdio.h>

#define MAXLINE 1000

int lower(int val);

/* test new lower function */
main()
{
  char line[MAXLINE] = "HOLa aAafaHOlA\n";
  int i;

  printf("%s", line);

  for (i = 0; i < MAXLINE && line[i] != '\0'; i++)
    line[i] = lower(line[i]);

  printf("%s", line);

  return 0;
}

/* lower: converts c to lower case; ASCII only, 2nd version*/
int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
} 
