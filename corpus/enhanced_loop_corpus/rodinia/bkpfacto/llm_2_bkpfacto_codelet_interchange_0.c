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

extern MAT *A;
extern int i;
extern int j;
extern double tmp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access (simulated via pointer arithmetic)
    // Instead of accessing columns i and j directly, we use a stride over rows with base pointer adjustments.
    double *base_i = &(A->me[0][i]);
    double *base_j = &(A->me[0][j]);
    int stride = A->max_n; // Assuming row-major layout, stride is number of columns

    for (k = 0; k < i; k++) {
        double *elem_k_i = base_i + k * stride;
        double *elem_k_j = base_j + k * stride;
        tmp = (*elem_k_i);
        (*elem_k_i) = (*elem_k_j);
        (*elem_k_j) = tmp;
    }
}
