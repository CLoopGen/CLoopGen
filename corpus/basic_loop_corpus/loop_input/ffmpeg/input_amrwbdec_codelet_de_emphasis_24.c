#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in;
float m;
int i;

void init_vars() {
    const size_t data_size = 64; // Since loop runs from 1 to 63, we need at least 64 elements
    in = (float*)aligned_alloc(32, data_size * sizeof(float));
    out = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; idx++) {
        in[idx] = (float)(idx % 100);
        out[idx] = (float)((idx + 1) % 75);
    }

    m = 1.5f;
    i = 0;
}