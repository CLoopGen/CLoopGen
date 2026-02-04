#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int x;
uint16_t *dst;
uint16_t *src;
int init_x;
int width;
int height;
int save_lower_right;
int save_lower_left;

void init_vars() {
    width = 8192;
    height = 4096;
    stride_dst = width;
    stride_src = width;
    init_x = 0;
    save_lower_right = 0;
    save_lower_left = 0;

    size_t total_elements = (size_t)height * width;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    dst = aligned_alloc(32, total_bytes);
    src = aligned_alloc(32, total_bytes);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
        dst[i] = 0;
    }
}