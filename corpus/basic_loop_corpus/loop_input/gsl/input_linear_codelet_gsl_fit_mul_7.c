#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

double *x;
size_t xstride;
double *y;
size_t ystride;
size_t n;
double m_x;
double m_y;
double m_dx2;
double m_dxdy;
size_t i;

void init_vars() {
    n = 10000000;  // ~80 MB of data (10M * 8 bytes * 2 arrays), adjust for ~0.01 sec runtime
    xstride = 1;
    ystride = 1;

    x = aligned_alloc(32, n * xstride * sizeof(double));
    y = aligned_alloc(32, n * ystride * sizeof(double));

    if (!x || !y) {
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        x[idx * xstride] = (double)(idx % 1000) / 100.0;
        y[idx * ystride] = (double)((idx + 500) % 1000) / 100.0;
    }

    m_x = 5.0;
    m_y = 5.0;
    m_dx2 = 0.0;
    m_dxdy = 0.0;
    i = 0;
}