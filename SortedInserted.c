#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void sortedInsert(struct Node** head_ref)
{
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
	struct Node* temp;
    int data;
    scanf("%d", &data);
	newNode->data = data;
	newNode->next = NULL;
	if (*head_ref == NULL || (*head_ref)->data >= newNode->data) {
	    newNode->next = *head_ref;
		*head_ref = newNode;
	}
	else {
		temp = *head_ref;
		while (temp->next != NULL
			&& temp->next->data < newNode->data) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void traverse(struct Node* linkedList)
{
	while (linkedList != NULL) {
		printf("%d ", linkedList->data);
		linkedList = linkedList->next;
	} printf("\n");
}

int main()
{
	struct Node* head = NULL;
	
    int choice = 0;
    while (choice != 3)
    {
        printf("MENU\n1. Insert\n2. Traverse\n3. Exit\nSelect Operation: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {   
                sortedInsert(&head);
                break;
            }
            case 2:
            {
                traverse(head);
                break;
            }
            case 3: 
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
