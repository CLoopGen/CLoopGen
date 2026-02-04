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

static MAT D_storage;
static double *data_block;
static double **row_pointers;
MAT *D = &D_storage;
int i;

void init_vars() {
    D->m = 1000;
    D->n = 1000;
    D->max_m = 1000;
    D->max_n = 1000;
    D->max_size = 1000000;

    data_block = (double *)calloc(D->m * D->n, sizeof(double));
    row_pointers = (double **)malloc(D->m * sizeof(double *));
    
    for (u_int idx = 0; idx < D->m; idx++) {
        row_pointers[idx] = &data_block[idx * D->n];
        for (u_int jdx = 0; jdx < D->n; jdx++) {
            row_pointers[idx][jdx] = (double)(idx * D->n + jdx);
        }
    }

    D->me = row_pointers;
    D->base = data_block;

    i = 0;
}