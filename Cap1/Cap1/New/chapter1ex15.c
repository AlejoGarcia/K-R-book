#include <stdio.h>

#define	LOWER	-300	/* lower limit of temperature table */
#define UPPER	300	/* upper limit of temperature table */
#define STEP	20	/* step size */

float fahr_to_celsius(float d);

/* print Fahrenheit-Celsius table with aux function to convert
 * 	for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;

	printf("Fahrenheit\tCelsius\n");
	printf("-----------------------\n");
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%10.0f\t%7.1f\n", fahr, fahr_to_celsius(fahr));
}


/* function to convert degrees fahrenheit to degrees celsius */
float fahr_to_celsius(float degree)
{
	return (5.0/9.0) * (degree - 32.0);
}
