#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct EleList {
    int value;
    int key;
    struct EleList *next;
} List;

void getElementFilled(List *newEleelement, int key, int value){
    newEleelement->key = key;
    newEleelement->value = value;
    newEleelement->next = NULL;
}
void MapInsert(List **head, int key, int value) {
    List *newEleelement = (List*)malloc(sizeof(List));
    getElementFilled(newEleelement, key, value);
    if (!*head)  {
        *head = newEleelement;
        return;
    }

    List *currentElement = *head;
    while (currentElement->next != NULL) {
        if (currentElement->key == key) { break; }
        currentElement = currentElement->next;
    }

    if (currentElement->key != key) {
        currentElement->next = newEleelement;
    }
    else {
        currentElement->value = value;
        free(newEleelement);
    }
}
void MapDelete(List **head, int key) {
    List *currentElement = *head;
    List *previous = NULL;
    while (currentElement->key != key) {
        previous = currentElement;
        currentElement = currentElement->next;
    }

    //if (currentElement == NULL) { return; }

    if (previous) {
        currentElement = currentElement->next;
    }
    else {
        (*head) = (*head)->next;
    }
    free(currentElement);
}
List *MapSearch(List *head, int key)
{
    while (head != NULL) {
        if (head->key == key) { break; }
        head = head->next;
    }
    return (head);
}

typedef struct ElementOfDispercedArray
{
    List **list;
    int element;
} AssociatedList;

int getIndexViaHash(int k, int element) { return (k % element); }

int at(AssociatedList t, int key) {
    int hash = getIndexViaHash(key, t.element);

    if (t.list[hash] != NULL) {
        List *res = MapSearch(t.list[hash], key);

        if (res != NULL) {
            return (res->value);
        }
    }
    return 0;
}

void clearList(AssociatedList associatedList) {

    for (int i = 0; i < associatedList.element; i++) {
        List *previous = NULL;
        while (associatedList.list[i] != NULL) {
            previous = associatedList.list[i];
            associatedList.list[i] = associatedList.list[i]->next;
            free(previous);
        }
    }

}
void getDispercedArrayWorking(int N, AssociatedList associatedList){

    for (unsigned i = 0; i < N; i++) {
        char *str = (char *)calloc(10000000, sizeof(char));
        int key, value;

        scanf("%s %d",str,  &key);
        
        if (str[1] == 'S') {
            scanf("%d", &value);
            int hash = getIndexViaHash(key, associatedList.element);
            if (value == 0) {
                MapDelete(associatedList.list + hash, key);
            }
            else {
                MapInsert(associatedList.list + hash, key, value);
            }
        } else {
            printf("%d\n", at(associatedList, key));
        }

    }
}
int main() {
    unsigned N;
    int element;
    scanf("%u %d", &N, &element);
    AssociatedList associatedList;
    associatedList.list = (List **) calloc(element, sizeof(List *));
    associatedList.element = element;
    getDispercedArrayWorking(N, associatedList);
    clearList(associatedList);
    free(associatedList.list);
    return 0;

    }

