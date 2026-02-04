#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix;
int n;
double *out;
int i;
int j;
double *y;

void init_vars() {
    n = 1024; 

    matrix = (double*)aligned_alloc(32, n * n * sizeof(double));
    out = (double*)aligned_alloc(32, n * sizeof(double));
    y = (double*)aligned_alloc(32, n * sizeof(double));

    for (int idx = 0; idx < n * n; idx++) {
        matrix[idx] = 1.0 + 0.001 * (idx % 127);
    }

    for (int idx = 0; idx < n; idx++) {
        y[idx] = 2.0 * idx;
        out[idx] = 0.0;
    }
}