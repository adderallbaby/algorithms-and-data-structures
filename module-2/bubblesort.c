#include <stdio.h>
#include <stdlib.h>
void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    unsigned long t, b, i, y, z, c;
    t = nel - 1;
    b = t;
    t = 0;
    i = 0;
    c = 0;
    y = 0;
    while (t != b) {
        while (i < b) {
            if (compare(i + 1, i) == -1) {
                swap(i + 1, i);
                t = i;
            }
            i += 1;
        }
        i = t;
        if (y == i)
            break;
        y = i;
        while (i > c) {
            if (compare(i, i - 1) == -1) {
                swap(i, i - 1);
                y = i;
            }
            i -= 1;
        }
        c = y;
        b = t;
        t = y;
        i = y;
    }
}
int *array;

int compare(unsigned long i, unsigned long j)
{
    if (array[i] == array[j]) return 0;
    return array[i] < array[j] ? -1 : 1;
}

void swap(unsigned long i, unsigned long j)
{
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}
int main(int argc, char **argv)
{
    int i, n;
    scanf("%d", &n);

    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", array+i);

    bubblesort(n, compare, swap);
    for (i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    free(array);
    return 0;
}