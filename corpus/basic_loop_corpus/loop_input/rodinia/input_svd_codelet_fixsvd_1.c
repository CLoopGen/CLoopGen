#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

VEC *d;
MAT *U;
MAT *V;
int i;
int j;
int k;
int l;
int r;
int stack[100];
int sp;
double tmp;
double v;

static double *alloc_2d_row(size_t n) {
    return (double *)aligned_alloc(sizeof(double), n * sizeof(double));
}

void init_vars() {
    const int size = 65536; // ~512KB for d->ve, scales with U/V cols

    // Initialize d vector
    d = (VEC *)malloc(sizeof(VEC));
    d->dim = size;
    d->max_dim = size;
    d->ve = (double *)malloc(size * sizeof(double));

    // Initialize random-like data with descending order to ensure partitioning occurs
    for (int idx = 0; idx < size; idx++) {
        d->ve[idx] = (double)(size - idx);
    }

    // Initialize U matrix: transpose of d if needed, size x 64 columns (~32MB total)
    U = (MAT *)malloc(sizeof(MAT));
    U->m = size;
    U->n = 64;
    U->max_m = size;
    U->max_n = 64;
    U->max_size = size * 64;
    U->me = (double **)malloc(size * sizeof(double *));
    U->base = (double *)malloc(size * 64 * sizeof(double));
    
    for (int row = 0; row < size; row++) {
        U->me[row] = U->base + row * 64;
        for (int col = 0; col < 64; col++) {
            U->me[row][col] = (double)(row + col);
        }
    }

    // Initialize V matrix: smaller, size x 16 columns (~8MB)
    V = (MAT *)malloc(sizeof(MAT));
    V->m = size;
    V->n = 16;
    V->max_m = size;
    V->max_n = 16;
    V->max_size = size * 16;
    V->me = (double **)malloc(size * sizeof(double *));
    V->base = (double *)malloc(size * 16 * sizeof(double));
    
    for (int row = 0; row < size; row++) {
        V->me[row] = V->base + row * 16;
        for (int col = 0; col < 16; col++) {
            V->me[row][col] = (double)(row * 16 + col);
        }
    }

    // Set initial sort range
    l = 0;
    r = size - 1;
    sp = -1;
    tmp = 0.0;
    v = 0.0;
}