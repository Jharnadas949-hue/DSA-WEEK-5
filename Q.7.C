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

// Function to count occurrences of a given item
int countOccurrences(int item) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (temp->data == item)
            count++;
        temp = temp->next;
    }

    return count;
}

// Main function
int main() {
    int n, data, item, i, count;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }

    displayList();

    printf("Enter the item to count occurrences: ");
    scanf("%d", &item);

    count = countOccurrences(item);

    printf("The item %d occurs %d time(s) in the list.\n", item, count);

    return 0;
}
