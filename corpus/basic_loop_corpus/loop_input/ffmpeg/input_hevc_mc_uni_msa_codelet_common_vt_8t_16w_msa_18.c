#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t total_data_size = 64 << 20; // 64 MB of source data
    const int block_height = 1024;
    const int block_width = 64;

    src_stride = block_width;
    dst_stride = block_width;
    height = block_height;

    size_t src_buffer_size = (size_t)block_height * (size_t)src_stride;
    size_t dst_buffer_size = (size_t)block_height * (size_t)dst_stride;

    src_buffer = aligned_alloc(32, src_buffer_size);
    dst_buffer = aligned_alloc(32, dst_buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_buffer_size; ++i) {
        src_buffer[i] = rand() & 0xFF;
    }
    memset(dst_buffer, 0, dst_buffer_size);

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}