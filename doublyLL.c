#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void push(struct Node **linkedList, int data)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *linkedList;
    *linkedList = newNode;
}

void traverse(struct Node *linkedList) 
{
    while (linkedList != NULL) {
        printf("%d ", linkedList->data);
        linkedList = linkedList->next;
    } printf("\n");
}

int main() {

    struct Node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    traverse(head);

return 0;
}