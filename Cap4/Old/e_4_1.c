#include <stdio.h>

int strrindex(char *s, char l)
{
	int respuesta;

	for (respuesta = 0; s[respuesta] != '\0' && s[respuesta] != l; respuesta++);

	if (s[respuesta] == '\0')
		respuesta = -1;
	
	return respuesta;
}

main()
{
	char a[] = "hola compañero!!\n";
	char b = 'c';
	printf("La frase guardada en 'a' (\"%s\") %s contiene el caracter '%c'. La función ha devuelto %d.\n", a, (strrindex(a, b) >= 0) ? "si" : "no", b, strrindex(a, b));
	b = 'j';
	printf("La frase guardada en 'a' (\"%s\") %s contiene el caracter '%c'. La función ha devuleto %d.\n", a, (strrindex(a, b) >= 0) ? "si" : "no", b, strrindex(a, b));
	b = 'a';
	printf("La frase guardada en 'a' (\"%s\") %s contiene el caracter '%c'. La función ha devuleto %d.\n", a, (strrindex(a, b) >= 0) ? "si" : "no", b, strrindex(a, b));
}

