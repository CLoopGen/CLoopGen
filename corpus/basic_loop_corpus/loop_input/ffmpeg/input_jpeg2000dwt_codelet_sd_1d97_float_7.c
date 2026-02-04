#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    p = (float*)aligned_alloc(32, data_size * sizeof(float));
    if (!p) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        p[idx] = (float)(idx % 1000) * 0.001f;
    }

    i0 = 2;     // ensures 2*i - 1 >= 1 when i starts at i0>>1 = 1
    i1 = (int)(data_size - 2); // ensures 2*i + 1 < data_size when i < (i1>>1)
}