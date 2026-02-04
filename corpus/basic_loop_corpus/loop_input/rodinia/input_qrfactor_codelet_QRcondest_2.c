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

MAT *QR;
VEC *y;
double sum;
int i;
int j;
int limit;

static double **alloc_2d_double(u_int rows, u_int cols) {
    double **arr = malloc(rows * sizeof(double*));
    double *data = calloc(rows * cols, sizeof(double));
    for (u_int i = 0; i < rows; i++)
        arr[i] = &(data[i * cols]);
    return arr;
}

static double *alloc_1d_double(u_int size) {
    return calloc(size, sizeof(double));
}

void init_vars() {
    limit = 2048;

    QR = malloc(sizeof(MAT));
    QR->m = limit;
    QR->n = limit;
    QR->max_m = limit;
    QR->max_n = limit;
    QR->max_size = limit * limit;
    QR->me = alloc_2d_double(limit, limit);
    QR->base = alloc_1d_double(limit * limit);

    y = malloc(sizeof(VEC));
    y->dim = limit;
    y->max_dim = limit;
    y->ve = alloc_1d_double(limit);

    sum = 0.0;
    i = 0;
    j = 0;

    for (int row = 0; row < limit; row++) {
        for (int col = 0; col < limit; col++) {
            QR->me[row][col] = (row == col) ? 2.0 : (abs(row - col) == 1 ? -1.0 : 0.0);
        }
    }

    for (int idx = 0; idx < limit; idx++) {
        y->ve[idx] = 1.0;
    }
}