#include <stdio.h>
#include <stdlib.h>

int arr[] = {10, 20, 30, 40, 60, 50, 0}, f = 40;

int compare(unsigned long i) {
  if (arr[i] == f) return 0;
  if (arr[i]  < f) return -1;
  return 1;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
  unsigned long l = 0, r = nel - 1, m = (l + r) / 2;
  while (l <= r) {
    int res = compare(m);
    if (res == -1) l = m + 1;
    else if (res == 1) r = m - 1;
    else return m;
    m = (l + r) / 2;
  }
  return nel;
}

int main() {
  printf("%lu", binsearch(sizeof arr / sizeof arr[0], compare));
  return 0;
}
