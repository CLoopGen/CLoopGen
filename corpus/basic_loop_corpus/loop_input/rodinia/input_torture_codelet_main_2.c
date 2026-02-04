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
MAT *C;
int i;

void init_vars() {
    C = (MAT *)calloc(1, sizeof(MAT));
    C->m = 2048;
    C->n = 2048;
    C->max_m = C->m;
    C->max_n = C->n;
    C->max_size = C->m * C->n * sizeof(double);
    
    base_data = (double *)calloc(C->m * C->n, sizeof(double));
    me_data = (double **)calloc(C->m, sizeof(double *));
    
    for (u_int idx = 0; idx < C->m; idx++) {
        me_data[idx] = base_data + idx * C->n;
        for (u_int jdx = 0; jdx < C->n; jdx++) {
            me_data[idx][jdx] = (double)(idx + jdx);
        }
    }

    C->me = me_data;
    C->base = base_data;
}