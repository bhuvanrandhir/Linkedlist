#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    new_node->next = *head_ref;
    temp->next = new_node;
    *head_ref = new_node;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = *head_ref;
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL) {
        if (position != 0) {
            printf("Invalid position\n");
            free(new_node);
            return;
        }
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    if (position == 0) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; i < position - 1 && temp->next != *head_ref; i++) {
        temp = temp->next;
    }

    if (temp->next == *head_ref && position != 0) {
        printf("Position is beyond the length of the list\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
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