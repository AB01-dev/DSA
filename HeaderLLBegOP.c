#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void push(struct Node **head)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Warning: No memory was allocated");
        return;
    }
    
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = (*head)->next;
    (*head)->next = newNode;
    ((*head)->data)++;
}

struct Node *pop(struct Node *head)
{
    if (head->next == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return head;
    }
    struct Node *temp = head->next;
    printf("%d popped\n", temp->data);
    head->next = temp->next;
    free(temp);
    (head->data)--;
    return head;
}

void traverse(struct Node *head)
{   
    if (head->next == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return;
    }
    printf("Number of nodes: %d\n", head->data);
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    } printf("\n");
}

int main() {

    struct Node *Header = (struct Node *)malloc(sizeof(struct Node));
    Header->data = 0;
    Header->next = NULL;

    int choice = 0;
    while (choice != 4)
    {
        printf("Select Operation:\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                push(&Header);
                break;
            }
            case 2:
            {
                Header = pop(Header);
                break;
            }
            case 3:
            {
                traverse(Header);
                break;
            }
            case 4: 
            {
                printf("Quiting...\n");
                break;
            }
            default:
            {
                printf("Invalid Operation!\n");
                break;
            }
        } printf("\n");
    } printf("End of loop\n");

return 0;
}