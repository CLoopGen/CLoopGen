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

void init_vars() {
    A = (MAT*)malloc(sizeof(MAT));
    A->m = 40;
    A->n = 40;
    A->max_m = 40;
    A->max_n = 40;
    A->max_size = 40 * 40;
    
    A->base = (double*)calloc(40 * 40, sizeof(double));
    
    A->me = (double**)malloc(40 * sizeof(double*));
    for (int idx = 0; idx < 40; idx++) {
        A->me[idx] = A->base + idx * 40;
    }
}