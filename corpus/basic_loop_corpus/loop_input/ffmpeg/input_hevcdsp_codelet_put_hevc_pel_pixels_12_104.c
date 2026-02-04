#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x;
int y;

uint16_t *src;
int16_t *dst;
ptrdiff_t srcstride = 512;

void init_vars() {
    size_t src_size = (size_t)height * (size_t)width * sizeof(uint16_t);
    size_t dst_size = (size_t)height * 64 * sizeof(int16_t);

    uint16_t *src_data = aligned_alloc(32, src_size);
    int16_t *dst_data = aligned_alloc(32, dst_size);

    if (!src_data || !dst_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size / sizeof(uint16_t); i++) {
        src_data[i] = (uint16_t)(i % 16384);
    }

    for (size_t i = 0; i < dst_size / sizeof(int16_t); i++) {
        dst_data[i] = 0;
    }

    src = src_data;
    dst = dst_data;
}