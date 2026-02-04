#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int32_t loop_cnt;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;
static size_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime

void init_vars() {
    stride = 64; // typical cache line aligned step

    internal_src_buffer = (uint8_t*)aligned_alloc(64, total_size);
    internal_dst_buffer = (uint8_t*)aligned_alloc(64, total_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        exit(EXIT_FAILURE);
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;

    // Ensure initial pointers are within bounds for all loop iterations
    // Loop runs 4 times, each time adding 4*stride to src and dst
    // Final offset: 4 * (4 * stride) = 16 * stride = 16 * 64 = 1024 bytes
    // So we only need to ensure at least 1024 bytes of valid memory
    // Our 64MB buffer is more than sufficient
}