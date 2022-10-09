#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

struct Queue 
{
	struct Node *front, *rear;
};

void enQueue(struct Queue *head, int data)
{
	struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
    if(newNode == NULL)  
    {  
        printf("Overflow Warning: No space available\n");  
        return;  
    }  
	newNode->data = data;
	newNode->next = NULL;
	if (head->rear == NULL)
    {
		head->front = head->rear = newNode;
		return;
	}
	head->rear->next = newNode;
	head->rear = newNode;
}

void deQueue(struct Queue *head)
{
	if (head->front == NULL)
    {
        printf("Underflow Warning: Queue is empty\n");
		return;
    }
	struct Node* temp = head->front;
	head->front = head->front->next;

	if (head->front == NULL)
    {
		head->rear = NULL;
    }
	free(temp);
}

void traverse(struct Queue* head) 
{
    if (head->front == NULL)
    {
        printf("Underflow Warning: Queue is empty\n");
		return;
    }
    struct Node* temp = head->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } printf("\n");
}

int main()
{
	struct Queue *linkedList = (struct Queue *) malloc(sizeof(struct Queue));
    linkedList->front = NULL;
    linkedList->rear = NULL;

    int data, pos, choice = 0;
    while (choice != 4)
    {
        printf("Select Operation:\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {   
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                enQueue(linkedList, data);
                break;
            }
            case 2:
            {
                deQueue(linkedList);
                break;
            }
            case 3:
            {
                traverse(linkedList);
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
