#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void insert(struct Node **head)
{
    struct Node* newNode =  (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Warning: Failed to allocate memory\n");
        return;
    }

    int pos;
    printf("Enter the position to insert in: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > (*head)->data + 1)
    {
        printf("Warning: Invalid position, please enter a value between 1 to %d!\n", ((*head)->data+1));
        return;
    }

    ((*head)->data)++;
    while (pos--)
    {
        head = &(*head)->next;
    }
    printf("Enter the data to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->next = *head;
    *head = newNode;
}

void delete (struct Node *head)
{
    if (head->next == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return;
    }

    int pos;
    printf("Enter the position to delete from: ");
    scanf("%d", &pos);
    if (pos > head->data || pos < 1) {
        printf("Warning: Invalid position, list contains elements between 1 to %d\n", head->data);
        return;
    }

    (head->data)--;

    struct Node* temp = head->next;
    if (pos == 1) {
        printf("Element deleted is: %d\n", temp->data);
        head->next = temp->next;
        temp->next = NULL;
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    struct Node* del = temp->next;
    printf("Element deleted is: %d\n", del->data);
    temp->next = del->next;
    del->next = NULL;
    free(del);
}

void traverse(struct Node *head)
{
    if (head->next == NULL)
    {
        printf("Underflow Warning: Stack is empty\n");
        return;
    }
    printf("Number of nodes: %d\nNodes: ", head->data);
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
        printf("MENU\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\nSelect Operation: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {   
                insert(&Header);
                break;
            }
            case 2:
            {
                delete(Header);
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