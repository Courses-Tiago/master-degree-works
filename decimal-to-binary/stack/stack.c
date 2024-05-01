#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack {
    int data;
    struct stack *next;
} stack_t;

void init_stack(stack_t **stack) {
    *stack = NULL;
}

bool is_empty(const stack_t *stack) {
    return stack == NULL;
}

void push(stack_t **stack, int data) {
    stack_t *new = (stack_t*)malloc(1 * sizeof(stack_t)); 
    if(new == NULL) {
        fprintf(stderr, "ERROR in 'push'\n");
        fprintf(stderr, "Fail to allocate new node!\n");
        exit(EXIT_FAILURE);
    }
    new->data = data;
    new->next = *stack;
    *stack = new;
}

int pop(stack_t **stack) {
    if(is_empty(*stack)) {
        puts("Stack is empty");
        return -1;
    }
    int removed_data;
    stack_t *new = *stack;
    removed_data = new->data;
    *stack = (*stack)->next;
    free(new);

    return removed_data;
}

void peek(const stack_t *stack) {
    if(is_empty(stack)) {
        fprintf(stderr, "ERROR in 'peek function'\n");
        fprintf(stderr, "Stack is Empty!\n");
        exit(EXIT_FAILURE);
    }
    printf("Current stack top content: %d\n", stack->data);
}

void free_all_stack(stack_t **stack) {
    stack_t *aux = *stack;
    if(is_empty(aux)) {
        printf("No memory to deallocate\n");
        return;
    }
    printf("Poping all stack..\n");
    while(aux->next != NULL) {
        pop(&aux);
    }
    // Removes the last one
    pop(&aux);
    *stack = NULL;
    printf("All Memory deallocated successfully!\n");
}
