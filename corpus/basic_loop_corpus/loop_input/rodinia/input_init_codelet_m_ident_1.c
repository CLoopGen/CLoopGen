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

static double **me_data;
static double *base_data;
static MAT A_storage;
MAT *A = &A_storage;
int i;
int size;

void init_vars() {
    size = 10000; // Adjusted to achieve ~0.01 sec runtime
    
    base_data = (double *)calloc(size * size, sizeof(double));
    me_data = (double **)malloc(size * sizeof(double *));
    
    for (int idx = 0; idx < size; idx++) {
        me_data[idx] = base_data + idx * size;
    }
    
    A->m = size;
    A->n = size;
    A->max_m = size;
    A->max_n = size;
    A->max_size = size;
    A->me = me_data;
    A->base = base_data;
}