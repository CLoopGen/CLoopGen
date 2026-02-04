#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

double *x;
size_t xstride;
double *y;
size_t ystride;
size_t n;
double m_x;
double m_y;
size_t i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1 million elements
    n = data_size;
    xstride = 1;
    ystride = 1;
    m_x = 0.0;
    m_y = 0.0;
    i = 0;

    // Allocate memory for x and y arrays
    x = (double*)aligned_alloc(32, n * xstride * sizeof(double));
    y = (double*)aligned_alloc(32, n * ystride * sizeof(double));

    // Initialize arrays with random but deterministic data
    srand(123);
    for (size_t idx = 0; idx < n * xstride; idx++) {
        x[idx] = (double)(rand() % 1000) / 10.0;
    }
    for (size_t idx = 0; idx < n * ystride; idx++) {
        y[idx] = (double)(rand() % 1000) / 10.0;
    }
}