#include <stdio.h>

void reverse(char *s)
{
	int final;

	for (final = 0; s[final] != '\0'; final++);

	if (final > 1) {
		s[final] = s[0];
		s[0] = s[final-1];
		s[final-1] = '\0';
		reverse(&s[1]);
		s[final-1] = s[final];
		s[final] = '\0';
	}
}

main()
{
	char a[] = "hola compañero!!\0";
	printf("Cadena inicial: \"%s\"\n", a);
	reverse(a);
	printf("Cadena final: \"%s\"\n", a);
}

