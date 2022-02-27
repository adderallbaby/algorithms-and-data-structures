#include <stdio.h>
int numbers[7] = {3, 2, 100, 4, 7, 5, 9};
int less (unsigned long i, unsigned long j){
    return 0;
}
void getCut(int n){
    if (numbers[0] > numbers[1]){
        printf("%d ", 0);
    }
    if(numbers[n-1] > numbers[n-2]){
        printf("%d ", n-1);
    }
}
unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j))
{
    getCut(nel);
    for (int i = 1; i < nel - 1; ++i){
        if (numbers[i] > numbers[i-1] && numbers[i] > numbers[i+1]){
            printf("%d ", i);
        }
    }
    return 0;
}
int main(){
    peak(7, less);
}
