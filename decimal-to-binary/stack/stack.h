#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack stack_t;

/**
 * @brief Assign NULL to the stack pointer.
 * 
 * @param stack A pointer address to be initialized.
 */
void init_stack(stack_t **stack);

/**
 * @brief Checks if the stack is empty.
 * 
 * @param stack Object to be verified.
 * @return true if stack is empty, false otherwise.
 */
bool is_empty(const stack_t *stack);

/**
 * @brief Inserts data in the stack.
 * 
 * @param stack Double pointer to insert data.
 * @param data Value to insert in the stack.
 */
void push(stack_t **stack, int data);

/**
 * @brief Removes the last inserted data.
 * 
 * @param stack Double pointer to remove the data.
 */

/**
 * @brief Removes the last inserted data.
 * 
 * @param stack Double pointer to remove the data.
 * @return The removed data.
 */
int pop(stack_t **stack);

/**
 * @brief Prints the stack top content.
 * 
 * @param stack Object to print the contained data.
 */
void peek(const stack_t *stack);

/**
 * @brief Deallocates all memory on HEAP.
 * 
 * @param stack Double pointer to handle the stack.
 */
void free_all_stack(stack_t **stack);

#endif
