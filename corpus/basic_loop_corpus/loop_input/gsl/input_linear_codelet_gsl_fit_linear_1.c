#include <stdlib.h>
#include <stdint.h>

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
    n = 10000000;  // ~80 MB total data (10M * 8 bytes * 2 arrays), suitable for ~0.01 sec on modern CPU

    xstride = 1;
    ystride = 1;

    x = (double*)aligned_alloc(32, n * xstride * sizeof(double));
    y = (double*)aligned_alloc(32, n * ystride * sizeof(double));

    for (size_t idx = 0; idx < n * xstride; idx += xstride) {
        x[idx] = (double)(idx + 1) * 0.0001;
    }

    for (size_t idx = 0; idx < n * ystride; idx += ystride) {
        y[idx] = (double)(idx + 1) * 0.0002;
    }

    m_x = 500.0;
    m_y = 1000.0;
    m_dx2 = 0.0;
    m_dxdy = 0.0;
    i = 0;
}