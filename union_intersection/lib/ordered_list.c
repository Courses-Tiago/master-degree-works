#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ordered_list.h>
#include <errno.h>

void init_ordered_list(node_t **list) {
    *list = NULL;
}

void insert_node(node_t **list, int info) {
    if(*list == NULL) {
        *list = (node_t*) malloc(sizeof(node_t));

        if(*list == NULL) {
            printf("Fail to allocate memory for polynom\n");
            return;
        }

        (*list)->info = info;
        (*list)->next = NULL;

    } else {
        node_t *previous = NULL;
        node_t *aux = *list;

        while((aux != NULL) && (aux->info < info)) {
            previous = aux;
            aux = aux->next;
        } 

        if(aux != NULL && aux->info == info) {
            errno = -2;
            return;
        }

        aux = (node_t*) malloc(sizeof(node_t));
        aux->info = info;

        if(previous == NULL) {
            aux->next = *list;
            *list = aux;
        } else {
            aux->next = previous->next;
            previous->next = aux;
        }

    }
}

void print_list(node_t *list) {
    node_t *aux = list;
    printf("List -> ");
    while(aux != NULL) {
        printf("%d", aux->info);
        
        if(aux->next != NULL) printf(" -> ");

        aux = aux->next;
    }
    putchar('\n');
}

void free_list(node_t  **list) {
    node_t *aux = *list;
    while(aux != NULL) {
        node_t *next = aux->next;
        free(aux);
        aux = next;
    }

    *list = NULL;
}