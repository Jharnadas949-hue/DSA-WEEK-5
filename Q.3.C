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

// Function to insert at the end (for initial setup)
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

// Function to display the linked list
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

// Function to delete node from the beginning
void deleteFromBeginning() {
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Node deleted from the beginning (value = %d).\n", temp->data);
    free(temp);
}

// Function to delete node from the end
void deleteFromEnd() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If there's only one node
    if (head->next == NULL) {
        printf("Node deleted from the end (value = %d).\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Node deleted from the end (value = %d).\n", temp->data);
    free(temp);
}

// Function to delete node from a specific position
void deleteFromPosition(int position) {
    struct Node *temp = head, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // Delete first node
    if (position == 1) {
        head = head->next;
        printf("Node deleted from position %d (value = %d).\n", position, temp->data);
        free(temp);
        return;
    }

    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    printf("Node deleted from position %d (value = %d).\n", position, temp->data);
    free(temp);
}

// Main function with menu
int main() {
    int choice, data, position;

    // Creating a small initial list for testing
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    while (1) {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Specific Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            deleteFromBeginning();
            break;
        case 2:
            deleteFromEnd();
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;
        case 4:
            displayList();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
