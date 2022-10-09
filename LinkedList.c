#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};
int size = 0;
    
void insert(struct Node **head)
{
    int pos;
    printf("Enter the position you want to: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    int data; 
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    struct Node* newNode =  (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    while (pos--) 
    {
        if (pos == 0) 
        {
            newNode->next = *head;
            *head = newNode;
        }
        head = &(*head)->next;
    }
    size++;
}

struct Node* delete(struct Node *head)
{
    if (head == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return head;
    }

    int pos;
    printf("Enter the position to delete from: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > size) {
        printf("Warning: Invalid position, please enter a position between 1 to %d\n", size + 1);
        return head;
    }
    
    struct Node* temp = head;
    if (pos == 1) {
        printf("\nElement deleted is : %d\n", temp->data);
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else {
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        struct Node* del = temp->next;     
        temp->next = temp->next->next;
        printf("\nElement deleted is : %d\n", del->data);
        del->next = NULL;
        free(del);
    }
    return head;
}

void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Warning: list is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    } printf("\n");
}

int main() {

    struct Node *Head = NULL; 
    
    int choice = 0;
    while (choice != 4)
    {
        printf("Select Operation:\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                insert(&Head);
                break;
            }
            case 2:
            {
                Head = delete(Head);
                break;
            }
            case 3:
            {
                traverse(Head);
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