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

MAT *C;
int i;

void init_vars() {
    C = (MAT *)malloc(sizeof(MAT));
    C->m = 4096;
    C->n = 4096;
    C->max_m = C->m;
    C->max_n = C->n;
    C->max_size = C->m * C->n;
    C->base = (double *)calloc(C->m * C->n, sizeof(double));
    C->me = (double **)malloc(C->m * sizeof(double *));
    
    for (u_int idx = 0; idx < C->m; idx++) {
        C->me[idx] = &(C->base[idx * C->n]);
        for (u_int jdx = 0; jdx < C->n; jdx++) {
            C->me[idx][jdx] = (double)(idx + jdx);
        }
    }

    i = 0;
}