#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stacks
#define MAX 8

// Define the structure for the stack
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stacks
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if a stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Check if a stack is full
int isFull(struct Stack *s) {
    return (s->top == MAX - 1);
}

// Push an element onto a stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;              // top is incremented or top =  top+1;
    s->arr[s->top] = value;//store the value in the array of stack
}

// Pop an element from a stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    int value = s->arr[s->top];      // What ever value deleted stored in value, after poped out
    s->top--;                           //top is going to be decreased or top = top - 1;
    return value;
}

// Enqueue an element into the queue
void enqueue(struct Stack *s1, struct Stack *s2, int value) {
    // Push all elements from s1 to s2
    while (!isEmpty(s1)) {             // that means while s1  stack is not empty
        push(s2, pop(s1));             // it should push s2 and pop s1
    }
    // Push the new element onto s1
    push(s1, value);
    // Push back all elements from s2 to s1
    while (!isEmpty(s2)) {
        push(s1, pop(s2));
    }
}

// Dequeue an element from the queue
int dequeue(struct Stack *s1) {
    if (isEmpty(s1)) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(s1);
}

int main() {
    struct Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    enqueue(&stack1, &stack2, 80);
    enqueue(&stack1, &stack2, 90);
    enqueue(&stack1, &stack2, 30);

    printf("Dequeued: %d\n", dequeue(&stack1));
    printf("Dequeued: %d\n", dequeue(&stack1));
    printf("Dequeued: %d\n", dequeue(&stack1));

    return 0;
}
