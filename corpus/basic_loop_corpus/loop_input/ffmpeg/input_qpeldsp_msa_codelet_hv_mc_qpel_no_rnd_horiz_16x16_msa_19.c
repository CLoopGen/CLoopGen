#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint8_t loop_count;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // 64 MB for substantial runtime (~0.01 sec)
    const int block_height = 1024;
    const int block_width = 16 * 1024;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;

    size_t src_size = (size_t)src_stride * (size_t)height;
    size_t dst_size = (size_t)dst_stride * (size_t)height;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0x5A, src_size);
    memset(dst_buffer, 0, dst_size);

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}