#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int16_t))

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

void init_vars() {
    const int stride = 8;
    const int tmp_offset = 10 * 8;
    
    w = (TOTAL_ELEMENTS - tmp_offset) / 8;
    if (w <= 0) w = 1000;

    dstStride = stride * sizeof(uint8_t);

    cm = aligned_alloc(32, 1024 * sizeof(uint8_t));
    dst = aligned_alloc(32, w * sizeof(uint8_t) + dstStride * 8);
    tmp = aligned_alloc(32, (w + tmp_offset + 8) * sizeof(int16_t));

    for (int i = 0; i < 1024; i++) {
        cm[i] = (uint8_t)((i * 17 + 23) % 256);
    }

    for (int i = 0; i < w + tmp_offset + 8; i++) {
        tmp[i] = (int16_t)((i * 31) % 512 - 256);
    }

    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < w; k++) {
            dst[k * sizeof(uint8_t) + j * dstStride] = (uint8_t)(k % 256);
        }
    }

    i = 0;
}

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;