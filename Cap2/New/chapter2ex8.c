#include <stdio.h>

unsigned rightrot(unsigned val, int num);

/* test new rightrot function */
main()
{
  unsigned a = 0xaaff55dd;

  printf("0x%08x\n", a);
  a = rightrot(a, 3);
  printf("0x%08x\n", a);
  a = rightrot(a, 4);
  printf("0x%08x\n", a);

  return 0;
}

/* rightrot: rotate to the right by n positions*/
unsigned rightrot(unsigned x, int n)
{
  int i;
  unsigned j;

  j = 1;
  for (i = 0; j > 0; i++)
    j = j << 1;

  return (x >> n) | (x << (i - n));
}
