#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int x;
uint8_t *dst;
uint8_t *src;
int init_x;
int width;
int height;
int save_lower_right;
int save_lower_left;

void init_vars() {
    width = 16384;
    height = 16384;
    stride_dst = width + 64;
    stride_src = width + 64;
    init_x = 0;
    save_lower_left = 0;
    save_lower_right = 0;

    dst = (uint8_t*)aligned_alloc(64, (size_t)height * (size_t)stride_dst);
    src = (uint8_t*)aligned_alloc(64, (size_t)height * (size_t)stride_src);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * stride_src + j] = rand() % 256;
        }
    }
}