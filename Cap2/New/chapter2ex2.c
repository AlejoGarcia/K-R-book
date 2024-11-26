#include <stdio.h>

/* loop conditions without && and || */
main()
{
  int i;
  const int lim = 100;
  char s[lim];
  char c;

	/*
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	*/

	i = 0;
	while (i < lim - 1) {
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
		++i;
	}
  printf("Read line: %s\n", s);
}
