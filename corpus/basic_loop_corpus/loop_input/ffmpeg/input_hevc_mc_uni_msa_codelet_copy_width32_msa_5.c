#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define TOTAL_ITERATIONS 10000000

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

void init_vars() {
    const int32_t block_height = 1024;
    const int32_t width = 1024;
    src_stride = width;
    dst_stride = width;
    height = block_height;

    size_t src_size = (size_t)(block_height + 4) * src_stride;
    size_t dst_size = (size_t)(block_height + 4) * dst_stride;

    src = (uint8_t*)aligned_alloc(64, src_size);
    dst = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src, 0x5A, src_size);
    memset(dst, 0, dst_size);
}

__attribute__((constructor)) void auto_init() {
    init_vars();
}