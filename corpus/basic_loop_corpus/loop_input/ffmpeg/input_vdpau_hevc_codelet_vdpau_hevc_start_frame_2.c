#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

static size_t array_size = 16777216; // 16M elements, ~64MB for double

double *a;
double *b;
double *c;
const size_t N = 16;

void init_vars() {
    a = (double*)aligned_alloc(32, array_size * sizeof(double));
    b = (double*)aligned_alloc(32, array_size * sizeof(double));
    c = (double*)aligned_alloc(32, array_size * sizeof(double));

    if (!a || !b || !c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < array_size; i++) {
        a[i] = (double)(i % 1000) / 10.0;
        b[i] = (double)((i + 50) % 1000) / 10.0;
        c[i] = 0.0;
    }
}