#include <stdio.h>

unsigned setbits(unsigned val, int pos, int num, int input);

/* test new setbits function */
main()
{
  unsigned a = 0xaaff55dd;

  printf("0x%08x\n", a);
  a = setbits(a, 11, 8, 0x000000ee);
  printf("0x%08x\n", a);
  a = setbits(a, 27, 8, 0x00000033);
  printf("0x%08x\n", a);

  return 0;
}

/* setbits: returns x with the n bits that begin at poss p set to the rightmost n bits
 * of y other bits are left unchanged */
unsigned setbits(unsigned x, int p, int n, int y)
{
  return (x & ~(~(~0 << n) << (p + 1 - n))) | (~(~0 << n) & y) << (p + 1 - n);
}
