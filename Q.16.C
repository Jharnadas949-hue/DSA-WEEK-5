#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <math.h>    // for pow()
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If the character is a digit, push it to stack
        if (isdigit(c)) {
            push(c - '0'); // convert char to int
        }
        // If operator, pop two operands and apply operator
        else {
            int val2 = pop();
            int val1 = pop();

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
    // Final result on top of the stack
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
