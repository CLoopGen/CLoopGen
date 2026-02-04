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
    init_x = 0;
    save_lower_left = 0;
    save_lower_right = 0;

    stride_src = width;
    stride_dst = width;

    size_t total_elements = (size_t)height * width;
    size_t total_bytes = total_elements * sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(64, total_bytes);
    dst = (uint16_t*)aligned_alloc(64, total_bytes);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
        dst[i] = 0;
    }
}