#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double **matrix;
size_t rank = 1024;  // Approx. 1024x1024 -> ~8MB for doubles, sufficient for ~0.01s
long double **hp_matrix;
ssize_t i;
ssize_t j;

void init_vars() {
    rank = 1024;
    matrix = (double **)calloc(rank, sizeof(double*));
    hp_matrix = (long double **)calloc(rank, sizeof(long double*));

    for (size_t idx = 0; idx < rank; ++idx) {
        matrix[idx] = (double *)calloc(rank, sizeof(double));
        hp_matrix[idx] = (long double *)calloc(rank, sizeof(long double));
    }

    // Initialize hp_matrix with sample values to avoid undefined behavior
    for (size_t i_idx = 0; i_idx < rank; ++i_idx) {
        for (size_t j_idx = 0; j_idx < rank; ++j_idx) {
            hp_matrix[i_idx][j_idx] = (long double)(i_idx * rank + j_idx) / 1000.0L;
        }
    }
}