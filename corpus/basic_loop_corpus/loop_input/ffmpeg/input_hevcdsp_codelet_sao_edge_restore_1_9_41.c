#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int y;
uint16_t *dst;
uint16_t *src;
int init_y;
int width;
int height;
int save_upper_right;
int save_lower_right;

void init_vars() {
    width = 2048;
    height = 1024;
    stride_dst = width + 16;
    stride_src = width + 16;
    init_y = 0;
    save_upper_right = 0;
    save_lower_right = 0;

    size_t dst_size = (size_t)height * (size_t)stride_dst;
    size_t src_size = (size_t)height * (size_t)stride_src;

    dst = aligned_alloc(32, dst_size * sizeof(uint16_t));
    src = aligned_alloc(32, src_size * sizeof(uint16_t));

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst[i] = 0;
    }
}