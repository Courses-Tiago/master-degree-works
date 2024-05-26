#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

int **create_matrix(int, int);
void fill_matrix(int **, int, int);
void print_matrix(int **, int, int, const char **);
void deallocate_matrix(int **, int);

int **create_matrix(int rows, int columns) {
    int **matrix = (int **)calloc(rows, sizeof(int *));
    if(matrix == NULL) {
        puts("Matrix Allocation Error");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(columns, sizeof(int));
        if(matrix[i] == NULL) {
            deallocate_matrix(matrix, rows);
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

void fill_matrix(int **matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] = i + j;
        }
    }
}

void print_matrix(int **m, int rows, int columns, const char **places) {
    if(m == NULL) {
        puts("Empty matrix");
        return;
    }
    for(int j = 0; j < columns; j++) {
        printf("\t%s", places[j]);
    }
    puts("\n--------------------------------------------------------------");
    bool flag = false;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(!flag) {
                printf("%s\t", places[i]);
                flag = true;
            }
            printf("|%.2d\t", m[i][j]);
        }
        putchar('\n');
        flag = false;
    }
    putchar('\n');
}

void deallocate_matrix(int **m, int rows) {
    for(int i = 0; i < rows; i++) {
        if(m[i] != NULL)
            free(m[i]);
    }
    free(m);
}