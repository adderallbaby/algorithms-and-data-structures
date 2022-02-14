#include <stdio.h>
#include <string.h>
int sum(const int arr[], int l, int r){
    int sum = 0;
    for (int i = l; i < r; i++){
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int n, k, max;
    max = -2147483648;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);
    for(int i = 0; i < n - k + 1; i++){
        int current = sum(array, i, i + k);
        if (current > max){
            max = current;
        }
    }
    printf("%d", max);
    return 0;
}