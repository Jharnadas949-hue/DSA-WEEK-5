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

// Function to search for a value in the linked list
void searchValue(int value) {
    struct Node* temp = head;
    int position = 1, found = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
        printf("Value %d not found in the list.\n", value);
}


int main() {
    int n, data, value, i;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }

    displayList();

    printf("Enter value to search: ");
    scanf("%d", &value);

    searchValue(value);

    return 0;
}
