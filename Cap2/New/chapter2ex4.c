#include <stdio.h>

void squeeze(char string1[], char string2[]);

/* test new squeeze function */
main()
{
  char str1[] = "Input string A.\n";
  char str2[] = "Itg.";
  printf("Input string: %s", str1);
  printf("Chars to delete:'%s'\n", str2);
  squeeze(str1, str2);
  printf("Output string: %s", str1);
  return 0;
}

/* squeeze: squeezes s1 by substracting any character that also appears in s2 */
void squeeze(char s1[], char s2[])
{
  int i, j, k;
  
  for (i = j = 0; s1[i] != '\0'; i++) {
    for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++);
    if (s2[k] == '\0')
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}
