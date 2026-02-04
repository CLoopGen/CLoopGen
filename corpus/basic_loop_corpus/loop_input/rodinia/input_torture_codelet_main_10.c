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

VEC *w;
MAT *C;
double s1;
int i;
int j;

void init_vars() {
    const u_int size = 4096; // Approximate to get ~130MB of data: (4096^2)*8 / 1e6
    u_int m = size;
    u_int n = size;

    s1 = 1.5;

    w = (VEC *)malloc(sizeof(VEC));
    w->dim = n;
    w->max_dim = n;
    w->ve = (double *)aligned_alloc(32, n * sizeof(double));
    for (u_int idx = 0; idx < n; idx++) {
        w->ve[idx] = 1.0 + idx * 0.001;
    }

    C = (MAT *)malloc(sizeof(MAT));
    C->m = m;
    C->n = n;
    C->max_m = m;
    C->max_n = n;
    C->max_size = m * n;
    C->base = (double *)aligned_alloc(32, m * n * sizeof(double));
    C->me = (double **)aligned_alloc(32, m * sizeof(double *));
    for (u_int idx = 0; idx < m; idx++) {
        C->me[idx] = C->base + idx * n;
        for (u_int jdx = 0; jdx < n; jdx++) {
            C->me[idx][jdx] = 0.1 * (idx + jdx);
        }
    }
}