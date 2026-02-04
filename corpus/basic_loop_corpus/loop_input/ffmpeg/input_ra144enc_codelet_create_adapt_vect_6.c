#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *vect;
int16_t *cb;
int lag;
int i;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // ~128MB of total data
    size_t num_elements = data_size / sizeof(int16_t);
    if (num_elements > INT32_MAX) num_elements = INT32_MAX;

    cb = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));
    vect = (float*)aligned_alloc(32, num_elements * sizeof(float));

    for (size_t idx = 0; idx < num_elements; idx++) {
        cb[idx] = (int16_t)(idx % 32768);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        vect[idx] = 0.0f;
    }

    lag = (int)((40 > num_elements ? 40 : num_elements));
}