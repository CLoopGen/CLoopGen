#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride;
int i;
uint8_t *dst;
int16_t *src;

static uint8_t *dst_buffer;
static int16_t *src_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    const size_t num_elements = data_size / sizeof(int16_t);
    const size_t num_iterations = (num_elements + 7) / 8;

    stride = 8;

    dst_buffer = aligned_alloc(32, num_iterations * stride * sizeof(uint8_t));
    src_buffer = aligned_alloc(32, num_elements * sizeof(int16_t));

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_iterations * stride; idx++) {
        dst_buffer[idx] = (uint8_t)(idx % 255);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        src_buffer[idx] = (int16_t)(idx % 32767);
    }

    dst = dst_buffer;
    src = src_buffer;
}