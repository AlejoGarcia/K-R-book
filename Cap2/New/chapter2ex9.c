#include <stdio.h>

int bitcount(unsigned val);

/* test new bitcount function */
main()
{
  unsigned a = 0xaaff55dd;

  printf("0x%08x\n", a);
  printf("# of 1's = %d\n", bitcount(a));

  return 0;
}

/* bitcount: counts number of 1s in x */
int bitcount(unsigned x)
{
  int r;

  for (r = 0; x > 0; r++)
    x &= x - 1;

  return r;
}

/* The expresion x &= x - 1 does the and betwen a number and its predecessor wich by definition
 * will diff on every value till the first 1 form the right so when it ands the who all values till 
 * the first 1 (and including it) are diferent so they are converted to 0 when they are AND*/
