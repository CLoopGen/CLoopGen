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
    height = 16384;
    stride_dst = width + 64;
    stride_src = width + 32;
    init_y = 0;
    save_upper_right = 0;
    save_lower_right = 0;

    dst = (uint16_t*)aligned_alloc(64, (size_t)stride_dst * height * sizeof(uint16_t));
    src = (uint16_t*)aligned_alloc(64, (size_t)stride_src * height * sizeof(uint16_t));

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}