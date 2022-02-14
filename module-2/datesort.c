#include <stdio.h>

#define TYPE struct Date

struct Date {
  int Day, Month, Year;
};

int array_max(int *arr, int n) {
  int mx = *arr;
  for (int i = 1; i < n; i++)
    if (arr[i] > mx) mx = arr[i];
  return mx;
}

void countSort(int *arr, int n, int st10) {
  int nix[n + 5], cnt[10] = {};
  for (int i = 0; i < n; i++) ++cnt[(arr[i] / st10) % 10];
  for (int i = 1; i < 10; ++i) cnt[i] += cnt[i - 1];
  for (int i = n - 1; i > -1; i--)
    nix[cnt[(arr[i] / st10) % 10] - 1] = arr[i], --cnt[(arr[i] / st10) % 10];
  for (int i = 0; i < n; i++) arr[i] = nix[i];
}

void radixsort(TYPE *arr, int n) {
  int varr[n + 10];
  for (int i = 0; i < n; ++i)
    varr[i] = arr[i].Year * 100,
      varr[i] = (varr[i] + arr[i].Month) * 100, varr[i] += arr[i].Day;
  int mx = array_max(varr, n);
  for (int st10 = 1; mx / st10 > 0; st10 *= 10)
    countSort(varr, n, st10);
  for (int i = 0; i < n; ++i)
    arr[i].Year = varr[i] / 10000,
      arr[i].Month = varr[i] / 100 % 100,
      arr[i].Day = varr[i] % 100;
}

int main() {
  int n;
  scanf("%d", &n);
  TYPE dates[n + 10];
  for (int i = 0; i < n; ++i)
    scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
  radixsort(dates, n);
  for (int i = 0; i < n; ++i)
    printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
  return 0;
}
