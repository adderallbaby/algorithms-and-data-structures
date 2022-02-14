#include <stdio.h>
#include <stdlib.h>

struct CircleBuffer {
  int *data, capacity,
    count, head, tail;
};

void InitQueue(struct CircleBuffer *ptr, int n) {
  ptr -> data = (int *) malloc(sizeof(int) * n);
  ptr -> capacity = n;
  ptr -> count = ptr -> head = 0, ptr -> tail = 0;
}

void QueueEmpty(struct CircleBuffer ptr){
  puts(ptr.count ? "false" : "true");
}

void Enqueue(struct CircleBuffer *ptr, int a) {
  ptr -> data[ptr -> tail++] = a;
  if(ptr -> tail == ptr -> capacity) {
    ptr -> capacity *= 2;
    ptr -> data = (int *) realloc(ptr -> data, sizeof(int) * ptr -> capacity);
  }
  ptr -> count++;
}

void Dequeue(struct CircleBuffer *ptr) {
  int tmp = ptr -> data[ptr -> head++];
  if (ptr -> head == ptr -> capacity) ptr -> head = 0;
  ptr -> count--, printf("%d\n", tmp);
}

void main() {
  int n, a;
  char wtd[10];
  scanf("%d", &n);
  struct CircleBuffer buff;
  InitQueue(&buff, 4);
  for(int i = 0; i < n; i++) {
    scanf("%s", wtd);
    if (wtd[1] == 'N')scanf("%d", &a), Enqueue(&buff, a);
    else if (wtd[0] == 'D')Dequeue(&buff);
    else QueueEmpty(buff);
  }
  free(buff.data);
}
