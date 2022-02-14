#include <stdio.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void distributionSort(int base, int c, union Int32 *nums, int n)
{
    int a,b,d,k;
    int count[base];
    for(int i = 0; i < base; i++) count[i] = 0;
    a = 0;
    while (a < n){
        int key = nums[a].bytes[c];
        if(c == 3) key ^= 128 ;
        count[key]++;
        a++;
    }
    b = 1;
    while (b < base) {
        count[b] += count[b - 1];
        b++;
    }
    union Int32 sorted_nums[n];
    k = n - 1;
    while (k >= 0){
        int key = nums[k].bytes[c];
        if(c == 3) key ^= 128 ;
        int j = --count[key];
        sorted_nums[j] = nums[k];
        k--;
    }

    for(d= 0; d < n; d++) nums[d] = sorted_nums[d];
}

void radixsort(int base, int c, union Int32 *nums, int n)
{
    for(int i = 0; i < c; i++)
        distributionSort(base, i, nums, n);
}


int main()
{
    int n;
    scanf("%i", &n);
    union Int32 nums[n];
    for(int i = 0; i < n; i++) scanf("%i", &nums[i].x);
    radixsort(256, 4, nums, n);
    for(int i = 0; i < n; i++) printf("%i ", nums[i].x);
    printf("\n");
    return 0;
}