#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

#define SET_BIT(i) (1 << (i))
#define GET_BIT(arr, index) (1 & ((arr) >> (index)))

//#define DEBUG

#ifdef DEBUG
#define out printf
#define newline putchar('\n');
#define SHOW_RECURSION_DEPTH(i) {int k; for(k = 0; k < i; ++k) printf("  |");}

#else
#define out(...)
#define newline
#define SHOW_RECURSION_DEPTH(i)
#endif

//char *place type **arr уже должны быть объявлены
#define MATRIX_MALLOC(place, arr, M, N, type) { \
    int i; \
    int col_size = (M)*sizeof(type *); \
    int str_size = (N)*sizeof(type); \
    place = (char *)malloc(col_size + (M)*str_size); \
    arr = (type **)(place); \
    for(i = 0; i < (M); ++i){ \
        arr[i] = (type *)((place) + col_size + i*str_size); \
    }\
  }

int pref_func2(char *str1, char *str2);
void permut(short arr, int nel);
short init_arr(int m);
short erase_q_arr(short arr, int q);
int *add_q_cort(int *cort, int q, int i);
void show_cort(int *cort, int nel);

char **container; //Хранилище строк
int **matrix;  //матрица смежности
int pi[MAX_LENGTH*2];

int main(void)
{
    int n, i;
    scanf("%d ", &n);
    // Выделение памяти под строки и считывание
    char *place1;
    MATRIX_MALLOC(place1, container, n, MAX_LENGTH, char);
    for (i = 0; i < n; ++i){
        scanf("%s", container[i]);
//        out("%s, ", container[i]);
    }
    char *place2;
    MATRIX_MALLOC(place2, matrix, n, n, int);
    int j;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            if(i == j){
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = pref_func2(container[j], container[i]);
            }

        }
    }
    permut(init_arr(n), n);
    free(place1);
    free(place2);
    return 0;
}
#define STR1_t ((t < len) ? str1[t] : str2[t - len])

int pref_func2(char *str1, char *str2)
{

    int i, t;
    pi[0] = t = 0;
    for (i = 1; str1[i]; ++i){
        while (t && str1[t] != str1[i]){
            t = pi[t-1];
        }
        if (str1[t] == str1[i]){
            ++t;
        }
        pi[i] = t;
    }

    int len = i;
    for (; str2[i-len]; ++i){
        while (t && STR1_t != str2[i-len]){
            t = pi[t-1];
        }
        if (STR1_t == str2[i-len]){
            ++t;
        }
        pi[i] = t;
    }
    out("str2 = %s str1 = %s\nSUM_LENGTH = %d, last pi = %d\n", str2, str1, i, pi[i-1]);
    out("LEN_OF_SECOND = %d, LEN_WITOUT_CROSS = %d\n\n", i - len, i - len - pi[i-1]);
    if (pi[i-1] < len && pi[i-1] < i - len) return (i - len - pi[i-1]);
    else return len > len-i ? len : len-i;
}

int shortest;
void count_least(int *cort, int nel)
{
    int i, current;
    for(i = current = 0; i < nel-1; ++i){
        current += matrix[cort[i]][cort[i+1]];
    }
    current += strlen(container[cort[i]]);
    out("CURRENT_LEN = %d", current);
    if(current < shortest){
        shortest = current;
    }
}

void permut_rec(short arr, int nel, int counter, int *cort)
{
    if(counter == nel){
//        show_cort(cort, counter);
        count_least(cort, nel);
        newline;
    } else {
        int i;
        for(i = 0; i < nel; ++i){
            if(GET_BIT(arr, i)){
                permut_rec(erase_q_arr(arr, i), nel, counter + 1, add_q_cort(cort, i, counter));
            }
        }
    }
}

void permut(short arr, int nel)
{
    int *cort = (int *)calloc(nel, sizeof(int));
    shortest = 10*MAX_LENGTH;
    permut_rec(arr, nel, 0, cort);
    free(cort);
    out("SHORTEST = ");
    printf("%d\n", shortest);
}
short init_arr(int m)
{
    return SET_BIT(m)-1;
}
short erase_q_arr(short arr, int q)
{
    return GET_BIT(arr, q) ? (arr ^ SET_BIT(q)) : arr;
}

int *add_q_cort(int *cort, int q, int i)
{
    cort[i] = q;
    return cort;
}

void show_cort(int *cort, int nel)
{
    int i;
    for(i = 0; i < nel; ++i){
        printf("[%d]%s ", cort[i], container[cort[i]]);
    }
    newline;
}