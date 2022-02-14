#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    unsigned long n = 0;
    scanf("%ld", &n);
    long* array = (long*)malloc(sizeof(long) * n);
    for (int i = 0 ; i < n; i++) {
        scanf("%ld", &array[i]);
    }
    long answer = 0;
    long m = (1 << n) - 1;
    for (long i = 0; i <= m; i++){
        long x = 0, y = i, sum = 0;
        while(y > 0) {
            if ((y & 1) == 1)
                sum += array[x];
            x++;
            y = y >> 1;

        }
        if (sum && ((sum & (sum - 1)) == 0)) answer++;
    }
    printf("%ld\n", answer);
    free(array);
    return 0;
}


