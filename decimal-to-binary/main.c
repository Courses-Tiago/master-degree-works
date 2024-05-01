#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack/stack.h"

#define SIZE_OF_INT_IN_BITS     (8 * sizeof(int))

int *decimal_to_binary(int, int *);

int main(int argc, char **argv) {
    if(argc != 2) {
        puts("Please, type a decimal number to be printed as binary.\n");
        puts("The number must be greather than zero.");
        puts("Example:");
        puts("./executable 100\n");
        return EXIT_FAILURE;
    }
    printf("Decimal number: %s\n", argv[1]);
    int decimal = (int)strtol(argv[1], NULL, 10);
    if(decimal <= 0) {
        puts("Invalid number, please type a number greather than zero");
        return EXIT_FAILURE;
    }
    int size = 0;
    int *ptr = decimal_to_binary(decimal, &size);

    printf("0b");
    for(int i = 0; i < size; i++) {
        printf("%d", ptr[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

int *decimal_to_binary(int decimal, int *size){
    stack_t *stack = NULL;
    bool detect_one = false;
    int num_of_bits = 0;
    int aux_array[SIZE_OF_INT_IN_BITS];
    for(int i = 0; i < SIZE_OF_INT_IN_BITS; i++) {
        push(&stack, ((decimal >> i) & 0x1));
    }
    for(int i = 0; i < SIZE_OF_INT_IN_BITS; i++) {
        aux_array[i] = pop(&stack);
        if(aux_array[i] && !detect_one)
            detect_one = true;
        if(detect_one)
            num_of_bits++;
    }
    int *p = (int *)calloc(num_of_bits, sizeof(int));
    if(p == NULL) {
        puts("Fail to allocate pointer");
        return NULL;
    }
    int init_valid_binary = (SIZE_OF_INT_IN_BITS - num_of_bits);
    int index = 0;
    for(int i = init_valid_binary; i < SIZE_OF_INT_IN_BITS; i++) {
        p[index] = aux_array[i];
        index++;
    }
    *size = num_of_bits;
    return p;
}