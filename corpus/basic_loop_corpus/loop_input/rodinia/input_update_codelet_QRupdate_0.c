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

MAT *R;
VEC *u;
int k;

void init_vars() {
    // Allocate and initialize VEC u
    u = (VEC*)malloc(sizeof(VEC));
    u->dim = 1000000;  // ~8MB for ve, ensures loop runtime around 0.01s
    u->max_dim = u->dim;
    u->ve = (double*)malloc(u->dim * sizeof(double));

    // Initialize most elements to non-zero, but ensure last few are zero so we don't scan entire array
    for (u_int i = 0; i < u->dim - 10; i++) {
        u->ve[i] = 1.0;
    }
    for (u_int i = u->dim - 10; i < u->dim; i++) {
        u->ve[i] = 0.0;  // Ensure loop stops early in valid range
    }

    // Allocate and initialize MAT R
    R = (MAT*)malloc(sizeof(MAT));
    R->m = u->dim;  // Match u->dim so k goes from R->m-1 downward
    R->n = 1;
    R->max_m = R->m;
    R->max_n = R->n;
    R->max_size = R->m;
    R->base = (double*)malloc(R->m * sizeof(double));
    R->me = (double**)malloc(R->m * sizeof(double*));
    for (u_int i = 0; i < R->m; i++) {
        R->me[i] = R->base + i;
    }
}

// Definitions of external symbols
MAT *R = NULL;
VEC *u = NULL;
int k = 0;