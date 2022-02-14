#include <stdio.h>
#include <stdlib.h>

int numbers[5] = {1, 2, 1, 4, 5};
int less (unsigned long i, unsigned long j){
    return 0;
}
unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j)) {
    int peaks[nel];
    for (int i = 0; i < nel; i++) {
        peaks[i] = 0;
    }
    for (int i = 0; i < nel; i++) {
        if ((i == 0) && (numbers[0] > numbers[1])) {
            peaks[0] = 1;
            printf("%d\n", i);
        }else if ((i == nel - 1) && (numbers[nel - 1] > numbers[nel - 2])) {
            peaks[nel - 1] = 1;
            printf("%d\n", i);
        }else{
            if((numbers[i] > numbers[i+1]) && (numbers[i] > numbers[i-1])){
                peaks[i] = 1;
                printf("%d\n", i);
            }
        }
    }
    return 0;

}

int main() {
    unsigned long i, j;
    peak(5, less);
    return 0;
}