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

    size_t buf_size = w * h * sizeof(IDWTELEM);
    size_t dst_size = w * h * sizeof(uint8_t);

    buf = aligned_alloc(32, buf_size);
    dst8 = aligned_alloc(32, dst_size);

    for (int i = 0; i < w * h; i++) {
        buf[i] = (IDWTELEM)(rand() % 512 - 256);
    }
    for (int i = 0; i < w * h; i++) {
        dst8[i] = 0;
    }
}