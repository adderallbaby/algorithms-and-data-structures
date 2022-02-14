#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1005

char *concat(char **s, int n) {
  int size = 0, id = 0;
  for (int i = 0; i < n; ++i)
    size += strlen(&s[i][0]);
  char *str = malloc(size + 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; s[i][j] != '\0'; ++j)
      str[id++] = s[i][j];
  str[id] = '\0';
  return str;
}

char *cpy(char *s, int ln) {
  char *str = malloc(ln + 1);
  for (int i = 0; i <= ln; ++i)
    str[i] = s[i];
  return str;
}

int main() {
  int n;
  scanf("%d", &n);
  char *arr[SIZE * SIZE / 10 + 5], str[SIZE], *ptr;
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    arr[i] = cpy(str, strlen(str));
  }
  ptr = concat(arr, n);
  printf("%s", ptr), free(ptr);
  for (int i = 0; i < n; ++i) free(arr[i]);
  return 0;
}
