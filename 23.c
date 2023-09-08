#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stacks
#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize a stack
void init(struct Stack *stack) {
    stack->top = -1;
}

// Check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if a stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto a stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Pop an element from a stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Enqueue operation (insert) using two stacks
void enqueue(struct Stack *stack1, struct Stack *stack2, int data) {
    // Push the data onto stack1
    push(stack1, data);
}

// Dequeue operation (delete) using two stacks
int dequeue(struct Stack *stack1, struct Stack *stack2) {
    int data;

    // If both stacks are empty, the queue is empty
    if (isEmpty(stack1) && isEmpty(stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            data = pop(stack1);
            push(stack2, data);
        }
    }

    // Pop the front element from stack2
    data = pop(stack2);
    return data;
}

int main() {
    struct Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

    // Enqueue some elements
    enqueue(&stack1, &stack2, 1);
    enqueue(&stack1, &stack2, 2);
    enqueue(&stack1, &stack2, 3);

    // Dequeue and print elements
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));

    // Enqueue more elements
    enqueue(&stack1, &stack2, 4);
    enqueue(&stack1, &stack2, 5);

    // Dequeue and print remaining elements
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stacks
#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize a stack
void init(struct Stack *stack) {
    stack->top = -1;
}

// Check if a stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if a stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto a stack
void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Pop an element from a stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Enqueue operation (insert) using two stacks
void enqueue(struct Stack *stack1, struct Stack *stack2, int data) {
    // Push the data onto stack1
    push(stack1, data);
}

// Dequeue operation (delete) using two stacks
int dequeue(struct Stack *stack1, struct Stack *stack2) {
    int data;

    // If both stacks are empty, the queue is empty
    if (isEmpty(stack1) && isEmpty(stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            data = pop(stack1);
            push(stack2, data);
        }
    }

    // Pop the front element from stack2
    data = pop(stack2);
    return data;
}

int main() {
    struct Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

    // Enqueue some elements
    enqueue(&stack1, &stack2, 1);
    enqueue(&stack1, &stack2, 2);
    enqueue(&stack1, &stack2, 3);

    // Dequeue and print elements
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));

    // Enqueue more elements
    enqueue(&stack1, &stack2, 4);
    enqueue(&stack1, &stack2, 5);

    // Dequeue and print remaining elements
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));
    printf("Dequeue: %d\n", dequeue(&stack1, &stack2));

    return 0;
}
