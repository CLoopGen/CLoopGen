#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *work;
float *data;
int i;
float gain;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    work = (float*)aligned_alloc(32, data_size * sizeof(float));
    data = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; idx++) {
        work[idx] = (float)(idx % 1000) + 1.0f;
        data[idx] = (float)(idx % 1000) + 2.0f;
    }

    i = 0;
    gain = 0.5f;
}