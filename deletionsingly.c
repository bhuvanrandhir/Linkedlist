#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    // If there's only one node in the list
    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Traverse to the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Free the last node
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a specific position
void deleteFromPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    // If the position is 0, delete the head
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node before the target position
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is beyond the length of the list
    if (temp == NULL || temp->next == NULL) return;

    // Node temp->next is the node to be deleted
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the delete functions
int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Manually creating the list: 1 -> 2 -> 3 -> 4
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    // Print the initial list
    printf("Initial list: ");
    printList(head);

    // Delete from the beginning
    deleteFromBeginning(&head);
    printf("After deleting from beginning: ");
    printList(head);

    // Delete from the end
    deleteFromEnd(&head);
    printf("After deleting from end: ");
    printList(head);

    // Delete from a specific position
    deleteFromPosition(&head, 1); // Deleting second node (index 1)
    printf("After deleting from position 1: ");
    printList(head);

    // Free the remaining nodes
    deleteFromBeginning(&head);
    deleteFromBeginning(&head);

    return 0;
}