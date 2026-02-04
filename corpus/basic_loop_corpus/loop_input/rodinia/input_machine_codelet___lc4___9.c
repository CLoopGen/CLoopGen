#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *v0;
double *v1;
double *v2;
double *v3;
double *w;
int i;
int len2;
double a0;
double a1;
double a2;
double a3;
double tmp0;
double tmp1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime
    len2 = data_size / (8 * sizeof(double));   // Each iteration accesses 8 doubles (4 vectors * 2 elements)

    v0 = (double*)aligned_alloc(32, 2 * len2 * sizeof(double));
    v1 = (double*)aligned_alloc(32, 2 * len2 * sizeof(double));
    v2 = (double*)aligned_alloc(32, 2 * len2 * sizeof(double));
    v3 = (double*)aligned_alloc(32, 2 * len2 * sizeof(double));
    w  = (double*)aligned_alloc(32, 2 * len2 * sizeof(double));

    a0 = 1.5;
    a1 = 2.0;
    a2 = -0.5;
    a3 = 0.75;

    for (int j = 0; j < 2 * len2; j++) {
        v0[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        v1[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        v2[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        v3[j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        w[j]  = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}