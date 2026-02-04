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

MAT *Hout;
int i;
int j;
int limit;

void init_vars() {
    limit = 1500;

    Hout = (MAT *)malloc(sizeof(MAT));
    Hout->m = limit;
    Hout->n = limit;
    Hout->max_m = limit;
    Hout->max_n = limit;
    Hout->max_size = limit * limit;
    Hout->base = (double *)calloc(limit * limit, sizeof(double));
    Hout->me = (double **)malloc(limit * sizeof(double *));
    
    for (int idx = 0; idx < limit; idx++) {
        Hout->me[idx] = Hout->base + idx * limit;
    }
}