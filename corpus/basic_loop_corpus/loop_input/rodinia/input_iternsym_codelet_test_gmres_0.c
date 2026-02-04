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

int i = 1000;
MAT *R1;
int j;

void init_vars() {
    R1 = (MAT*)malloc(sizeof(MAT));
    R1->max_m = 2000;
    R1->max_n = 1000;
    R1->m = 0;
    R1->n = 0;
    R1->max_size = R1->max_m * R1->max_n;

    R1->base = (double*)calloc(R1->max_size, sizeof(double));
    R1->me = (double**)malloc(R1->max_m * sizeof(double*));
    for (u_int idx = 0; idx < R1->max_m; idx++) {
        R1->me[idx] = &(R1->base[idx * R1->max_n]);
    }

    i = 999;
}