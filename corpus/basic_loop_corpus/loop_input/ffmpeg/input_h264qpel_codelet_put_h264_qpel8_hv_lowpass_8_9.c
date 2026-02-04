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
    tmpStride = 16;
    srcStride = 16;

    size_t src_size = (h + 5) * srcStride + 12;
    size_t tmp_size = (h + 5) * tmpStride;

    src = (uint8_t*)aligned_alloc(32, src_size);
    tmp = (int16_t*)aligned_alloc(32, tmp_size * sizeof(int16_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = (uint8_t)(idx % 251);
    }
    for (size_t idx = 0; idx < tmp_size; idx++) {
        tmp[idx] = 0;
    }
}