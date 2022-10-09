#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void push(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Overflow Warning: Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void pop() {
    if (front == -1) {
        printf("Underflow Warning: Queue is empty\n");
        return;
    }
    printf("%d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek() {
    if (front == -1) {
        printf("Underflow Warning: Queue is empty\n");
        return;
    } printf("%d\n", queue[front]);
}

void traverse() {
    if (front == -1) {
        printf("Underflow Warning: Queue is empty\n");
        return;
    } int i;
    for (i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    } printf("%d\n", queue[i]);
}

int main() {

    int val, op = 0;

    while (op != 5) {

        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Peeks\n4. Traverse\n5. Exit\n\n");
        scanf("%d", &val);

        switch (val) {
            case 1: {
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                peek();
                break;
            }
            case 4: {
                traverse();
                break;
            }
            case 5: {
                printf("Quiting...\n");
                break;
            }
            default: {
                printf("Invalid Operation\n");
                break;
            }
        }
    } printf("End of loop\n");

return 0;
}