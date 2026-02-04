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
int i;
int j;
double tmp;
int k;

void init_vars() {
    const u_int matrix_size = 2048;  // ~32MB for double elements (2048x2048 * 8 bytes)
    
    A = (MAT *)calloc(1, sizeof(MAT));
    A->m = matrix_size;
    A->n = matrix_size;
    A->max_m = matrix_size;
    A->max_n = matrix_size;
    A->max_size = matrix_size * matrix_size;
    
    A->base = (double *)calloc(matrix_size * matrix_size, sizeof(double));
    A->me = (double **)calloc(matrix_size, sizeof(double*));
    
    for (u_int idx = 0; idx < matrix_size; idx++) {
        A->me[idx] = &(A->base[idx * matrix_size]);
    }
    
    // Ensure i and j are within valid range and i+1 < j to allow loop execution
    i = 100;
    j = 500;
    
    tmp = 0.0;
    k = 0;
}