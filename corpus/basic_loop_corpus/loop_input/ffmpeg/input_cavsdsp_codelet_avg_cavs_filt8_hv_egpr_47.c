#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t))
#define TMP_OFFSET 10
#define STRIDE 8

void init_vars() {
    dstStride = STRIDE;
    srcStride = STRIDE;
    w = (TOTAL_ELEMENTS > 100) ? 100 : TOTAL_ELEMENTS / 2;

    cm = aligned_alloc(32, 512 * sizeof(uint8_t));
    dst = aligned_alloc(32, w * dstStride * sizeof(uint8_t));
    src2 = aligned_alloc(32, w * srcStride * sizeof(uint8_t));
    tmp = aligned_alloc(32, (w + TMP_OFFSET + 8) * 8 * sizeof(int16_t));

    for (int i = 0; i < 512; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < w * dstStride; i++) {
        dst[i] = rand() % 256;
    }

    for (int i = 0; i < w * srcStride; i++) {
        src2[i] = rand() % 256;
    }

    for (int i = 0; i < (w + TMP_OFFSET + 8) * 8; i++) {
        tmp[i] = rand() % 256 - 128;
    }
}