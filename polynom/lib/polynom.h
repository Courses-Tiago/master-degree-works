#ifndef POLYNOM_H
#define POLYNOM_H

typedef struct polynom polynom_t;
typedef struct term {
    float coefficient;
    int exponent;
} term_t;

void init_polynom(polynom_t **polynom);
void free_polynom(polynom_t **polynom);
void insert_term(polynom_t **polynom, term_t term);
void print_polynom(polynom_t *polynom);
term_t create_term(float coefficient, int exponent);
double calc_polynom(polynom_t *polynom, double x);

#endif

