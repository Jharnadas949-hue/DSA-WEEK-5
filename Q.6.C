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

// Function to insert node at the end
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

// Function to remove duplicate nodes
void removeDuplicates() {
    struct Node *current = head, *index, *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        index = current;
        while (index->next != NULL) {
            if (current->data == index->next->data) {
                // Duplicate found, delete it
                temp = index->next;
                index->next = index->next->next;
                free(temp);
            } else {
                index = index->next;
            }
        }
        current = current->next;
    }

    printf("Duplicate nodes removed successfully.\n");
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

    removeDuplicates();

    printf("\nAfter removing duplicates ");
    displayList();

    return 0;
}
