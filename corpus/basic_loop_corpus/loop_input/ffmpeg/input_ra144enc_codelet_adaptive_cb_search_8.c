#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *work;
float *data;
int i;
float best_gain;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime on modern CPU
    work = (float*)aligned_alloc(32, data_size);
    data = (float*)aligned_alloc(32, data_size);

    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        work[idx] = (float)(idx % 1000) / 100.0f;
        data[idx] = (float)(idx % 500) / 50.0f;
    }

    best_gain = 0.75f;
    i = 0;
}