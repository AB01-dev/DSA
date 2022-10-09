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
    newNode->next = (*head)->next;
    (*head)->next = newNode;
    ((*head)->data)++;
}

struct Node *pop(struct Node *head)
{
    struct Node *temp = head->next;
    if (temp == head)
    {
        printf("Underflow Warning: Stack is empty\n");
        return head;
    }
    printf("%d popped\n", temp->data);
    head->next = head->next->next;
    free(temp);
    (head->data)--;
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
    struct Node *temp = head->next;
    if (temp == head)
    {
        printf("Underflow Warning: Stack is empty\n");
        return;
    }
    printf("Number of nodes: %d\n", head->data);
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } printf("\n");
}

int main() {

    struct Node *Header = (struct Node *)malloc(sizeof(struct Node));
    Header->data = 0;
    Header->next = Header;

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
                push(&Header, data);
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
            case 5:
            {
                scanf("%d", &pos);
                peek(Header, pos);
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