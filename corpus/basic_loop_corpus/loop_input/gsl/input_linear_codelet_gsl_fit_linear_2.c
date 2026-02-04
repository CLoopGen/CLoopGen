#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *x;
size_t xstride;
double *y;
size_t ystride;
size_t n;
double m_x;
double m_y;
size_t i;
double d2;
double b;

void init_vars() {
    n = 16777216; // ~16.7 million elements to target ~0.01 sec runtime
    xstride = 1;
    ystride = 1;

    x = (double*)aligned_alloc(32, n * xstride * sizeof(double));
    y = (double*)aligned_alloc(32, n * ystride * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    m_x = 1.5;
    m_y = 2.5;
    b = 0.75;
    d2 = 0.0;

    for (size_t idx = 0; idx < n; idx++) {
        x[idx * xstride] = 1.0 + 0.1 * idx / 1000.0;
        y[idx * ystride] = 2.0 + 0.1 * idx / 1000.0;
    }
}