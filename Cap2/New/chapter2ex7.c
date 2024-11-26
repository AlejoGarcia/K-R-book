#include <stdio.h>

unsigned invert(unsigned val, int pos, int num);

/* test new invert function */
main()
{
  unsigned a = 0xaaff55dd;

  printf("0x%08x\n", a);
  a = invert(a, 31, 8);
  printf("0x%08x\n", a);
  a = invert(a, 15, 8);
  printf("0x%08x\n", a);

  return 0;
}

/* invert: inverts n bits of x begining at p (changes 0 for 1 and vice versa) */
unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n)) << (p + 1 - n);
}
