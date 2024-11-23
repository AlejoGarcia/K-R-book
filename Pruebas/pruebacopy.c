#include <stdio.h>
#include <stdlib.h>

void cpstring(char* a, char* b) {
  while ((*b++ = *a++) != '\0');
}

void ncpstring(char* a, char* b, unsigned int n) {
  while (n-- > 0)
    *b++ = *a++;
}

char* stack = NULL;
char* stack_base = NULL;
unsigned int stack_size = 0;

char pop(void) {
  if (stack != stack_base)
    return *--stack;
  else
    return 0;
}

void push(char x) {
  char* aux = NULL;
  if (stack == NULL) {
    stack = (char*)malloc(sizeof(char)*8);
    stack_base = stack;
    stack_size = 8;
  } else if (stack_base + stack_size <= stack) {
    aux = (char*)malloc(sizeof(char)*stack_size*2);
    ncpstring(stack_base, aux, stack_size);
    stack_base = aux;
    stack = aux + stack_size;
    aux = NULL;
    stack_size *= 2;
  }
  *stack++ = x;
}

void main(void){
  printf("hola mundo\n");
  unsigned int buffersize = 100;
  char buffer[buffersize];
  char line[] = "hola hola holaaaa";
  unsigned int index = 0;
  while (line[index] != '\0')
    push(line[index++]);
  buffer[0] = '\0';
  printf("'%s'\n", line);
  printf("'%s'\n", buffer);
  cpstring(line, buffer);
  printf("%s\n", line);
  printf("%s\n", buffer);
  while (stack != stack_base)
    printf("%c\n", pop());
}
