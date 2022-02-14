#include <stdio.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define GET_BIT(str, bit) ((str[(bit)/8] >> ((bit) % 8)) & 1)
int strdiff(char *a, char *b)
{
    int i;
    int strlen_a = strlen(a) + 1;
    int strlen_b = strlen(b) + 1;
    for(i = 0; i < 8 * MIN(strlen_a, strlen_b); ++i){
        printf("GET_BIT(%d) = %d GET_BIT(%d) = %d\n", i, GET_BIT(a, i), i, GET_BIT(b, i));
        if (GET_BIT(a, i) != GET_BIT(b, i)){
            return i;
        }
    }
    return -1;
}