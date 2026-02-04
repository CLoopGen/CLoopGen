#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *dst;
uint8_t *dst8;
uint8_t *obmc;
int b_w;
int b_h;
int dst_stride;
int src_stride;
int obmc_stride;
int add;
uint8_t *block[4];
int x;
int y;

void init_vars() {
    b_w = 256;
    b_h = 256;
    dst_stride = 256;
    src_stride = 256;
    obmc_stride = 512;
    add = 1;

    dst = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * dst_stride * b_h);
    dst8 = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    obmc = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * obmc_stride * obmc_stride);

    for (int i = 0; i < 4; i++) {
        block[i] = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    }

    for (int i = 0; i < dst_stride * b_h; i++) {
        dst[i] = rand() % 256;
    }

    for (int i = 0; i < src_stride * b_h; i++) {
        dst8[i] = 0;
    }

    for (int i = 0; i < obmc_stride * obmc_stride; i++) {
        obmc[i] = rand() % 256;
    }

    for (int b = 0; b < 4; b++) {
        for (int i = 0; i < src_stride * b_h; i++) {
            block[b][i] = rand() % 256;
        }
    }
}