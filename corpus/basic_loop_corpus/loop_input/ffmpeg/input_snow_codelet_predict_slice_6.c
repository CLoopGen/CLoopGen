#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *buf;
int mb_y;
int x;
int y;
int block_h;
int ref_stride;
uint8_t *dst8;
int w;
int h;

void init_vars() {
    w = 1920;
    h = 1080;
    block_h = 16;
    mb_y = 0;
    ref_stride = 1920;

    buf = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * w * h);
    dst8 = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * ref_stride * h);

    for (int i = 0; i < w * h; i++) {
        buf[i] = (short)((i * 73) % 512 - 256);
    }

    for (int i = 0; i < ref_stride * h; i++) {
        dst8[i] = 0;
    }
}