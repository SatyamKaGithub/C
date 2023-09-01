#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
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

void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %c.\n", value);
        return;
    }
    
    stack->items[++stack->top] = value;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
    
    return stack->items[stack->top--];
}

void reverseString(char *input) {
    struct Stack stack;
    initialize(&stack);
    
    // Push each character onto the stack
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }
    
    // Pop characters from the stack to get the reversed string
    for (int i = 0; i < strlen(input); i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[MAX_SIZE];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character
    input[strlen(input) - 1] = '\0';
    
    printf("Original string: %s\n", input);
    
    reverseString(input);
    
    printf("Reversed string: %s\n", input);
    
    return 0;
}