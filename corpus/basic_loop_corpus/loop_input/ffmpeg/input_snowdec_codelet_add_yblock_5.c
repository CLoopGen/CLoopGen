#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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

static size_t total_data_size = 64 * 1024 * 1024;

void init_vars() {
    b_w = 256;
    b_h = 256;
    dst_stride = 256;
    src_stride = 256;
    obmc_stride = 512;
    add = 1;

    dst = aligned_alloc(32, sizeof(IDWTELEM) * dst_stride * b_h);
    dst8 = aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    obmc = aligned_alloc(32, sizeof(uint8_t) * obmc_stride * ((obmc_stride >> 1) + 1));

    block[0] = aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    block[1] = aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    block[2] = aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);
    block[3] = aligned_alloc(32, sizeof(uint8_t) * src_stride * b_h);

    for (int i = 0; i < dst_stride * b_h; i++) {
        dst[i] = rand() % 256;
    }
    for (int i = 0; i < src_stride * b_h; i++) {
        dst8[i] = 0;
        block[0][i] = rand() % 256;
        block[1][i] = rand() % 256;
        block[2][i] = rand() % 256;
        block[3][i] = rand() % 256;
    }
    for (int i = 0; i < obmc_stride * ((obmc_stride >> 1) + 1); i++) {
        obmc[i] = rand() % 256;
    }
}