#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *tmp;
uint8_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    h = 1000;
    pad = 10;
    srcStride = 16;
    tmpStride = 16;

    size_t src_size = (h + 5) * srcStride;
    size_t tmp_size = (h + 5) * tmpStride;

    src = aligned_alloc(32, src_size * sizeof(uint8_t));
    tmp = aligned_alloc(32, tmp_size * sizeof(int16_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = (uint8_t)(idx % 251);
    }

    for (size_t idx = 0; idx < tmp_size; idx++) {
        tmp[idx] = 0;
    }
}