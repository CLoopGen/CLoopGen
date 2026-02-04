#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *data;
size_t N;
size_t i;

void init_vars() {
    N = 134217728; // 128MB of data (134217728 doubles = 134217728 * 8 bytes)
    data = (double*)aligned_alloc(32, N * sizeof(double));
    if (!data) {
        exit(1);
    }
    for (size_t idx = 0; idx < N; idx++) {
        data[idx] = (double)(idx & 0xFF);
    }
}