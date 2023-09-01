#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
struct Stack {
    int items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int popped = stack->items[stack->top--];
    return popped;
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->items[stack->top];
}
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 6);
    push(&stack, 7);

    push(&stack, 8);

    push(&stack, 5);

    push(&stack, 3);

    pop(&stack);

    push(&stack, 10);

    pop(&stack);
    pop(&stack);

    display(&stack);

    return 0;
}