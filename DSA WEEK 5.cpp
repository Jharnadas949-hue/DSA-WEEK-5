#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create the linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    head = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;

    // Create remaining nodes
    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;  // Link new node to the list
        temp = temp->next;
    }

    printf("\nSingly linked list created successfully.\n");
}

// Function to display the linked list
void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List Elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    displayList();

    return 0;
}
