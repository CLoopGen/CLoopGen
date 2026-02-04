#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *x;
size_t xstride;
double *w;
size_t wstride;
double *y;
size_t ystride;
size_t n;

double W;
double wm_x;
double wm_y;
double wm_dx2;
double wm_dxdy;
size_t i;

void init_vars() {
    n = 10000000;  // Adjusted to achieve ~0.01 sec runtime on modern CPU
    xstride = 1;
    wstride = 1;
    ystride = 1;

    x = (double*)aligned_alloc(32, n * xstride * sizeof(double));
    w = (double*)aligned_alloc(32, n * wstride * sizeof(double));
    y = (double*)aligned_alloc(32, n * ystride * sizeof(double));

    for (size_t idx = 0; idx < n; idx++) {
        x[idx * xstride] = (double)(idx % 1000) * 0.01;
        w[idx * wstride] = (double)((idx % 500) + 1) * 0.02;
        y[idx * ystride] = (double)(idx % 750) * 0.015;
    }

    W = 1.0;
    wm_x = 5.0;
    wm_y = 3.0;
    wm_dx2 = 0.0;
    wm_dxdy = 0.0;
    i = 0;
}