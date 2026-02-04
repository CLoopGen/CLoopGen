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

typedef struct {
    MAT *mat;
    int lb;
    int ub;
} BAND;

static double **Av_storage;
static MAT mat_instance;
static BAND A_instance;
BAND *A = &A_instance;
int lb;
int i;
int j;
double **Av;

void init_vars() {
    lb = 100;
    mat_instance.m = 100;
    mat_instance.n = 200;
    mat_instance.max_m = 100;
    mat_instance.max_n = 200;
    mat_instance.max_size = 20000;

    mat_instance.base = (double*)calloc(mat_instance.max_size, sizeof(double));
    mat_instance.me = (double**)calloc(mat_instance.max_m, sizeof(double*));
    for (u_int ii = 0; ii < mat_instance.m; ++ii) {
        mat_instance.me[ii] = mat_instance.base + ii * mat_instance.max_n;
    }

    A_instance.mat = &mat_instance;
    A_instance.lb = 0;
    A_instance.ub = lb - 1;

    Av_storage = (double**)calloc(lb, sizeof(double*));
    for (int ii = 0; ii < lb; ++ii) {
        Av_storage[ii] = (double*)calloc(mat_instance.n, sizeof(double));
    }
    Av = Av_storage;
}