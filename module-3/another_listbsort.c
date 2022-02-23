#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Elem Elem;
typedef struct SLL SLL;

struct Elem {
    struct Elem *next;
    char *word;
};
void cpy(void *a, void *b, int n) {
    unsigned char *A = (unsigned char *) a, *B = (unsigned char *) b;
    for (int i = 0; i < n; ++i) A[i] = B[i];
}
Elem* InitSingleLinkedList(const char* initializer) {

    Elem* SingleLinkedListSingleElement = malloc(sizeof(Elem));
    SingleLinkedListSingleElement->word = (char *)calloc(1000, sizeof(char));
    cpy(SingleLinkedListSingleElement->word, (void*) initializer, strlen(initializer));
    SingleLinkedListSingleElement->next = NULL;
    return SingleLinkedListSingleElement;
}

void InsertBeforeHead(Elem* list, Elem* add) {
    Elem *y;
    y = list;
    while (y->next) {
        y = y->next;
    }
    y->next= add;
}

void swap(Elem *head, Elem* after)
{
    char *buffer = head->word;
    head->word = after->word;
    after->word = buffer;
}
int compareCurrentWordAndNextWord (Elem* current){
    return (strlen(current->word) > strlen(current->next->word));
}
struct Elem *bsort(Elem *list)
{

    Elem *c;
    int len = 0;
    Elem *x = list;
    while (x) {
        len++;
        x = x->next;
    }
    int t = len - 1;
    while (t > 0)
    {
        int bound = t;
        c = list;
        int i = 0;
        t = 0;
        while (i < bound) {
            if (compareCurrentWordAndNextWord(c)) {
                swap(c, c->next);
                t = i;
            }
            i++;
            c = c->next;
        }
    }
    return list;
}

void revarray(void *base, unsigned long nel, unsigned long width)
{
    int i,j;
    unsigned char *c, *d, f;
    for (i=0; i<nel/2;i++) {
        for (j=0; j<width;j= j+1) {
            c=((unsigned char*)base + width*i+j);
            d=((unsigned char*)base + width*(nel-1-i)+j);
            f=*c;
            *c=*d;
            *d=f;
        }
    }
}
void makeZero(char* buffer, int j){
    int k;
    for (k=0;k<j;k++) {
        buffer[k]=0;
    }
}
void getPreviousWord(char* src, int index, Elem* SingleLinkedList){
    char output[1000];
    char final[1000];
    int counter = 0;
    makeZero(final, 1000);
    while ((src[index]!=' ') && (index!=-1)){
        output[counter] = src[index];
        index--;
        counter++;
    }
    int strl = strlen(output);
    revarray((void *) output, strl, sizeof output[0]);

    for(int i = 0; i < strl; i++) {
        if(output[i]!= '\n')
            final[i] = output[i];
    }
    makeZero(output, strl);

    Elem *x = InitSingleLinkedList(final);
    InsertBeforeHead(SingleLinkedList, x);
}
void getWordsSingleLinkedList(char *s,  Elem* SingleLinkedList)
{
    int i;
    for(i = 0; i < strlen(s) + 1; ++i){
        if((s[i]== ' ') || (s[i] == '\0')){

            getPreviousWord(s, i-1, SingleLinkedList);
        }
    }

}
void SingleLinkedListOperating(){
    char *input = (char *)calloc(1000000, sizeof(char));
    Elem* SingleLinkedList = InitSingleLinkedList("");
    fgets(input, 10000000, stdin);
    getWordsSingleLinkedList(input,SingleLinkedList);
    free(input);
    bsort(SingleLinkedList);
    Elem *element;
    Elem* buffer;
    element = SingleLinkedList->next;
    while (element) {
        printf("%s ", element->word);
        buffer = element;
        free(element->word);
        element = element->next;
        free(buffer);
    }
    free(element);
    free(SingleLinkedList->word);
    free(SingleLinkedList);
}
int main() {
    SingleLinkedListOperating();
    return 0;
}
