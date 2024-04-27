#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynom.h"

typedef struct polynom {
    term_t term;
    struct polynom *next;
} polynom_t;

void init_polynom(polynom_t **polynom) {
    *polynom = NULL;
}

void insert_term(polynom_t **polynom, term_t term) {
    if(*polynom == NULL) {
        *polynom = (polynom_t*) malloc(sizeof(polynom_t));

        if(*polynom == NULL) {
            printf("Fail to allocate memory for polynom\n");
            return;
        }

        (*polynom)->term = term;
        (*polynom)->next = NULL;

    } else {
        polynom_t *previous = NULL;
        polynom_t *aux = *polynom;

        while((aux != NULL) && (aux->term.exponent < term.exponent)) {
            previous = aux;
            aux = aux->next;
        } 

        if(aux != NULL && aux->term.exponent == term.exponent) {
            aux->term.coefficient += term.coefficient;
            return;
        }

        aux = (polynom_t*) malloc(sizeof(polynom_t));
        aux->term = term;

        if(previous == NULL) {
            aux->next = *polynom;
            *polynom = aux;
        } else {
            aux->next = previous->next;
            previous->next = aux;
        }

    }
}

void print_polynom(polynom_t *polynom) {
    polynom_t *aux = polynom;
    printf("Polynom -> ");
    while(aux != NULL) {
        printf("%.1fx^%d", aux->term.coefficient, aux->term.exponent);
        
        if(aux->next != NULL) printf(" + ");

        aux = aux->next;
    }
    putchar('\n');
}

term_t create_term(float coefficient, int exponent) {
    term_t term = {
        coefficient, exponent
    };

    return term;
}

void free_polynom(polynom_t  **polynom) {
    polynom_t *aux = *polynom;
    while(aux != NULL) {
        polynom_t *next = aux->next;
        free(aux);
        aux = next;
    }

    *polynom = NULL;
}

double calc_polynom(polynom_t *polynom, double x) {
    polynom_t *aux = polynom;
    double acc = 0.0f;
    while(aux != NULL) {
        term_t term = aux->term;
        acc += (term.coefficient * (pow(x, term.exponent)));
        aux = aux->next;
    }

    return acc;
}