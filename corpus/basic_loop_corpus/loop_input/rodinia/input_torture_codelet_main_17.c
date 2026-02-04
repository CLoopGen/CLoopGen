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
MAT *D;
int i;

void init_vars() {
    D = (MAT *)calloc(1, sizeof(MAT));
    D->m = 1000;
    D->n = 1000;
    D->max_m = D->m;
    D->max_n = D->n;
    D->max_size = D->m * D->n;
    
    base_data = (double *)calloc(D->m * D->n, sizeof(double));
    me_data = (double **)calloc(D->m, sizeof(double *));
    
    for (u_int idx = 0; idx < D->m; idx++) {
        me_data[idx] = &base_data[idx * D->n];
        for (u_int jdx = 0; jdx < D->n; jdx++) {
            me_data[idx][jdx] = (double)(idx + jdx);
        }
    }
    
    D->me = me_data;
    D->base = base_data;
}