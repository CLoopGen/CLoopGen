#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *features;
float *ceps_0;

void init_vars() {
    size_t data_size = 1 << 20;
    features = (float*)aligned_alloc(32, data_size * sizeof(float));
    ceps_0 = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t i = 0; i < data_size; i++) {
        features[i] = (float)(i % 1000) / 10.0f;
        ceps_0[i] = 0.0f;
    }
}