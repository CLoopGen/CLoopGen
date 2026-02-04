#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int order;
float *out;
float *out2;
int i;
float buffer1[37];
float buffer2[37];

void init_vars() {
    const size_t data_size = 37;
    order = data_size - 1;

    out = (float*)aligned_alloc(32, data_size * sizeof(float));
    out2 = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; ++idx) {
        out[idx] = 1.0f;
        out2[idx] = 2.0f;
        buffer1[idx] = 0.1f;
        buffer2[idx] = 0.2f;
    }
}