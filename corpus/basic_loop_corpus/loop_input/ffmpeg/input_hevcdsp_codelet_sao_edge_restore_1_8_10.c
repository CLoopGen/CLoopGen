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
    save_upper_left = 1;
    save_lower_left = 1;
    height = (DATA_SIZE / 256) + save_upper_left + save_lower_left; // Ensure enough rows
    stride_dst = 256;
    stride_src = 256;

    dst = aligned_alloc(32, (height + 1) * (size_t)stride_dst);
    src = aligned_alloc(32, (height + 1) * (size_t)stride_src);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < (height + 1); i++) {
        src[i * stride_src] = (uint8_t)(i & 0xFF);
    }
}