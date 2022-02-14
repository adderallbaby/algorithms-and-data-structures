#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// List
typedef struct Elem_List {
    int m_val;
    int m_key;
    struct Elem_List *m_next;
} List;

void addNodeList(List **head, int key, int m_val) {
    List *newElem = (List*)malloc(sizeof(List));

    newElem->m_key = key;
    newElem->m_val = m_val;
    newElem->m_next = NULL;

    if (*head == NULL) {
        *head = newElem;
        return;
    }

    List *curr = *head;
    while (curr->m_next != NULL) {
        if (curr->m_key == key) { break; }
        curr = curr->m_next;
    }

    if (curr->m_key != key) {
        curr->m_next = newElem;
    }
    else {
        curr->m_val = m_val;
        free(newElem);
    }
}
void removeByKey(List **head, int key) {
    List *curr = *head;
    List *prev = NULL;

    while (curr != NULL) {
        if (curr->m_key == key) { break; }
        prev = curr;
        curr = curr->m_next;
    }

    if (curr == NULL) { return; }

    if (prev != NULL) {
        prev->m_next = curr->m_next;
    }
    else {
        (*head) = (*head)->m_next;
    }
    free(curr);
}
List *findByKey(List *head, int key)
{
    while (head != NULL) {
        if (head->m_key == key) { break; }
        head = head->m_next;
    }
    return (head);
}


// Hash
typedef struct Elem_Hash
{
    List **m_list;
    int m_m;
} HashTable;

int calcHash(int k, int m) { return (k % m); }
void assign(HashTable *t, int key, int val) {
    int hash = calcHash(key, t->m_m);
    if (val == 0) {
        removeByKey(t->m_list + hash, key);
    }
    else {
        addNodeList(t->m_list + hash, key, val);
    }
}
int at(HashTable t, int key) {
    int hash = calcHash(key, t.m_m);

    if (t.m_list[hash] != NULL) {
        List *res = findByKey(t.m_list[hash], key);

        if (res != NULL) {
            return (res->m_val);
        }
    }
    return 0;
}


int main() {
    unsigned N;
    int m;
    scanf("%u %d", &N, &m);
    if (N == 0) { return -1; }

    HashTable table;
    table.m_list = (List **)calloc(m, sizeof(List *));
    table.m_m = m;

    for (unsigned i = 0; i < N; i++) {
        char str[7];
        int key, val;

        scanf("%s %d", str, &key);

        if (strcmp("ASSIGN", str) == 0) {
            scanf("%d", &val);
            assign(&table, key, val);
        }
        else {
            printf("%d\n", at(table, key));
        }
    }

    for (int i = 0; i < table.m_m; i++) {
        List *prev = NULL;
        while (table.m_list[i] != NULL) {
            prev = table.m_list[i];
            table.m_list[i] = table.m_list[i]->m_next;
            free(prev);
        }
    }
    free(table.m_list);

    return 0;
}