#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *rj;
double *rh;
size_t i;

void init_vars() {
    const size_t data_size = 134217728; // 128MB of doubles (each double is 8 bytes)

    rj = (double*)aligned_alloc(32, data_size * sizeof(double));
    rh = (double*)aligned_alloc(32, data_size * sizeof(double));

    for (size_t idx = 0; idx < data_size; ++idx) {
        rj[idx] = (double)(idx % 1000) + 1.0;
        rh[idx] = (double)(idx % 1000) + 2.0;
    }
}