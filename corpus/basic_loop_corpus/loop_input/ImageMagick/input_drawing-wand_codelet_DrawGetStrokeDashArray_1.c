#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

double *p;
double *q;
size_t n;
ssize_t i;

static double *alloc_p;
static double *alloc_q;

void init_vars() {
    n = 16777216; // 128 MB of doubles (16M elements * 8 bytes)

    alloc_p = (double*)aligned_alloc(32, n * sizeof(double));
    alloc_q = (double*)aligned_alloc(32, n * sizeof(double));

    if (!alloc_p || !alloc_q) {
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        alloc_p[idx] = (double)(idx & 511);
    }

    p = alloc_p;
    q = alloc_q;
}