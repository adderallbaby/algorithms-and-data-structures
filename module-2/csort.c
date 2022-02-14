#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(char *s, char ***w)
{
    char **words = NULL, *word = NULL, c = 1;
    unsigned long wordscount = 0, charscount = 0;
    while (c != '\0')
    {
        c = *(s++);
        if (c != ' ' && c != '\0')
        {

            if (charscount == 0)
                word = (char *)malloc(sizeof(char));

            else
                word = (char *)realloc(word, sizeof(char) * (charscount + 1));

            *(word + charscount) = c;

            charscount++;
        }

        else if (charscount != 0)

        {

            word = (char *)realloc(word, sizeof(char) * (charscount + 1));

            word[charscount] = '\0';

            charscount = 0;
            words = (char **)realloc(words, sizeof(char *) * (wordscount + 1));
            *(words + wordscount) = word;
            wordscount++;
        }
    }
    *w = words;
    return wordscount;
}

void csort(char *src, char *dest)
{
    char **words;
    int wcount = split(src, &words), null_term_idx = 0;
    int *count = (int*)malloc(sizeof(int)*wcount);
    for (int i = 0; i < wcount; i++){
        count[i] = 0;
    }
    for (int i = 0; i < wcount - 1; i++)
    {
        int let1 = strlen(words[i]);
        null_term_idx += let1 + 1;
        for (int j = i + 1; j < wcount; j++)
        {
            int let2 = strlen(words[j]);
            if (let1 > let2){
                count[i] += let2 + 1;
            }
            else{
                count[j] += let1 + 1;
            }
        }
    }

    null_term_idx += strlen(words[wcount - 1]);

    for (int i = 0; i < wcount; i++){
        strcpy(dest + count[i], words[i]);
    }
    for (int i = 0; i < wcount; i++){
        if (count[i] != 0){
            dest[count[i] - 1] = ' ';
        }
    }

    dest[null_term_idx] = '\0';

    for (int i = 0; i < wcount; i++){
        free(words[i]);
    }

    free(count);
    free(words);
}

void main()
{
    char *string, c;
    char **p = &string;
    int strlen = 0, tr_slen = -1;
    char *words = (char *)malloc(sizeof(char)), ch;
    scanf("%c", &ch);
    while (ch != '\n')
    {
        words[strlen] = ch;
        words = (char *)realloc(words, sizeof(char) * (++strlen + 1));
        scanf("%c", &ch);
    }
    words[strlen] = '\0';
    *p = words;
    char *sorted_string = (char*)malloc(sizeof(char)*strlen+1);
    csort(string, sorted_string);
    printf("%s\n", sorted_string);
    free(words);
    free(sorted_string);
}