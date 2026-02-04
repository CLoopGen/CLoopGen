#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst = 512;
ptrdiff_t stride_src = 512;
int y;
uint16_t *dst;
uint16_t *src;
int init_y = 0;
int height = 1024;
int save_upper_left = 1;
int save_lower_left = 1;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    dst = aligned_alloc(64, total_size);
    src = aligned_alloc(64, total_size);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size / sizeof(uint16_t); i++) {
        src[i] = rand() % 65536;
        dst[i] = 0;
    }
}