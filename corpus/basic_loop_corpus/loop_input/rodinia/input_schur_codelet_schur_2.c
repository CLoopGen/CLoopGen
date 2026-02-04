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
double **A_me;

void init_vars() {
    A = (MAT *)calloc(1, sizeof(MAT));
    A->m = 5000;
    A->n = 5000;
    A->max_m = A->m;
    A->max_n = A->n;
    A->max_size = A->m * A->n;
    
    A->base = (double *)calloc(A->max_size, sizeof(double));
    A->me = (double **)calloc(A->m, sizeof(double*));
    for (u_int idx = 0; idx < A->m; idx++) {
        A->me[idx] = A->base + idx * A->n;
    }
    
    A_me = A->me;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}