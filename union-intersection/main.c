#include <stdio.h>
#include <stdlib.h>
#include <ordered_list.h>
#include <errno.h>

node_t* list_intersection (node_t *L1, node_t *L2);
node_t* list_union (node_t *L1, node_t *L2);

int main(void) {
    node_t *L1;
    
    init_ordered_list(&L1);

    insert_node(&L1, 9);
    insert_node(&L1, 11);
    insert_node(&L1, 10);
    insert_node(&L1, 2);
    printf("---L1---\n");
    print_list(L1);

    node_t *L2;
    init_ordered_list(&L2);
    insert_node(&L2, 9);
    insert_node(&L2, 5);
    insert_node(&L2, 1);
    insert_node(&L2, 11);
    printf("\n---L2---\n");
    print_list(L2);

    node_t *union_list = list_union(L1, L2);
    printf("\n---UNION---\n");
    print_list(union_list);

    node_t *intersection_list = list_intersection(L1, L2);
    printf("\n---INTERSECTION---\n");
    print_list(intersection_list);
    printf("\n---FIM---\n\n");

    free_list(&L1);
    free_list(&L2);
    free_list(&union_list);
    free_list(&intersection_list);
}

node_t* list_intersection (node_t *L1, node_t *L2) {
    node_t *intersection_list;
    node_t *union_list;

    init_ordered_list(&intersection_list);
    init_ordered_list(&union_list);

    node_t *aux = L1;

    while(aux != NULL) {
        insert_node(&union_list, aux->info);
        aux = aux->next;
    } 

    aux = L2;

    while(aux != NULL) {
        int err = insert_node(&union_list, aux->info);
        if(err == EDUPLICATEDVAL) {
            insert_node(&intersection_list, aux->info);
        }
        aux = aux->next;
    }

    free_list(&union_list);

    return intersection_list;
}

node_t* list_union(node_t *L1, node_t *L2) {
    node_t *union_list;

    init_ordered_list(&union_list);

    node_t *aux = L1;

    while(aux != NULL) {
        insert_node(&union_list, aux->info);
        aux = aux->next;
    } 

    aux = L2;

    while(aux != NULL) {
        insert_node(&union_list, aux->info);
        aux = aux->next;
    }

    return union_list;
}
