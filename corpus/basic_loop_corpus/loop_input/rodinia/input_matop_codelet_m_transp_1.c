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

MAT *in;
int i;
int j;
double tmp;

void init_vars() {
    in = (MAT *)malloc(sizeof(MAT));
    in->m = 1024;
    in->n = in->m;
    in->max_m = in->m;
    in->max_n = in->n;
    in->max_size = in->m * in->n;
    in->base = (double *)calloc(in->max_size, sizeof(double));
    in->me = (double **)malloc(in->m * sizeof(double *));
    for (u_int idx = 0; idx < in->m; idx++) {
        in->me[idx] = in->base + idx * in->n;
        for (u_int jdx = 0; jdx < in->n; jdx++) {
            in->me[idx][jdx] = (double)(idx * in->n + jdx);
        }
    }
}