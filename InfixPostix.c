#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(char exp) {
    stack[++top] = exp;
}

char peek() {
    return stack[top];
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1;
}

int precedence(char exp) {

    if(exp=='(') {
        return 0;
    }
    if(exp=='+' || exp=='-') {
        return 1;
    }
    if(exp=='*' || exp=='/') {
        return 2;
    }
    return -1;
}

int infixToPostfix(char *postfix) {

    int i, k;
    for (i = 0, k = -1; postfix[i]; ++i) {
 
        if (isalnum(postfix[i])) {
            postfix[++k] = postfix[i];
        }
        else if (postfix[i] == '(') {
            push(postfix[i]);
        }
        else if (postfix[i] == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[++k] = pop();
            if (peek() == '(')
                pop();
        }
        else {
            while (!isEmpty() && precedence(postfix[i]) <= precedence(peek())) 
                postfix[++k] = pop(); 
            push(postfix[i]);
        }
    }
    while (!isEmpty()) {
        postfix[++k] = pop();
    } postfix[++k] = '\0';

    printf("%s\n", postfix);

return 0;
}

int main() {

   char infix[] = "A+(B+C*D+E)+F/G";
   infixToPostfix(infix);

return 0;
}