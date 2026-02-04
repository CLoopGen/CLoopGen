#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;
static int allocated_height;
static ptrdiff_t allocated_stride;

void init_vars() {
    allocated_height = 1 << 14; // 16384 rows
    allocated_stride = 1 << 10;  // 1024 bytes per row
    total_size = (size_t)allocated_height * allocated_stride;

    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    src_stride = allocated_stride;
    dst_stride = allocated_stride;
    height = allocated_height;
}