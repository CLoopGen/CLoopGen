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
    const int total_elements = 64 * 1024 * 1024; // ~64 million bytes for input (adjustable)
    const int block_height = 1024;
    const int block_width = 64;

    height = block_height;
    src_stride = block_width;
    dst_stride = block_width;

    src_buffer = aligned_alloc(32, (size_t)height * (size_t)src_stride * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, (size_t)height * (size_t)dst_stride * sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < height * src_stride; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (int i = 0; i < height * dst_stride; i++) {
        dst_buffer[i] = (int16_t)(i & 0x7FF);
    }

    src = src_buffer;
    dst = dst_buffer;
}