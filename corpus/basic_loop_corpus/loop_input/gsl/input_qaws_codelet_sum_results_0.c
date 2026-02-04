#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double * rlist;
size_t n;
size_t k;
double result_sum;

void init_vars() {
    n = 16777216; // Approximately 128 MB of data (16M * 8 bytes per double)
    rlist = (double *)aligned_alloc(32, n * sizeof(double));
    if (!rlist) {
        exit(1);
    }
    for (size_t i = 0; i < n; i++) {
        rlist[i] = (double)(i % 1000) + 0.5;
    }
    k = 0;
    result_sum = 0.0;
}