#include <stdio.h>
#include <math.h>

int simple(long long x) {
  int sqr = sqrt(x);
  for (int i = 2; i <= sqr; ++i)
    if (x % i == 0) return 1;
  return 0;
}

int main() {
  long long n, p = 2;
  scanf("%lld", &n);
  if (n < 0)n *= -1;
  while (simple(n)) {
    if (n % p != 0)++p;
    else n /= p;
  }
  printf("%lld", n);
  return 0;
}
