#include <stdio.h>

#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

void push(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } 
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void pop() {
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("%d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    } 
}

void peek() {
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    } printf("%d\n", queue[front]);
}

void traverse() {
    if (rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i < rear + 1; i++) {
        printf("%d ", queue[i]);
    } printf("\n");
}

int main() {

    int val, op = 0;

    while (op != 5) {

        printf("\nMenu\n1. Enque\n2. Deueue\n3. Peek\n4. Traverse\n5. Exit\n\n");
        scanf("%d", &op);

        switch (op) {
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
                printf("Invalid operation\n");
                break;
            }
        }
    } printf("End of loop\n");

return 0;
}