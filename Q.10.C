#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data), *temp;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to display linked list
void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse linked list using iteration
void reverseIterative() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;   // Store next
        current->next = prev;   // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead
        current = next;
    }

    head = prev;  // New head is the last processed node
    printf("\nLinked list reversed using iteration.\n");
}

// Function to reverse linked list using recursion
struct Node* reverseRecursive(struct Node* current) {
    // Base case: empty list or last node
    if (current == NULL || current->next == NULL)
        return current;

    // Reverse the rest of the list
    struct Node* newHead = reverseRecursive(current->next);

    // Make the next node point to the current node
    current->next->next = current;
    current->next = NULL;

    return newHead;
}

// Main function
int main() {
    int n, data, i;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }

    printf("\nOriginal ");
    displayList();

    // Reverse using iteration
    reverseIterative();
    displayList();

    // Reverse using recursion (to get back original)
    head = reverseRecursive(head);
    printf("\nLinked list reversed again using recursion.\n");
    displayList();

    return 0;
}
