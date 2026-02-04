#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *h;
size_t nc;
size_t i;
double x;
size_t n;

void init_vars() {
    x = 3.14;
    n = 16384;
    nc = n;
    size_t total_elements = n * nc;
    h = (double*)aligned_alloc(32, total_elements * sizeof(double));
    for (size_t idx = 0; idx < total_elements; ++idx) {
        h[idx] = (double)(idx + 1);
    }
}