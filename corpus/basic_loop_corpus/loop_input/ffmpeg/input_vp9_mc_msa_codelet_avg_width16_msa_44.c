#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define TOTAL_ITERATIONS 1000000

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

void init_vars() {
    const int width = 64;
    height = 8 * (TOTAL_ITERATIONS / 1000); // Scale to control runtime
    
    size_t src_size = height * src_stride + 8 * width;
    size_t dst_size = height * dst_stride + 8 * width;

    src_stride = width;
    dst_stride = width;

    src_size = (size_t)(height + 8) * src_stride;
    dst_size = (size_t)(height + 8) * dst_stride;

    src = aligned_alloc(32, src_size);
    dst = aligned_alloc(32, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src, 0x5A, src_size);
    memset(dst, 0, dst_size);
}