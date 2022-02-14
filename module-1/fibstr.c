#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *fibstr(int n)
{
    char* fib1 = (char*)calloc(2, sizeof(char));
    char* fib2 = (char*)calloc(2, sizeof(char));
    strcpy(fib1, "a");
    strcpy(fib2, "b");
    if(n==1){free(fib2);return fib1;}
    if(n==2){free(fib1);return fib2;}
    for(int i = 0; i < n-2; i++)
    {
        char* fibsum = (char*)calloc(strlen(fib1)+strlen(fib2)+1,sizeof(char));
        strcpy(fibsum, fib1);
        strcat(fibsum, fib2);
        fib1 = (char*)realloc(fib1,strlen(fib2)+1);
        strcpy(fib1, fib2);
        fib2 = (char*)realloc(fib2, strlen(fibsum)+1);
        strcpy(fib2, fibsum);
        free(fibsum);
    }
    free(fib1);
    return fib2;
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
        int n = atoi(argv[1]);
        char *res = fibstr(n);
        printf("%s\n", res);
        free(res);
    }
    return 0;
}
