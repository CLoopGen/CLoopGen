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
int k;
int k_min;
int k_max;

void init_vars() {
    k_min = 0;
    k_max = 10000;  // Ensures about 10k iterations, enough for measurable time

    A->max_m = k_max + 4;
    A->max_n = k_max + 4;
    A->m = A->max_m;
    A->n = A->max_n;
    A->max_size = A->max_m * A->max_n;

    base_data = (double*)calloc(A->max_size, sizeof(double));
    me_data = (double**)malloc(A->max_m * sizeof(double*));

    for (u_int i = 0; i < A->max_m; i++) {
        me_data[i] = base_data + i * A->max_n;
    }

    A->me = me_data;
    A->base = base_data;
}