#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int total_elements = 64 * 1024 * 1024; // ~64MB for substantial work
    const int block_height = 12;
    const int block_width = 8;

    src_stride = block_width + 16; // Add padding to prevent overlap
    dst_stride = block_width + 16;

    height = (total_elements / (block_width * block_height)) * block_height;
    if (height == 0) height = block_height;

    size_t src_size = (size_t)(height + 8) * src_stride; // Extra margin
    size_t dst_size = (size_t)(height + 8) * dst_stride;

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

    cnt = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}