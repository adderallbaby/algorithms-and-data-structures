#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
    int counter = 1;
    char *token = strtok(s, " ");

    while (token != NULL) {
        counter++;
        token = strtok(NULL, " ");
    }
    return counter - 1;
}

int main() {
    char string[10000];
    gets(string);
    printf("%d", wcount(string));


    return 0;
}