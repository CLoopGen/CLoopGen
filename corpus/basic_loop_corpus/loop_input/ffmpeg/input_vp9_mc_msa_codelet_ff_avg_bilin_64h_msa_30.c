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
static size_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = 1024;
    dst_stride = 1024;
    height = total_size / src_stride;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}