#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const float ff_pow_0_5[16] = {
    1.0f, 0.70710678118f, 0.5f, 0.35355339059f,
    0.25f, 0.1767766953f, 0.125f, 0.08838834765f,
    0.0625f, 0.04419417382f, 0.03125f, 0.02209708691f,
    0.015625f, 0.01104854345f, 0.0078125f, 0.00552427173f
};

float *iir_mem;
float *filt_mem[2];

int i;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; // ~64MB per array to ensure loop runtime ~0.01s

    iir_mem = (float *)aligned_alloc(32, data_size * sizeof(float));
    filt_mem[0] = (float *)aligned_alloc(32, data_size * sizeof(float));
    filt_mem[1] = (float *)aligned_alloc(32, data_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; idx++) {
        iir_mem[idx] = (float)(idx % 1000) / 100.0f;
        filt_mem[0][idx] = 0.0f;
        filt_mem[1][idx] = 0.0f;
    }

    i = 0;
}