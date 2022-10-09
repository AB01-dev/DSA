#include <stdio.h>
#include <stdlib.h>

int isEmpty(int *Stack, int *top) {
    if (*top == -1)
        return 1;
    return 0;
}

int isFull(int *Stack, int *top, int size) {
    if (*top == size - 1)
        return 1;
    return 0;
}

void push(int *Stack, int *top) {
    int value; scanf("%d", &value);
    Stack[++(*top)] = value;
    printf("Pushed %d into the stack\n", value);
}

void pop(int *Stack, int *top) {
    if (isEmpty(Stack, top)) {
        printf("Underflow: Stack is empty\n");
        return;
    } printf("Popped %d from the stack\n", Stack[(*top)--]);
}

void peek(int *Stack, int *top) {
    if (isEmpty(Stack, top)) {
        printf("Stack is empty\n");
        return;
    } int value; scanf("%d", &value);
    int pos = value - 1;
    printf("%d is Present on position %d\n", Stack[pos], value);
}

void traverse(int *Stack, int *top) {
    if (isEmpty(Stack, top)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i < (*top) + 1; i++) {
        printf("%d ", Stack[i]);
    } printf("\n");
}

int main() {

    int size;
    printf("Enter the size of Stack: "); 
    scanf("%d", &size);
    int lst = -1; int *top = &lst;
    int *Stack = (int*)malloc(size * sizeof(int));

    int op = 0;
    
    while(op != 5) {

        printf("\nMenu\n1. Insertion\n2. Deletion\n3. Peek\n4. Traverse\n5. Exit\n\n");
        scanf("%d", &op);

        switch(op) {
            case 1: {
                if (isFull(Stack, top, size)) {
                    printf("Overflow: Stack is full\n");
                    break;
                }
                push(Stack, top);
                break;
            }
            case 2: {
                pop(Stack, top);
                break;
            }
            case 3: {
                peek(Stack, top);
                break;
            }
            case 4: {
                traverse(Stack, top);
                break;
            }
            case 5: {
                printf("Quiting...\n");
                break;
            }
            default: {
                printf("Invalid opeation\n");
                break;
            }
        }

    } printf("End of Loop\n");

return 0;
}