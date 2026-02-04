#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint8_t *src;

void init_vars() {
    h = 1000;
    pad = 10;
    srcStride = 16;
    tmpStride = 8;

    src = (uint8_t*)aligned_alloc(32, (h + 5) * srcStride * sizeof(uint8_t));
    tmp = (int16_t*)aligned_alloc(32, (h + 5) * tmpStride * sizeof(int16_t));

    for (int idx = 0; idx < (h + 5) * srcStride; idx++) {
        src[idx] = (uint8_t)(idx % 256);
    }

    for (int idx = 0; idx < (h + 5) * tmpStride; idx++) {
        tmp[idx] = 0;
    }
}