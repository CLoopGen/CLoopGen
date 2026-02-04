#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;
uint32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    src_stride = 4096; // Large enough to allow indexing within page-like boundaries
    dst_stride = 4096;
    height = 16384; // Number of outer loop iterations

    posix_memalign((void**)&src_buffer, 32, data_size);
    posix_memalign((void**)&dst_buffer, 32, data_size);

    src = src_buffer;
    dst = dst_buffer;

    // Initialize memory to avoid undefined behavior
    for (size_t i = 0; i < data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }
}