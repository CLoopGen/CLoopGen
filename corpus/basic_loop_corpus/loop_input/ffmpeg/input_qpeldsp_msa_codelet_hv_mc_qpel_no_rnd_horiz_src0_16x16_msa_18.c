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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int total_elements = 64 * 1024 * 1024;
    const int block_height = 16384;
    const int block_width = 4;

    src_buffer = aligned_alloc(32, total_elements * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, total_elements * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < total_elements; ++i) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;
}