#include <stdio.h>
#include <ctype.h>

int htoi(char hex[]);

/* test funtion htoi */
main()
{
	/* test convertin string "ab23ed" */
	printf("ab23ed = %d\n", htoi("ab23ed"));
	/* test convertin string "0xfedfac" */
	printf("0xfedfac = %d\n", htoi("0xfedfac"));
	/* test convertin string "0XACfac" */
	printf("0XACfac = %d\n", htoi("0XACfac"));
	/* test convertin string "0X5a5a" */
	printf("0X5a5a = %d\n", htoi("0X5a5a"));
}

/* converts string s containing a hex value to its int value */
int htoi(char s[])
{
	int i, n;

	n = 0;
	i = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i = 2;
	while (isxdigit(s[i])) {	
		if (isalpha(s[i]))
	       		n = n * 16 + tolower(s[i]) - 'a' + 10; 	
		else
	       		n = n * 16 + s[i] - '0'; 	
		++i;
	}
	return n;
}
