#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double * rlist;
size_t n;
size_t k;
double result_sum;

void init_vars() {
    n = 16777216; // ~134 MB of data (16M * sizeof(double) ≈ 134MB), tuned for ~0.01 sec on modern CPUs
    rlist = (double*)aligned_alloc(32, n * sizeof(double));
    if (!rlist) {
        exit(1);
    }
    for (size_t i = 0; i < n; i++) {
        rlist[i] = (double)(i % 1000) + 1.0;
    }
    result_sum = 0.0;
}