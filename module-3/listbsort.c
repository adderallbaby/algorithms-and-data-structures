#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Elem Elem;
typedef struct SLL SLL;

struct Elem {
	struct Elem *next;
	char *word;
};

Elem* InitSingleLinkedList(char* str) {
	Elem* tmp = (Elem *)calloc(1, sizeof(Elem));
	tmp->word = (char *)calloc(100, sizeof(char));
	strcpy(tmp->word, str);
	tmp->next = NULL;
	return tmp;
}

void InsertBeforeHead(Elem* list, Elem* add) {
	Elem *y;
	while (list != NULL) {
		y = list;
		list = list->next;
	}
	y->next = add;
}

void swap(Elem *head, Elem* after)
{
	char *temp = head->word;
	head->word = after->word;
	after->word = temp;
}
int length(Elem *l)
{
	int len = 0;
	Elem *x = l;
	while (x != NULL) {
		len++;
		x = x->next;
	}
	return len;
}
struct Elem *bsort(Elem *list)
{
	Elem *current;
	int t = length(list) - 1;
	while (t > 0)
	{
		int bound = t;
		current = list;
		int i = 0;
		t = 0;
		while (i < bound) {
			if (strlen(current->word) > strlen(current->next->word)) {
				swap(current, current->next);
				t = i;
			}
			i++;
			current = current->next;
		}
	}
	return list;
}
void printList(Elem* SingleLinkedList){
	Elem *freer;
	Elem* buffer;
	freer = SingleLinkedList->next;
	while (freer != NULL) {
		buffer = freer;
		printf("%s ", freer->word);
		free(freer->word);
		freer = freer->next;
		free(buffer);
	}
}
int main() {
	char *input = (char *)calloc(1000000, sizeof(char));
	Elem* SingleLinkedList = InitSingleLinkedList("");
	fgets(input, 1000000, stdin);
	char *newline = strchr(input, '\n');
	if (newline) *newline = '\0';
	char *token = strtok(input, " ");
	while (token != NULL) {
		//Elem *x = (Elem*)malloc(sizeof (Elem));
		Elem *x = InitSingleLinkedList(token);
		InsertBeforeHead(SingleLinkedList, x);
		token = strtok(NULL, " ");
	}
	free(input);
	bsort(SingleLinkedList);
	printList(SingleLinkedList);
	//Elem* a = bsort(SingleLinkedList);
	//printList(a);
	free(SingleLinkedList->word);
	free(SingleLinkedList);
	return 0;
}