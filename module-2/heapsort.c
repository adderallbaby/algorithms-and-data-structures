#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t width)
{
    void *temp = malloc(width);
    memcpy(temp, a, width);
    memcpy(a, b, width);
    memcpy(b, temp, width);
    free(temp);
}

void heapify(void *base, int i, size_t n, size_t width,
             int (*compare)(const void *a, const void *b))
{
    while (1) {
        int l, r, j;

        l = 2 * i + 1;
        r = l + 1;
        j = i;
        if ((l < n) && (compare((char*)base + width * i, (char*)base + width * l) < 0))
            i = l;
        if ((r < n) && (compare((char*)base + width * i,(char*)base + width*r) < 0))
            i = r;
        if (i == j)
            break;
        swap((char*)base + i * width, (char*)base + j * width, width);
    }
}

void build_heap(void *base, size_t nel, size_t width,
                int (*compare)(const void *a, const void *b))
{
    int i = nel / 2 - 1;

    while(i >= 0)
    {
        heapify(base, i, nel, width, compare);
        i--;
    }
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b))
{
    build_heap(base, nel, width, compare);
    int i = nel - 1;

    while(i > 0)
    {
        swap((char*)base, (char*)base + i * width, width);
        heapify(base, 0, i, width, compare);
        i--;
    }
}

int char_count(char *a, char find)
{
    int count = 0;
    char c = *a;
    while(c)
    {
        if(c == find)
            count++;

        c = *(++a);
    }
    return count;
}

int compare(const void *a, const void *b)
{
    char *ca = *((char**)a), *cb = *((char**)b);
    return char_count(ca, 'a') - char_count(cb, 'a');
}

void helper(int size, char ***wordsarray)
{
    char **words = NULL;

    for(int i = 0; i < size; i++)
    {
        char c;
        scanf("%c", &c);
        int lengthoftheword = 0;
        char *word = (char*)malloc(sizeof(char));

        while(c != '\n')
        {
            word[lengthoftheword] = c;
            word = (char*)realloc(word, sizeof(char) * (++lengthoftheword + 1));
            scanf("%c", &c);
        }
        word[lengthoftheword] = '\0';

        words = (char**)realloc(words, sizeof(char*) * (i + 1));
        words[i] = word;
    }

    *wordsarray = words;
}

int main()
{
    int n;
    scanf("%i\n", &n);
    char **words;
    helper(n, &words);

    hsort(words, n, sizeof(char*), compare);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}