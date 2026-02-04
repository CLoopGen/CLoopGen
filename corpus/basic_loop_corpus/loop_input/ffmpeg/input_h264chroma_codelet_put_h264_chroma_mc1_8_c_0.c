#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A = 1;
int B = 1;
int C = 1;
int D = 1;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for significant runtime (~0.01 sec target)
    const size_t buffer_size = total_data_size + 2 * sizeof(uint8_t) + 2 * stride;

    stride = 1024;
    h = total_data_size / stride;

    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer + 1;
    dst = dst_buffer + 1;

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        src_buffer[idx] = rand() % 256;
        dst_buffer[idx] = 0;
    }
}