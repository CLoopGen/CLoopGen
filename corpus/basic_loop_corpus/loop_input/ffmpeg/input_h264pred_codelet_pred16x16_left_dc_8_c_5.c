#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

static uint8_t *src_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    if (!src_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    stride = 4096;
    i = 0;
    dc = 0;
    src = src_buffer + 1; // Adjust so that src[-1] is valid (points to first element)
}