#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x, y;

uint16_t *src;
int16_t *dst;
int8_t *filter;
ptrdiff_t srcstride = 512;

void init_vars() {
    size_t src_size = (height + 2) * srcstride * sizeof(uint16_t);
    size_t dst_size = ((height * width + 63) / 64 + 1) * 64 * sizeof(int16_t);
    
    src = aligned_alloc(64, src_size);
    dst = aligned_alloc(64, dst_size);
    filter = aligned_alloc(64, 4 * sizeof(int8_t));

    for (int i = 0; i < (height + 2) * srcstride; i++) {
        src[i] = rand() & 0xFFFF;
    }
    for (int i = 0; i < 4; i++) {
        filter[i] = rand() % 17 - 8;
    }
}