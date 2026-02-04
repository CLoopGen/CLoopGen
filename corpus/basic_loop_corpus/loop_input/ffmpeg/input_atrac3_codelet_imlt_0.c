#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *input;
int i;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime
    input = (float*)aligned_alloc(32, data_size);
    if (!input) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(float); ++idx) {
        input[idx] = (float)(idx % 1000) + 1.0f;
    }
}