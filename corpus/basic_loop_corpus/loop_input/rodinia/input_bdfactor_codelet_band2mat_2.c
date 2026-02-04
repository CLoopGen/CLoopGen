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

static double *alloc_1d_double(size_t n) {
    return (double *)calloc(n, sizeof(double));
}

static double **alloc_2d_double(size_t rows, size_t cols) {
    double **arr = (double **)calloc(rows, sizeof(double *));
    double *data = (double *)calloc(rows * cols, sizeof(double));
    for (size_t i = 0; i < rows; i++) {
        arr[i] = &data[i * cols];
    }
    return arr;
}

static void free_2d_double(double **arr) {
    if (arr) {
        free(arr[0]);
        free(arr);
    }
}

MAT *A;
int i;
int j;
int l;
int n = 2000;
int n1 = 1000;
int lb = 50;
int ub = 150;
double **bmat;

void init_vars() {
    A = (MAT *)calloc(1, sizeof(MAT));
    A->m = 2000;
    A->n = 2000;
    A->max_m = 2000;
    A->max_n = 2000;
    A->max_size = 2000 * 2000;
    
    A->me = alloc_2d_double(2000, 2000);
    A->base = alloc_1d_double(2000 * 2000);

    bmat = alloc_2d_double(300, 2000);
}