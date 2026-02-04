#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int linesize;
int16_t block[64];
int y;

void init_vars() {
    linesize = 128;
    int dst_size = linesize * 128;
    dst = (uint16_t*)aligned_alloc(32, dst_size * sizeof(uint16_t));
    for (int i = 0; i < dst_size; i++) {
        dst[i] = (uint16_t)(i % 512);
    }
    for (int i = 0; i < 64; i++) {
        block[i] = (int16_t)(i * 2 - 64);
    }
    y = 0;
}