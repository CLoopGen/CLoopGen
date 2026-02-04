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
uint16_t *src;

void init_vars() {
    h = 1000;
    pad = 10;
    srcStride = 20;
    tmpStride = 16;

    size_t src_size = (h + 5) * srcStride * sizeof(uint16_t);
    size_t tmp_size = (h + 5) * tmpStride * sizeof(int16_t);

    src = aligned_alloc(32, src_size);
    tmp = aligned_alloc(32, tmp_size);

    for (int i = 0; i < (h + 5) * srcStride; i++) {
        src[i] = (uint16_t)(i % 1024);
    }
    for (int i = 0; i < (h + 5) * tmpStride; i++) {
        tmp[i] = (int16_t)(i % 512);
    }
}