#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    if (temp->next == *head_ref) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }

    last->next = temp->next;
    *head_ref = temp->next;
    free(temp);
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    if (temp->next == *head_ref) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    struct Node* second_last = NULL;
    while (temp->next != *head_ref) {
        second_last = temp;
        temp = temp->next;
    }

    second_last->next = *head_ref;
    free(temp);
}

// Function to delete a node from a specific position in the circular linked list
void deleteFromPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;

    if (position == 0) {
        deleteFromBeginning(head_ref);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 0; temp->next != *head_ref && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head_ref && position != 0) {
        printf("Position is beyond the length of the list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
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

// Main function to test the delete functions
int main() {
    struct Node* head = NULL;

    // Manually creating the circular list: 1 -> 2 -> 3 -> 4 -> (head)
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = head;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    second->next = head;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    third->next = head;
    second->next = third;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 4;
    fourth->next = head;
    third->next = fourth;

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