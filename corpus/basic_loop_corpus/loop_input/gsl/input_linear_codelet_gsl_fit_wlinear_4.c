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
double wm_dx2;
double wm_dxdy;
size_t i;

double *x_data;
double *w_data;
double *y_data;

void init_vars() {
    const size_t data_size = 32 * 1024 * 1024; // ~256 MB of total data (3 arrays)
    n = data_size;
    xstride = 1;
    wstride = 1;
    ystride = 1;

    posix_memalign((void**)&x_data, 32, n * xstride * sizeof(double));
    posix_memalign((void**)&w_data, 32, n * wstride * sizeof(double));
    posix_memalign((void**)&y_data, 32, n * ystride * sizeof(double));

    x = x_data;
    w = w_data;
    y = y_data;

    srand(time(NULL));
    for (size_t idx = 0; idx < n; ++idx) {
        x[idx * xstride] = (double)(rand() % 1000) / 10.0;
        w[idx * wstride] = (double)(rand() % 100) / 100.0;
        y[idx * ystride] = (double)(rand() % 1000) / 10.0;
    }

    wm_x = 50.0;
    wm_y = 50.0;
    W = 1e-9;
    wm_dx2 = 0.0;
    wm_dxdy = 0.0;
    i = 0;
}