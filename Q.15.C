#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push onto stack
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

// Function to pop from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert Infix to Postfix
void infixToPostfix(char *infix, char *postfix) {
    top = -1; // reset stack
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

// Function to convert Infix to Prefix
void infixToPrefix(char *infix, char *prefix) {
    char revInfix[MAX], revPostfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);

    // Replace ( with ) and vice versa
    for (int i = 0; i < strlen(revInfix); i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    // Get postfix of reversed infix
    infixToPostfix(revInfix, revPostfix);

    // Reverse postfix to get prefix
    reverse(revPostfix);
    strcpy(prefix, revPostfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("\nInfix Expression: %s", infix);
    printf("\nPostfix Expression: %s", postfix);
    printf("\nPrefix Expression: %s\n", prefix);

    return 0;
}
