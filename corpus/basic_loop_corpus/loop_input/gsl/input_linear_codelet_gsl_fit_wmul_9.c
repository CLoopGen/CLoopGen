#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double *x;
size_t xstride;
double *w;
size_t wstride;
double *y;
size_t ystride;
size_t n;

double W = 0.0;
double wm_x = 0.0;
double wm_y = 0.0;
size_t i;

void init_vars() {
    n = 16777216;  // ~134 MB of data (16M * 8 bytes per double * 8 arrays approx)
    xstride = 1;
    wstride = 1;
    ystride = 1;

    x = aligned_alloc(32, n * xstride * sizeof(double));
    w = aligned_alloc(32, n * wstride * sizeof(double));
    y = aligned_alloc(32, n * ystride * sizeof(double));

    for (size_t idx = 0; idx < n; idx++) {
        x[idx * xstride] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        w[idx * wstride] = (double)(rand() % 2);
        y[idx * ystride] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    W = 0.0;
    wm_x = 0.0;
    wm_y = 0.0;
}