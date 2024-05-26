#ifndef MATRIX_H
#define MATRIX_H

int **create_matrix(int, int);
void fill_matrix(int **, int, int);
void print_matrix(int **, int, int, const char **);
void deallocate_matrix(int **, int);

#endif