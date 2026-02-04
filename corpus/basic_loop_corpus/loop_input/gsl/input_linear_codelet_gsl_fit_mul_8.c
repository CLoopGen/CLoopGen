#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
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
    n = 10000000;  // Approximately 80 MB of data (10M * 8 bytes per double * 2 arrays)
    xstride = 1;
    ystride = 1;
    m_x = 1.5;
    m_y = 2.5;
    b = 0.8;
    d2 = 0.0;

    x = (double *)aligned_alloc(32, n * xstride * sizeof(double));
    y = (double *)aligned_alloc(32, n * ystride * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        x[idx * xstride] = 1.0 + 0.1 * idx / n;
        y[idx * ystride] = 2.0 + 0.2 * idx / n;
    }
}