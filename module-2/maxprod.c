#include <stdio.h>
#include <math.h>

#define MAX 1000000
#define EPS 0.00001

int main() {
  int n;
  scanf("%d", &n);
  int zn, ch, l = 0, r = 0, start = 0;
  float number, maxsum = -MAX, sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d / %d", &ch, &zn);
    if(ch == 0) number = -MAX;
    else number = log(ch) - log(zn);
    if(sum < 0) sum = 0, start = i;
    sum += number;
    if(sum - maxsum > EPS)
      maxsum = sum, l = start, r = i;
  }
  printf("%d %d\n", l, r);
  return 0;
}
