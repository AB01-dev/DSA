#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Overflow Warning: No memory allocated");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

struct Node *pop(struct Node *head)
{
    if (head == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return head;
    }
    struct Node *temp = head;
    printf("%d popped\n", temp->data);
    head = head->next;
    free(temp);
    return head;
}

void peek(struct Node *head, int position) 
{
    for (int i = 0; i < position-1 && head != NULL; i++)
    {
        head = head->next;
    } printf("%d is stored at postion %d", head->data, position);
}

void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    } printf("\n");
}

int main() {

    struct Node *stack = NULL;

    int data, pos, choice = 0;
    while (choice != 4)
    {
        printf("Select Operation:\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {   
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            }
            case 2:
            {
                stack = pop(stack);
                break;
            }
            case 3:
            {
                traverse(stack);
                break;
            }
            case 4: 
            {
                printf("Quiting...\n");
                break;
            }
            case 5:
            {
                scanf("%d", &pos);
                peek(stack, pos);
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