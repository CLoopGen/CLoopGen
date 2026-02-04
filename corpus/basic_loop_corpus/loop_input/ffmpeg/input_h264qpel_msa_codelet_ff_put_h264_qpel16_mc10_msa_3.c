#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    stride = 64; // Typical cache line aligned step

    src_buffer = (uint8_t *)aligned_alloc(64, total_data_size);
    dst_buffer = (uint8_t *)aligned_alloc(64, total_data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    // Ensure initial src and dst are within bounds for all iterations
    // Each iteration adds (4 * stride) to dst and (4 * stride) to src (via four increments)
    // Loop runs 4 times -> total advance: 16 * stride
    // So we need at least 16 * stride accessible data per iteration? But loop_cnt is fixed to 4.
    // Total src/dst advance over 4 iterations: 4 * (4 * stride) = 16 * stride
    size_t min_required = 16 * stride;
    if (total_data_size < min_required) {
        exit(1);
    }

    // Initialize buffers to avoid undefined behavior if accessed
    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}