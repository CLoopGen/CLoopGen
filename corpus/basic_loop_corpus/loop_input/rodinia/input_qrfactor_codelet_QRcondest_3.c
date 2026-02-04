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

void init_vars() {
    limit = 1024; // Size chosen to make loop run ~0.01 seconds

    // Allocate and initialize QR matrix
    QR = (MAT*)malloc(sizeof(MAT));
    QR->m = limit;
    QR->n = limit;
    QR->max_m = limit;
    QR->max_n = limit;
    QR->max_size = limit * limit;
    QR->base = (double*)calloc(limit * limit, sizeof(double));
    QR->me = (double**)malloc(limit * sizeof(double*));
    for (int idx = 0; idx < limit; idx++) {
        QR->me[idx] = QR->base + idx * limit;
        for (int jdx = 0; jdx < limit; jdx++) {
            QR->me[idx][jdx] = (double)(idx - jdx) / (limit); // Ensure non-out-of-bounds access
        }
    }

    // Allocate and initialize y vector
    y = (VEC*)malloc(sizeof(VEC));
    y->dim = limit;
    y->max_dim = limit;
    y->ve = (double*)malloc(limit * sizeof(double));
    for (int idx = 0; idx < limit; idx++) {
        y->ve[idx] = 1.0;
    }

    sum = 0.0;
    i = 0;
    j = 0;
}