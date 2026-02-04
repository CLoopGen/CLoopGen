#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;

void init_vars() {
    // Aim for ~64MB of data processed per loop iteration: 8 rows * stride bytes per column
    // We choose a height of 8000 -> 1000 iterations (since cnt = height / 8)
    // Let's use a stride close to 8000 bytes to get roughly 8000*8000 = 64MB total
    height = 8000;
    src_stride = 8192;
    dst_stride = 8192;
    total_size = (size_t)height * src_stride;

    // Allocate buffers with padding to prevent overflow
    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize buffers
    memset(src_buffer, 0x5A, total_size);
    memset(dst_buffer, 0, total_size);

    // Set the external pointers
    src = src_buffer;
    dst = dst_buffer;

    // Initialize cnt (will be overwritten in loop, but set correctly for safety)
    cnt = height / 8;
}