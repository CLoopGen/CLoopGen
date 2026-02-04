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
int32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t block_width = 1024;
    const int32_t total_size = block_height * block_width;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height & ~3;

    src_buffer = (uint8_t*)aligned_alloc(64, total_size * sizeof(uint8_t));
    dst_buffer = (uint8_t*)aligned_alloc(64, total_size * sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < total_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((destructor))
void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}