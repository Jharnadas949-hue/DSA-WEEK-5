#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

// Structure for header node
struct Header {
    int count;
    struct Node* next;
};

struct Header* head = NULL;

// Function to create header node
void createHeader() {
    head = (struct Header*)malloc(sizeof(struct Header));
    head->count = 0;
    head->next = NULL;
}

// Function to insert a node at the end
void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL) {
        head->next = newNode;
    } else {
        struct Node* temp = head->next;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    head->count++;  // Update count
    printf("Node inserted successfully! Total nodes = %d\n", head->count);
}

// Function to delete a node from the beginning
void deleteNode() {
    if (head->next == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head->next;
    head->next = temp->next;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);

    head->count--;  // Update count
    printf("Total nodes after deletion = %d\n", head->count);
}

// Function to display list and count
void displayList() {
    if (head->next == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head->next;
    printf("Linked List Elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total elements (count in header): %d\n", head->count);
}

// Main function with menu
int main() {
    int choice, data;

    createHeader(); // Initialize header node

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node from Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(data);
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            displayList();
            break;

        case 4:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
