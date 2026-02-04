#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t total_size = 64 << 20; // 64 MB of input data to ensure ~0.01 sec runtime
    src_stride = 4096;
    dst_stride = 4096;
    height = (total_size / 2) / src_stride;

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
}