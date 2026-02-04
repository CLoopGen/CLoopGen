#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int y;
uint8_t *dst;
uint8_t *src;
int init_y;
int height;
int save_upper_left;
int save_lower_left;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    init_y = 0;
    height = 32768;
    save_upper_left = 1;
    save_lower_left = 1;

    stride_src = 4096;
    stride_dst = 4096;

    dst = aligned_alloc(32, DATA_SIZE);
    src = aligned_alloc(32, DATA_SIZE);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        src[i * stride_src] = (uint8_t)(i & 0xFF);
    }
}