#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

double * rlist;
size_t n;
size_t k;
double result_sum;

void init_vars() {
    n = 16777216; // ~16M elements, roughly 128MB of data (16M * 8 bytes), targets ~0.01 sec on modern CPU
    rlist = (double*)aligned_alloc(32, n * sizeof(double));
    if (!rlist) {
        exit(1);
    }
    for (size_t i = 0; i < n; i++) {
        rlist[i] = (double)(i & 511) - 255.0; // Small values to avoid overflow in sum
    }
    result_sum = 0.0;
    k = 0;
}