#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node* head = NULL;

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("Node inserted at the end successfully!\n");
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted node with data: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* last = head->prev;
    struct Node* temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

// Function to display the circular doubly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}

// Main function with menu
int main() {
    int choice, data;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node from Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 2:
            deleteFromBeginning();
            break;

        case 3:
            displayList();
            break;

        case 4:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
