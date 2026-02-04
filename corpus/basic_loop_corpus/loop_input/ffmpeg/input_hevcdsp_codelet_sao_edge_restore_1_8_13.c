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
    width = 16000;
    height = 10000;
    stride_dst = width + 16;
    stride_src = width + 32;
    init_x = 0;
    save_lower_right = 1;
    save_lower_left = 1;

    dst = (uint8_t *)aligned_alloc(32, (size_t)height * (size_t)stride_dst);
    src = (uint8_t *)aligned_alloc(32, (size_t)height * (size_t)stride_src);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}