#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int lag;
int i;
int16_t *vector_ptr;

static int16_t *out_buffer;
static int16_t *vector_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128 MB of int16_t data (64M elements)
    lag = 64 * 1024 * 1024; // Set lag to buffer length

    out_buffer = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    vector_buffer = (int16_t*)aligned_alloc(32, (data_size + lag) * sizeof(int16_t));

    if (!out_buffer || !vector_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        out_buffer[idx] = 0;
    }
    for (size_t idx = 0; idx < data_size + lag; idx++) {
        vector_buffer[idx] = (int16_t)(idx % 32767);
    }

    out = out_buffer;
    vector_ptr = vector_buffer + lag; // Adjust so that vector_ptr[i - lag] starts at valid base
}