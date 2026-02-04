#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

MAT *A;
int k;
int k_min;
int k_max;

static double** create_double_matrix(u_int rows, u_int cols) {
    double **matrix = (double**)calloc(rows, sizeof(double*));
    for (u_int i = 0; i < rows; ++i) {
        matrix[i] = (double*)calloc(cols, sizeof(double));
    }
    return matrix;
}

static double* create_double_array(u_int size) {
    return (double*)calloc(size, sizeof(double));
}

void init_vars() {
    A = (MAT*)calloc(1, sizeof(MAT));
    A->m = 2000;
    A->n = 2000;
    A->max_m = 2000;
    A->max_n = 2000;
    A->max_size = 2000;
    
    A->me = create_double_matrix(A->max_m + 2, A->max_n + 2);
    A->base = create_double_array((A->max_m + 2) * (A->max_n + 2));

    for (u_int i = 0; i < A->max_m + 2; ++i) {
        for (u_int j = 0; j < A->max_n + 2; ++j) {
            if (i > 0 && j == i - 1) {
                A->me[i][j] = 0.0;
            } else {
                A->me[i][j] = 1.0;
            }
        }
    }

    k_min = 0;
    k_max = 1000;
    k = 0;
}