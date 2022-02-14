#include <stdio.h>
#include <limits.h>

#define TYPE struct Elem

struct Elem {
  struct Elem *prev, *next;
  int v;
} begin;

void insert(TYPE *ptr) {
  TYPE *id = &begin;
  while (id -> next != NULL && ptr -> v > id -> next -> v)
    id = id -> next;
  ptr -> next = id -> next, id -> next = ptr;
}

int main() {
  int n;
  scanf("%d", &n);
  TYPE arr[n + 10];
  begin.v = INT_MIN;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i].v);
    arr[i].next = NULL, insert(arr + i);
  }
  while (begin.next != NULL)
    printf("%d ", (begin.next) -> v), begin = *begin.next;
  return 0;
}
