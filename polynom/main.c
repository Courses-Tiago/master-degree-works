#include <stdio.h>
#include <stdlib.h>
#include <polynom.h>

int main(void) {

    double x = 2.0;
    polynom_t *polynom; 
    init_polynom(&polynom);

    term_t term1 = create_term(3.0, 2);
    term_t term2 = create_term(2.0, 3);
    term_t term3 = create_term(4.0, 2);
    term_t term4 = create_term(5.0, 7);

    insert_term(&polynom, term1);
    insert_term(&polynom, term2);
    insert_term(&polynom, term3);
    insert_term(&polynom, term4);

    print_polynom(polynom);

    printf("polynom calculation for x = %.1lf, result = %.1lf\n", x, calc_polynom(polynom, x));

    free_polynom(&polynom);

    return 0;
}