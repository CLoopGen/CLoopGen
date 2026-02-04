#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t rank = 512;
ssize_t *columns;
ssize_t *rows;
long double **hp_matrix;
ssize_t i;
ssize_t j;

void init_vars() {
    columns = (ssize_t *)malloc(rank * sizeof(ssize_t));
    rows = (ssize_t *)malloc(rank * sizeof(ssize_t));
    hp_matrix = (long double **)malloc(rank * sizeof(long double *));
    
    for (ssize_t idx = 0; idx < rank; idx++) {
        hp_matrix[idx] = (long double *)malloc(rank * sizeof(long double));
        for (ssize_t jdx = 0; jdx < rank; jdx++) {
            hp_matrix[idx][jdx] = (long double)(idx * rank + jdx);
        }
        columns[idx] = (idx % 2 == 0) ? (rank - 1 - idx) : idx;
        rows[idx] = idx;
    }
}