#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    pad = 10;
    h = 10000;

    srcStride = 8;
    tmpStride = 4;

    size_t src_size = (h + 5) * srcStride * sizeof(uint16_t);
    size_t tmp_size = (h + 5) * tmpStride * sizeof(int32_t);

    src = aligned_alloc(32, src_size);
    tmp = aligned_alloc(32, tmp_size);

    for (int j = 0; j < (h + 5) * srcStride; j++) {
        src[j] = (uint16_t)(j % 1024);
    }

    for (int j = 0; j < (h + 5) * tmpStride; j++) {
        tmp[j] = 0;
    }
}