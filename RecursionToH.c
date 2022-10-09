#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) {
    if (top == -1)
        printf("Warning: Stack overflow");
    stack[top++] = val;
}

// void pop() {

// }

// void peek() {

// }

// void traverse() {

// }

void TowerOfHanoi(int n, int source, int helper, int destination) {

    if (n == 1) {
        printf("Moved disk 1 from source %d to destination %d\n", source, destination);
        return; 
    }

    TowerOfHanoi(n-1, source, helper, destination);
    printf("Moved disk %d from source %c to destination %c\n", stack[n], source, destination);
    TowerOfHanoi(n-1, helper, destination, source);
}

int main() {

    int n;
    for (int i = 0; i < n; i++) {
        push(i);
    }

return 0;
}