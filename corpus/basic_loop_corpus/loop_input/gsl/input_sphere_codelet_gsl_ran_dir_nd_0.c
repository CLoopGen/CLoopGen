#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t n;
double *x;
double d;
size_t i;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double array
    d = 3.14159;
    x = (double*)aligned_alloc(32, n * sizeof(double));
    if (!x) {
        exit(1);
    }
    for (size_t idx = 0; idx < n; ++idx) {
        x[idx] = (double)(idx + 1);
    }
}