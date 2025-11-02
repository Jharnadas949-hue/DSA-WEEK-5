#include <stdio.h>
#include <stdlib.h>

// Structure for a node in doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;  // Head pointer

// Function to create the doubly linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return;
    }

    head = NULL;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Doubly linked list created successfully!\n");
}

// Function to insert a node after a given node
void insertAfter(int key, int data) {
    struct Node* temp = head;

    // Search for the node with the given key
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node inserted after %d successfully!\n", key);
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

// Function to display the list
void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int choice, n, data, key;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Insert After a Given Node\n");
        printf("3. Delete From Beginning\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            printf("Enter value after which to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAfter(key, data);
            break;

        case 3:
            deleteFromBeginning();
            break;

        case 4:
            displayList();
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
