#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int16_t))
#define TMP_OFFSET 10
#define HEIGHT 8

void init_vars() {
    const int width = TOTAL_ELEMENTS / (TMP_OFFSET + 8);
    w = width;

    dstStride = HEIGHT * sizeof(uint8_t);

    cm = aligned_alloc(64, 1024 * sizeof(uint8_t));
    for (int i = 0; i < 1024; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    tmp = aligned_alloc(64, (TOTAL_ELEMENTS + TMP_OFFSET + 8) * sizeof(int16_t));
    for (int i = 0; i < TOTAL_ELEMENTS + TMP_OFFSET + 8; i++) {
        tmp[i] = (int16_t)(i % 512 - 256);
    }

    dst = aligned_alloc(64, w * sizeof(uint8_t) * HEIGHT);
    for (int i = 0; i < w * HEIGHT; i++) {
        dst[i] = (uint8_t)(i & 0xFF);
    }

    i = 0;
}