#include<stdio.h>
#include<string.h> 
#include<limits.h>
#include<stdlib.h>

# define MAX 100
int top = -1;
char stack[MAX];

int isFull() {
    return top == MAX - 1;
}

int isEmpty() { 
    return top == -1; 
}

void push(char item) {
    if (isFull()) 
        return; 
	stack[++top] = item;
}

int pop() { 
    if (isEmpty()) 
        return INT_MIN; 
    return stack[top--]; 
} 

int peek(){ 
    if (isEmpty()) 
        return INT_MIN; 
    return stack[top]; 
} 

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) { 
    switch (ch) { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

void getPostfix(char* expression) {

    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) { 

        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        else if (expression[i] == '(') 
            push(expression[i]); 

        else if (expression[i] == ')') 
        { 
            while (!isEmpty() && peek() != '(') 
                expression[++j] = pop(); 
            if (!isEmpty() && peek() != '(') 
                return; // invalid expression              
            else
                pop(); 
        } 
        else
        { 
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek())) 
                expression[++j] = pop(); 
            push(expression[i]); 
        } 

    } 

    while (!isEmpty()) 
        expression[++j] = pop(); 

    expression[++j] = '\0'; 

}

void reverse(char *exp) {
    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0') {
        temp[j] = exp[i];
        j--;
        i++;
    } strcpy(exp,temp);
}

void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0') {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp){
    int size = strlen(exp);
    reverse(exp);
    brackets(exp);  //change brackets
    getPostfix(exp);
    reverse(exp);
}

int main() {


    char expression[] = "a*b+c";
    printf("\nThe infix  value is: %s\n",expression);
    
    InfixtoPrefix(expression);

    printf("The prefix value is: %s\n",expression);

    return 0; 
}