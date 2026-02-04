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

MAT *in;
MAT *out;
int i;
int j;

void init_vars() {
    // Set dimensions to achieve ~1MB - 256MB of data; choose 1024x1024 for approx 8MB per matrix (double = 8 bytes)
    u_int m = 1024;
    u_int n = 1024;

    in = (MAT*)malloc(sizeof(MAT));
    out = (MAT*)malloc(sizeof(MAT));

    in->m = m;
    in->n = n;
    in->max_m = m;
    in->max_n = n;
    in->max_size = m * n;
    in->base = (double*)calloc(m * n, sizeof(double));
    in->me = (double**)malloc(m * sizeof(double*));
    for (u_int i = 0; i < m; i++) {
        in->me[i] = in->base + i * n;
    }

    out->m = n;
    out->n = m;
    out->max_m = n;
    out->max_n = m;
    out->max_size = m * n;
    out->base = (double*)calloc(m * n, sizeof(double));
    out->me = (double**)malloc(n * sizeof(double*));
    for (u_int j = 0; j < n; j++) {
        out->me[j] = out->base + j * m;
    }

    // Initialize input data with non-zero values to simulate real usage
    for (u_int i = 0; i < m; i++) {
        for (u_int j = 0; j < n; j++) {
            in->me[i][j] = (double)(i * n + j);
        }
    }
}