#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %c\n", item);
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    } else {
        char item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}
bool areParenthesesBalanced(const char *expression) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            char popped = pop(&stack);
            if ((expression[i] == ')' && popped != '(') ||
                (expression[i] == ']' && popped != '[') ||
                (expression[i] == '}' && popped != '{')) {
                return false;
            }
        }
    }
    return stack.top == -1;
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}