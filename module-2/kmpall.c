#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int stlen(char *s);
void kmpall(char *str, char *str2, int *cl, int fl, int sl);
void count_l(char *str, int len, int *cl);

int main(int argc, char **argv) {
  int flen = stlen(argv[1]), slen = stlen(argv[2]), *cnt_letters = (int *) calloc(SIZE, sizeof (int));
  count_l(argv[1], flen, cnt_letters), kmpall(argv[1], argv[2], cnt_letters, flen, slen);
  free(cnt_letters);
  return 0;
}

int stlen(char *s) {
  int len = 0;
  while (*(s + len) != '\0')++len;
  return len;
}

void kmpall(char *str, char *str2, int *cl, int fl, int sl) {
  int i = 0, j = 0;
  while (j < sl) {
    while (i != 0 && str[i] != str2[j])i = cl[i - 1];
    i += str[i] == str2[j++];
    if (i == fl) printf("%d ", j - fl);
  }
}

void count_l(char *str, int len, int *cl) {
  int i = 1, j = 0;
  while (i < len) {
    while (j != 0 && str[j] != str[i])j = cl[j - 1];
    j += str[j] == str[i], cl[i++] = j; 
  }
}
