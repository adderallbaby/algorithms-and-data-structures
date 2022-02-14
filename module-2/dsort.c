#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000005
#define TWOI8 256

void sort(char *str);

int main() {
  char *str = (char *) malloc(SIZE * sizeof(char));
  scanf("%s", str), sort(str);
  printf("%s", str), free(str);
  return 0;
}

void sort(char *str) {
  int *cnt = (int *) calloc(TWOI8, sizeof(int));
  for (int i = 0; str[i] != '\0'; ++i)++cnt[str[i]];
  for (int i = 0; i < TWOI8; ++i)
    for (int j = 0; j < cnt[i]; ++j)*str = i, ++str;
  free(cnt);
}
