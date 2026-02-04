#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint16_t *dst;
uint16_t *src;
int init_x = 0;
int width;
int save_upper_left = 0;
int save_upper_right = 0;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128 MB of data (64M elements * 2 bytes each)
    width = data_size / sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(32, data_size);
    dst = (uint16_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < width; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
}