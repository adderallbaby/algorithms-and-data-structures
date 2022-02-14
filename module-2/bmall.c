#include <stdio.h>
#include <string.h>

#define CHARS 1024

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
int main(int argc, char *argv[]){
    if(argc<3){
        return -1;
    }
    char *T = argv[2];//string
    char *S = argv[1];//substring

    int s_size = strlen(S);
    int t_size = strlen(T);
 
    int wc[CHARS];

    int i;
    for (i = 0; i < CHARS; i++){
        wc[i] = -1;
    }
    
    for (i = 0; i < s_size; i++){
        wc[(int)S[i]] = i;
    }

    int found = 0;
    int shift = 0; 
    while (shift <= (t_size - s_size))
    {
        int j = s_size - 1;
 
        while (j >= 0 && S[j] == T[shift + j]){
            j--;
        }
        if (j < 0)
        {
            found++;
            printf("%d\n", shift);
            shift += (shift + s_size < t_size) ? s_size - wc[T[shift + s_size]] : 1;
        }
        else{
            shift += max(1, j - wc[T[shift + j]]);
        }
    }
    return 0;
}