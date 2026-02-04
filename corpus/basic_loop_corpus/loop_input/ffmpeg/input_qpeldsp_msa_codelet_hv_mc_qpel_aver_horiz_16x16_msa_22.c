#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t loop_count;

static uint8_t *internal_src;
static uint8_t *internal_dst;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;

    size_t src_size = (size_t)block_height * src_stride;
    size_t dst_size = (size_t)block_height * dst_stride;

    internal_src = (uint8_t*)aligned_alloc(64, src_size);
    internal_dst = (uint8_t*)aligned_alloc(64, dst_size);

    if (!internal_src || !internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; ++i) {
        internal_src[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; ++i) {
        internal_dst[i] = rand() & 0xFF;
    }

    src = internal_src;
    dst = internal_dst;
}