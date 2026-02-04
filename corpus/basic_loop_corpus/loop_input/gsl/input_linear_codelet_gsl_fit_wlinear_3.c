#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

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
size_t i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1 million elements (~8MB per array)
    n = data_size;
    xstride = 1;
    wstride = 1;
    ystride = 1;

    x = (double*)aligned_alloc(32, n * xstride * sizeof(double));
    w = (double*)aligned_alloc(32, n * wstride * sizeof(double));
    y = (double*)aligned_alloc(32, n * ystride * sizeof(double));

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < n; ++idx) {
        x[idx * xstride] = (double)(rand() % 1000) / 10.0;
        w[idx * wstride] = (double)(rand() % 100) / 100.0;
        y[idx * ystride] = (double)(rand() % 1000) / 10.0;
    }

    W = 0.0;
    wm_x = 0.0;
    wm_y = 0.0;
    i = 0;
}