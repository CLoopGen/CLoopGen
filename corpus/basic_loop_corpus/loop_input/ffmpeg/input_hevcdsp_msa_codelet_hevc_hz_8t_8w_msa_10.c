#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime on modern CPU
    // Aim for moderate memory footprint: use 4MB of source data as baseline
    const int total_elements = 1 << 20; // ~1M pixels
    const int block_height = 1024;      // height divisible by 4
    const int block_width = total_elements / block_height;

    if (block_width == 0) {
        return;
    }

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;

    // Allocate buffers with padding to prevent out-of-bounds access
    // Each iteration processes 4 rows, so ensure buffer is large enough
    size_t src_size = (size_t)(height + 4) * (size_t)src_stride;
    size_t dst_size = (size_t)(height + 4) * (size_t)dst_stride;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (int16_t*)calloc(dst_size, sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        free(src_buffer);
        free(dst_buffer);
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    loop_cnt = 0; // Will be set in loop()
}