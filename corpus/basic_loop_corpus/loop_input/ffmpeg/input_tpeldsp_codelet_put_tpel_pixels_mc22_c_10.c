#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

void init_vars() {
    width = 8192;
    height = (DATA_SIZE_MB * 1024 * 1024) / width;
    while (height * width < DATA_SIZE_MB * 1024 * 1024) {
        height++;
    }
    stride = width + 1;
    size_t src_size = (height + 1) * (size_t)(stride + 1);
    size_t dst_size = height * (size_t)stride;

    uint8_t *src_base = aligned_alloc(32, src_size * sizeof(uint8_t));
    uint8_t *dst_base = aligned_alloc(32, dst_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src_base[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_base[idx] = 0;
    }

    src = src_base;
    dst = dst_base;
}