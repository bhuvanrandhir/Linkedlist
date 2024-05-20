#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Assign data to the new node
    new_node->data = new_data;

    // If the position is the beginning of the list
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // Traverse to the node before the desired position
    struct Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    // If the position is beyond the end of the list
    if (current == NULL) {
        printf("Position is beyond the length of the list\n");
        free(new_node);
        return;
    }

    // Insert the new node at the desired position
    new_node->next = current->next;
    current->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the insertAtPosition function
int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Insert elements at specific positions
    insertAtPosition(&head, 1, 0); // List: 1
    insertAtPosition(&head, 2, 1); // List: 1 -> 2
    insertAtPosition(&head, 3, 1); // List: 1 -> 3 -> 2
    insertAtPosition(&head, 4, 2); // List: 1 -> 3 -> 4 -> 2

    // Print the linked list
    printList(head);

    return 0;
}