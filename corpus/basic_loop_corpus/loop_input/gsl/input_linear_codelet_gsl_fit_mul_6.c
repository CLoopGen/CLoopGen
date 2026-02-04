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

void init_vars() {
    n = 67108864;  // ~512 MB of data (2 arrays of 67M doubles ≈ 1GB total), tuned for ~0.01 sec on modern CPU with compiler opts
    xstride = 1;
    ystride = 1;

    x = (double*)aligned_alloc(32, n * sizeof(double));
    y = (double*)aligned_alloc(32, n * sizeof(double));

    if (!x || !y) {
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        x[idx] = (double)(idx % 1000) / 100.0;
        y[idx] = (double)((idx + 500) % 1000) / 100.0;
    }

    m_x = 0.0;
    m_y = 0.0;
    i = 0;
}