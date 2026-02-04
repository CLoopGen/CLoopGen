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

MAT *D;
int i;

void init_vars() {
    D = (MAT *)malloc(sizeof(MAT));
    D->m = 2048; // ensures loop runs ~2048 iterations
    D->n = D->m;
    D->max_m = D->m;
    D->max_n = D->n;
    D->max_size = D->m * D->n * sizeof(double);
    
    D->base = (double *)calloc(D->m * D->n, sizeof(double));
    D->me = (double **)malloc(D->m * sizeof(double *));
    
    for (u_int idx = 0; idx < D->m; idx++) {
        D->me[idx] = &(D->base[idx * D->n]);
        for (u_int jdx = 0; jdx < D->n; jdx++) {
            D->me[idx][jdx] = 1.0;
        }
    }
}