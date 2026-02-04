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
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

MAT *mat;
VEC *vec;
u_int col;
u_int i0;
u_int i;
u_int lim;

static double** create_2d_double_array(u_int rows, u_int cols) {
    double **arr = (double**)calloc(rows, sizeof(double*));
    double *data = (double*)calloc(rows * cols, sizeof(double));
    for (u_int i = 0; i < rows; i++) {
        arr[i] = &(data[i * cols]);
    }
    return arr;
}

void init_vars() {
    const u_int total_size = 128 * (1 << 20); // ~128MB of data
    const u_int rows = 32768;
    const u_int cols = 512;
    const u_int vec_size = rows;

    mat = (MAT*)calloc(1, sizeof(MAT));
    vec = (VEC*)calloc(1, sizeof(VEC));

    mat->m = rows;
    mat->n = cols;
    mat->max_m = rows;
    mat->max_n = cols;
    mat->max_size = rows * cols;
    mat->me = create_2d_double_array(rows, cols);
    mat->base = (double*)calloc(rows * cols, sizeof(double));

    vec->dim = vec_size;
    vec->max_dim = vec_size;
    vec->ve = (double*)calloc(vec_size, sizeof(double));

    col = cols / 2;
    i0 = 0;
    lim = rows;

    for (u_int i = 0; i < vec_size; i++) {
        vec->ve[i] = (double)(i % 1000) / 10.0;
    }

    for (u_int i = 0; i < rows; i++) {
        for (u_int j = 0; j < cols; j++) {
            mat->me[i][j] = (double)((i + j) % 2000) / 20.0;
        }
    }
}