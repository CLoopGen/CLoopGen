#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int64_t total_data_size = 64 * (1 << 20); // 64 MB for ~0.01 sec runtime estimate
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    
    src_stride = block_width;
    dst_stride = block_width;
    height = block_height & ~0x3; // Ensure divisible by 4 for >>2 and loop safety

    size_t src_size = (size_t)src_stride * height;
    size_t dst_size = (size_t)dst_stride * height;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    cnt = 0;
}