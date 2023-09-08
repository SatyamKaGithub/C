#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new Node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to search for an element in the list
struct Node* searchElement(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Element not found
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Insert some elements at the end
    insertEnd(&head, 10);
    insertEnd(&head, 30);
    insertEnd(&head, 20);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Linked List:\n");
    printList(head);

    int target = 30;
    struct Node* result = searchElement(head, target);

    if (result != NULL) {
        printf("%d found in the list.\n", target);
    } else {
        printf("%d not found in the list.\n", target);
    }

    // Free memory to prevent memory leaks
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}