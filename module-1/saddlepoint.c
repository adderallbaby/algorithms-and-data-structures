
#include <stdio.h>
int max(int arr[], int len){

    for (int i = 1; i < len; ++i) {
        if (arr[0] < arr[i]) {
            arr[0] = arr[i];
        }
    }

    return arr[0];
}
int min(int arr[], int len){

    for (int i = 1; i < len; ++i) {
        if (arr[0] > arr[i]) {
            arr[0] = arr[i];
        }
    }
    return arr[0];

}
void printnone(){
    printf("none");
}

int main(int argc, char ** argv)
{
    int str, sto;

    scanf("%d %d ", &str, &sto);

    int matrix[str][sto];
    int transponented[sto][str];
    for (int i = 0; i < str; i++)
        for (int j = 0; j < sto; j++) {
            int a;
            scanf("%d", &a);
            matrix[i][j] = a;
            transponented[j][i] = a;
        }

    int c = 0;
    for(int i = 0; i < str; i++){
        for(int j = 0; j < sto; j++){
            if((max(matrix[i], str) == min(transponented[j], sto))&& (matrix[i][j] == max(matrix[i], str))){
                printf("%d %d\n", i, j);
                c++;
            }
        }
    }
    if (c== 0){
        printnone();
    }
    return 0;
}
