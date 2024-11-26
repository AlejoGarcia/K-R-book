#include <stdio.h>

int any(char string1[], char string2[]);

/* test new any function */
main()
{
  char str1[] = "Input string A.\n";
  char str2[] = "r.";
  printf("Input string: %s", str1);
  printf("Chars to delete:'%s'\n", str2);
  printf("First apparance: %d\n", any(str1, str2));
  return 0;
}

/* any: search any char on s2 on s1 and return first apparance */
int any(char s1[], char s2[])
{
  int i, j, k, r;
  
  r = -1;
  for (i = j = 0; r < 0 && s1[i] != '\0'; i++) {
    for (k = 0; r < 0 && s2[k] != '\0' && s1[i] != s2[k]; k++);
    if (s2[k] != '\0')
      r = i;
  }
  return r;
}
