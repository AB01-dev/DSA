#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void push(struct Node ** LinkedList, int data) 
{
    if (LinkedList == NULL) 
    {
        printf("Empty");
        return;
    } struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = data;
    newNode->next = *LinkedList;
    *LinkedList = newNode;
}

void traverse(struct Node *LinkedList)
{
    while (LinkedList != NULL)
    {
        printf("%d ", LinkedList->data);
        LinkedList = LinkedList->next;
    } printf("\n");
}

int main() 
{

    struct Node *head = NULL;
    push(&head, 3);
    push(&head, 5);
    traverse(head);

return 0;
}