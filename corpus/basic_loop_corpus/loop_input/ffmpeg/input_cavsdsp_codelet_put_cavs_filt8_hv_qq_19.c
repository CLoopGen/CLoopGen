#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h = 10000;
int i;

static uint8_t src1_buffer[256 * 1024 * 1024 + 12]; // large buffer to allow for offset access and strides
static int16_t tmp_buffer[256 * 1024 * 1024 / 8 * 8]; // roughly matching size

void init_vars() {
    // Initialize srcStride to a reasonable value (e.g., width of a row)
    srcStride = 64;

    // Set src1 to point inside the buffer with padding for negative indices and offsets up to +10
    src1 = src1_buffer + 10; // allows src1[-2] to src1[...] safely

    // Initialize tmp to start of tmp_buffer
    tmp = tmp_buffer;

    // Ensure h is set so that we don't exceed buffer bounds
    // Each iteration advances src1 by srcStride and tmp by 8
    // Maximum src1 index used: src1[10] => offset 10 from base pointer
    // We need at least (h+5) iterations, so ensure (h+5)*srcStride + 10 <= buffer_size
    ptrdiff_t max_iterations = (256 * 1024 * 1024 - 10) / srcStride;
    h = (max_iterations > 5) ? max_iterations - 5 : 0;

    // Initialize src1 base data (skip first 10 elements due to offset)
    for (size_t i = 0; i < 256 * 1024 * 1024; ++i) {
        src1_buffer[i] = (uint8_t)(i % 256);
    }

    // Zero-initialize tmp buffer
    memset(tmp_buffer, 0, sizeof(tmp_buffer));
}