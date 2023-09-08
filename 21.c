#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int queue[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isEmpty(struct CircularQueue* cq) {
    return (cq->front == -1 && cq->rear == -1);
}

int isFull(struct CircularQueue* cq) {
    return ((cq->rear + 1) % MAX_SIZE == cq->front);
}

void COINSERT(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot insert.\n");
        return;
    } else if (isEmpty(cq)) {
        cq->front = cq->rear = 0;
    } else {
        cq->rear = (cq->rear + 1) % MAX_SIZE;
    }
    cq->queue[cq->rear] = value;
    printf("Element %d inserted successfully.\n", value);
}

void CQDELETE(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    } else if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    printf("Element removed successfully.\n");
}

int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);

    int choice, element;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. COINSERT\n");
        printf("2. CQDELETE\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                COINSERT(&cq, element);
                break;
            case 2:
                CQDELETE(&cq);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}