#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE struct stack
#define INIT_SIZE 1005
#define MMEMRY 10000

struct stack {
  long long *arr;
  int size, memsize;
};

long long max(long long a, long long b) {
  return a > b ? a : b;
}

long long min(long long a, long long b) {
  return a > b ? b : a;
}

void init(TYPE *ptr) {
  ptr -> arr = malloc(INIT_SIZE * sizeof(long long)),
    ptr -> memsize = INIT_SIZE, ptr -> size = 0;
}

void amortize(TYPE *ptr) {
  if (ptr -> size < ptr -> memsize)return;
  long long *newmem = (long long *) malloc((ptr -> memsize + MMEMRY) * sizeof(long long));
  for (int i = 0; i < ptr -> size; ++i)
    newmem[i] = ptr -> arr[i];
  free(ptr -> arr), ptr -> arr = newmem, ptr -> memsize += MMEMRY;
}

long long pop(TYPE *ptr) {
  ptr -> size--;
  return ptr -> arr[ptr -> size];
}

void insert(TYPE *ptr, long long x) {
  amortize(ptr), ptr -> arr[ptr -> size] = x, ptr -> size++;
}

void CONST(TYPE *ptr, long long x) {
  insert(ptr, x);
}

void ADD(TYPE *ptr) {
  insert(ptr, pop(ptr) + pop(ptr));
}

void SUB(TYPE *ptr) {
  insert(ptr, pop(ptr) - pop(ptr));
}

void MUL(TYPE *ptr) {
  insert(ptr, pop(ptr) * pop(ptr));
}

void DIV(TYPE *ptr) {
  insert(ptr, pop(ptr) / pop(ptr));
}

void MAX(TYPE *ptr) {
  insert(ptr, max(pop(ptr), pop(ptr)));
}

void MIN(TYPE *ptr) {
  insert(ptr, min(pop(ptr), pop(ptr)));
}

void NEG(TYPE *ptr) {
  insert(ptr, -pop(ptr));
}

void DUP(TYPE *ptr) {
  long long temp = pop(ptr);
  insert(ptr, temp), insert(ptr, temp);
}

void SWAP(TYPE *ptr) {
  long long a = pop(ptr), b = pop(ptr);
  insert(ptr, a), insert(ptr, b);
}

int main() {
  int n;
  long long tmp;
  scanf("%d", &n);
  char str[100];
  TYPE stackmachine;
  init(&stackmachine);
  while (n--) {
    scanf("%s", str);
    if (strcmp(str, "CONST") == 0)scanf("%lld", &tmp), CONST(&stackmachine, tmp);
    else if (strcmp(str, "ADD") == 0)ADD(&stackmachine);
    else if (strcmp(str, "SUB") == 0)SUB(&stackmachine);
    else if (strcmp(str, "MUL") == 0)MUL(&stackmachine);
    else if (strcmp(str, "DIV") == 0)DIV(&stackmachine);
    else if (strcmp(str, "MAX") == 0)MAX(&stackmachine);
    else if (strcmp(str, "MIN") == 0)MIN(&stackmachine);
    else if (strcmp(str, "NEG") == 0)NEG(&stackmachine);
    else if (strcmp(str, "DUP") == 0)DUP(&stackmachine);
    else if (strcmp(str, "SWAP") == 0)SWAP(&stackmachine);
  }
  printf("%lld", stackmachine.arr[0]), free(stackmachine.arr);
  return 0;
}
