#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void overflowCheck(struct Node *linkedList)
{
    
}

void push(struct Node **linkedList, int data)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *linkedList;
    *linkedList = newNode;
}

void insertBetween(struct Node *linkedList, int data, int loc)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    int count = 1;

    while(count != loc-1)
    {
        linkedList = linkedList->next;
        count++;
    }
    newNode->data = data;
    newNode->next = linkedList->next;
    linkedList->next = newNode;

}

void insertAtEnd(struct Node *linkedList, int data)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;

    while(linkedList->next != NULL)
    {
        linkedList = linkedList->next;
    } 
    linkedList->next = newNode;
    newNode->next = NULL;
}

struct Node *deleteFirst(struct Node *linkedList)
{
    struct Node *temp = linkedList;
    linkedList = linkedList->next;
    free(temp);
    return linkedList;
}

struct Node *deleteIndex(struct Node *linkedList, int index)
{
    struct Node *temp = linkedList;
    struct Node *ptr = linkedList->next;
    int count = 0;
    while(count != index-1)
    {
        temp = temp->next;
        ptr = ptr->next;
        count++;
    } temp->next = ptr->next;
    free(ptr);
    return linkedList;
}

struct Node *deleteLast(struct Node *linkedList)
{
    struct Node *temp = linkedList;
    struct Node *ptr = linkedList->next;

    while (ptr->next != NULL)
    {
        temp = temp->next;
        ptr = ptr->next;
    } temp->next = NULL;
    free(ptr);
    return linkedList;
}

struct Node *deleteValue(struct Node *linkedList, int value)
{
    struct Node *temp = linkedList;
    struct Node *ptr = linkedList->next;
    while(ptr->data != value && ptr->next != NULL)
    {
        temp = temp->next;
        ptr = ptr->next;
    } 
    if (ptr->data == value)
    {
        temp->next = ptr->next;
        free(ptr);
    }
    return linkedList;
}

void traverse(struct Node *linkedList)
{
    while (linkedList != NULL)
    {
        printf("%d ", linkedList->data);
        linkedList = linkedList->next;
    } printf("\n");
}

int main() {

    struct Node *Head = NULL; 
    push(&Head, 1);
    push(&Head, 2);
    push(&Head, 3);
    push(&Head, 4);
    push(&Head, 5);
    traverse(Head);
    insertBetween(Head, 546, 6);
    traverse(Head);  
    insertAtEnd(Head, 9);
    traverse(Head);
    Head = deleteFirst(Head);
    traverse(Head);
    Head = deleteIndex(Head, 1);
    traverse(Head);
    insertAtEnd(Head, 0);
    traverse(Head);
    Head = deleteValue(Head, 9);
    traverse(Head);
    Head = deleteLast(Head);
    traverse(Head);

return 0;
}