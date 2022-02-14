#include <stdio.h>
#include <stdlib.h>
typedef struct a a;
typedef struct s s;
struct a
{
    int low;
    int high;
};

struct s
{
    int capacity;
    int top;
    struct a*data;
};

void InitStack(s *s, int n)
{
    s->data = (a *)malloc(sizeof(s) * n);
    s->capacity = n;
    s->top = 0;
}

void push(s *s,  a x)
{
    s->data[s->top] = x;
    s->top++;
}

a pop(s *s)
{
    s->top--;
    return s->data[s->top];
}

int stackempty(s s)
{
    return s.top == 0;
}

int partition(int *a, int low, int high)
{
    int i = low;
    int j = 0;
    for(j = low; j < high; j++)
    {
        if(a[j] < a[high])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }

    int temp = a[i];
    a[i] = a[high];
    a[high] = temp;

    return i;
}

void quicksort(int *a, int n)
{
    s units;
    InitStack(&units, n);
    struct a unit;
    unit.high = n - 1;
    unit.low = 0;
    push(&units, unit);

    while(stackempty(units) == 0)
    {
        struct a unit = pop(&units);
        int low = unit.low;
        int high = unit.high;
        if(low < high)
        {
            struct a new;
            int queue = partition(a, low, high);
            new.low = queue + 1;
            new.high = high;
            push(&units, new);
            new.low = low;
            new.high = queue - 1;
            push(&units, new);
        }
    }
    free(units.data);
}
void StackOperating(){
    int n;
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    quicksort(nums, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
void main()
{
    StackOperating();
}