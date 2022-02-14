#include <stdio.h>

void cpy(void *a, void *b, int n) {
  unsigned char *A = (unsigned char *) a, *B = (unsigned char *) b;
  for (int i = 0; i < n; ++i) A[i] = B[i];
}

void revarray(void *base, size_t nel, size_t width) {
  char mem[width];
  void *tmp = mem, *lefts, *rights;
  for (int i = 0; i < nel / 2; ++i) {
    lefts = (char *) base + i * width; 
    rights = (char *) base + (nel - 1 - i) * width;
    cpy(tmp, lefts, width), cpy(lefts, rights, width),
      cpy(rights, tmp, width);
  }
}

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6};
  revarray(arr, sizeof arr / sizeof arr[0], sizeof arr[0]);
  for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i)
    printf("%d ", arr[i]);
  return 0;
}
