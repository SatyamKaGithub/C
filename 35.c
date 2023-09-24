#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
	{
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(struct Node** head, int data, int position) 
{
    struct Node* newNode = createNode(data);
    if (position == 1) 
	{
        newNode->next = *head;
        if (*head != NULL) 
		{
            (*head)->prev = newNode;
        }
        *head = newNode;
    } 
	else 
	{
        struct Node* current = *head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current != NULL) 
		{
            current = current->next;
            currentPosition++;
        }
        if (current == NULL) 
		{
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        newNode->next = current->next;
        if (current->next != NULL) 
		{
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void display(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
	{
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head = NULL;
    int data, position, numInsertions;

    printf("Enter the number of insertions: ");
    scanf("%d", &numInsertions);

    for (int i = 0; i < numInsertions; i++) 
	{
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        printf("Enter the position to insert at: ");
        scanf("%d", &position);
        insertAtPosition(&head, data, position);
    }


    printf("Doubly Linked List: ");
    display(head);

    return 0;
}