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
    save_lower_left = 0;
    save_lower_right = 0;

    size_t total_size = (size_t)width * height * sizeof(uint16_t);

    dst = aligned_alloc(64, total_size);
    src = aligned_alloc(64, total_size);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < width * height; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
        dst[i] = 0;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}