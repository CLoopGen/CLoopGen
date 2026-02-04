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
    init_y = 0;
    save_upper_right = 1;
    save_lower_right = 1;

    stride_src = width;
    stride_dst = width;

    dst = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * height * stride_dst);
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * height * stride_src);

    for (int i = 0; i < height * stride_src; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }

    for (int i = 0; i < height * stride_dst; i++) {
        dst[i] = 0;
    }
}