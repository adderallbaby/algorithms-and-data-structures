#include <stdio.h>
int main() {

    int mas1[8] = {0,0,0,0,0,0,0,0};
    int mas2[8]= {0,0,0,0,0,0,0,0};
    unsigned int i, j, k, l, m;
    for (i = 0; i < 8; i++){
        int a;
        scanf("%d", &a);
        mas1[i] = a;

    }
    for (l = 0; l < 8; l++){
        int a;
        scanf("%d", &a);
        mas2[l] = a;

    }
    int mark[8]= {0,0,0,0,0,0,0,0};
    int flag = 0;
    for (k = 0; k < 8; k++){
        for (j = 0; j < 8; j++){
            if (mas1[k] == mas2[j]){
                mark[k] = 1;
            }
        }
    }
    for (m = 0; m < 8; m++){
        if (mark[m] == 0 ) {
            flag = 1;
        }
    }
    if (flag == 0){
        printf("%s", "YES");
    }else{
        printf("%s", "NO");
    }

    return 0;
}