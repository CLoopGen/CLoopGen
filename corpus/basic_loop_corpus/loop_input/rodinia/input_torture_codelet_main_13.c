#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

VEC *v;
VEC *w;
MAT *B;
int i;
int j;

void init_vars() {
    // Set dimensions to achieve ~100ms runtime
    // Inner loop: B->m * B->n iterations, each doing a FMA
    // Aim for total memory around 64-128MB to ensure cache effects and measurable time

    u_int m = 4096;
    u_int n = 4096;

    // Allocate vectors v and w
    v = (VEC *)malloc(sizeof(VEC));
    w = (VEC *)malloc(sizeof(VEC));

    v->dim = n;
    v->max_dim = n;
    v->ve = (double *)aligned_alloc(32, n * sizeof(double));

    w->dim = m;
    w->max_dim = m;
    w->ve = (double *)aligned_alloc(32, m * sizeof(double));

    // Initialize vector elements to non-zero values
    for (u_int idx = 0; idx < m; idx++) {
        w->ve[idx] = 1.0 + (idx % 7);
    }
    for (u_int idx = 0; idx < n; idx++) {
        v->ve[idx] = 2.0 + (idx % 5);
    }

    // Allocate matrix B
    B = (MAT *)malloc(sizeof(MAT));
    B->m = m;
    B->n = n;
    B->max_m = m;
    B->max_n = n;
    B->max_size = m * n;
    B->base = (double *)aligned_alloc(32, m * n * sizeof(double));
    B->me = (double **)aligned_alloc(32, m * sizeof(double *));

    // Initialize row pointers for me[i][j]
    for (u_int idx = 0; idx < m; idx++) {
        B->me[idx] = B->base + idx * n;
    }

    // Initialize matrix elements to non-zero
    for (u_int i_idx = 0; i_idx < m; i_idx++) {
        for (u_int j_idx = 0; j_idx < n; j_idx++) {
            B->me[i_idx][j_idx] = 0.5;
        }
    }

    // Initialize loop indices
    i = 0;
    j = 0;
}