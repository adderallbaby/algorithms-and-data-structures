#include <stdio.h>
#include <stdlib.h>

#define TYPE int

void swap(TYPE *a, TYPE *b);
void selectionsort(TYPE *arr, int begin, int end);
int put_it_in_order(TYPE *arr, int begin, int end);
void r_quicksort(TYPE *arr, int begin, int end, int m);

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  TYPE *arr = (TYPE *) malloc(n * sizeof(TYPE));
  for(int i = 0; i < n; ++i)
    scanf("%d", arr + i);
  r_quicksort(arr, 0, n - 1, m);
  for(int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  free(arr); return 0;
}

void swap(TYPE *a, TYPE *b) {
  TYPE tmp = *a;
  *a = *b, *b = tmp;
}

void selectionsort(TYPE *arr, int begin, int end) {
  for(int i = end; i > begin; --i) {
    int mxid = i;
    for(int j = i - 1; j >= begin; --j)
      if(arr[j] > arr[mxid])mxid = j;
    swap(arr + i, arr + mxid);
  }
}

int put_it_in_order(TYPE *arr, int begin, int end) {
  for(int j = begin; j < end; ++j)
    if(arr[j] < arr[end])
      swap(arr + begin++, arr + j);
  swap(arr + begin, arr + end);
  return begin;
}

void r_quicksort(TYPE *arr, int begin, int end, int m) {
  if(end - begin <= m)
    selectionsort(arr, begin, end);
  else while(begin < end) {
    int nwbeg = put_it_in_order(arr, begin, end);
    if(nwbeg - begin < end - nwbeg)
      r_quicksort(arr, begin, nwbeg - 1, m), begin = nwbeg + 1;
    else r_quicksort(arr, nwbeg + 1, end, m), end = nwbeg - 1;
  }
}
