#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("\n%d pushed to stack.\n", value);
        display();
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No element to pop.\n");
    } else {
        printf("\n%d popped from stack.\n", stack[top]);
        top--;
        display();
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
