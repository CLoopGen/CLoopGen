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

int j;
MAT *Q;
MAT *H1;

void init_vars() {
    const u_int size = 8192;  // Approximate data size for ~0.01s runtime

    Q = (MAT *)calloc(1, sizeof(MAT));
    H1 = (MAT *)calloc(1, sizeof(MAT));

    Q->m = size;
    Q->n = size;
    Q->max_m = size;
    Q->max_n = size;
    Q->max_size = size * size;

    H1->m = size;
    H1->n = size;
    H1->max_m = size;
    H1->max_n = size;
    H1->max_size = size * size;

    H1->base = (double *)calloc(size * size, sizeof(double));
    H1->me = (double **)calloc(size, sizeof(double *));

    for (u_int i = 0; i < size; i++) {
        H1->me[i] = H1->base + i * size;
        for (u_int k = 0; k < size; k++) {
            H1->me[i][k] = (double)(i == k ? 2.0 : 0.5);  // Ensure diagonal is non-zero
        }
    }
}