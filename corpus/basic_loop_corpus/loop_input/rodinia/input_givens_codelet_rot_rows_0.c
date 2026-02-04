#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

MAT *mat;
MAT *out;
u_int i;
u_int k;
double c;
double s;
u_int j;
double temp;

static double** allocate_2d_array(u_int rows, u_int cols) {
    double **arr = malloc(rows * sizeof(double*));
    double *data = calloc(rows * cols, sizeof(double));
    for (u_int i = 0; i < rows; i++) {
        arr[i] = &(data[i * cols]);
    }
    return arr;
}

void init_vars() {
    // Set trigonometric coefficients
    c = 0.866025; // cos(30°)
    s = 0.5;      // sin(30°)

    // Determine size to target ~0.01s runtime: use matrix with ~1M elements per row
    u_int col_size = 1 << 20; // 1 million columns
    u_int row_size = 2;       // only two rows accessed

    // Allocate matrices
    mat = malloc(sizeof(MAT));
    out = malloc(sizeof(MAT));

    mat->m = row_size;
    mat->n = col_size;
    mat->max_m = row_size;
    mat->max_n = col_size;
    mat->max_size = row_size * col_size;
    mat->me = allocate_2d_array(row_size, col_size);
    mat->base = NULL;

    out->m = row_size;
    out->n = col_size;
    out->max_m = row_size;
    out->max_n = col_size;
    out->max_size = row_size * col_size;
    out->me = allocate_2d_array(row_size, col_size);
    out->base = NULL;

    // Initialize out matrix with non-zero values for meaningful computation
    for (u_int r = 0; r < row_size; r++) {
        for (u_int c_idx = 0; c_idx < col_size; c_idx++) {
            out->me[r][c_idx] = (double)(r + 1) * 0.1 + (double)c_idx * 1e-6;
        }
    }

    // Set loop indices within bounds
    i = 0;
    k = 1;

    // Initialize temp
    temp = 0.0;
}