#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct node {
    int info;
    struct node *next;
} node_t;

void init_ordered_list(node_t **list);

void insert_node(node_t **list, int info);

void print_list(node_t *list);

void free_list(node_t  **list);

#endif