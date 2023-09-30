#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteNodesWithValue(struct Node** head, int value) {
    struct Node* current = *head;

    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
        }
        current = current->next;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 50);

    printf("Original List: ");
    display(head);

    deleteNodesWithValue(&head, 30);

    printf("List after deleting nodes with value 30: ");
    display(head);

    return 0;
}