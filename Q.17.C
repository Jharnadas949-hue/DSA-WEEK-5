#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push element to stack
void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// Function to pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate prefix expression
int evaluatePrefix(char *exp) {
    int length = strlen(exp);

    // Scan from right to left
    for (int i = length - 1; i >= 0; i--) {
        char c = exp[i];

        // If operand, push onto stack
        if (isdigit(c)) {
            push(c - '0'); // convert char to integer
        }
        // If operator, pop two elements and apply operator
        else {
            int val1 = pop();
            int val2 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
        }
    }

    // Final result
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", exp);

    int result = evaluatePrefix(exp);
    printf("Result = %d\n", result);

    return 0;
}
