#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    if (position == 0) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    struct Node* temp = *head_ref;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is beyond the length of the list\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Traversal in reverse direction: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

// Main function to test the insert functions
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 1); // List: 1
    insertAtEnd(&head, 2);       // List: 1 -> 2
    insertAtEnd(&head, 4);       // List: 1 -> 2 -> 4
    insertAtPosition(&head, 3, 2); // List: 1 -> 2 -> 3 -> 4
    insertAtPosition(&head, 0, 0); // List: 0 -> 1 -> 2 -> 3 -> 4

    printList(head);

    return 0;
}