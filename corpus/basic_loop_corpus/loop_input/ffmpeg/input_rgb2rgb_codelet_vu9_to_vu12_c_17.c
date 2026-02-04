#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src2;
uint8_t *dst2;
int srcStride2;
int dstStride2;
int x;
int y;
int w;
int h;

void init_vars() {
    h = 4096;
    w = 4096;
    srcStride2 = w;
    dstStride2 = 2 * w;

    src2 = (uint8_t *)aligned_alloc(32, (size_t)srcStride2 * h);
    dst2 = (uint8_t *)aligned_alloc(32, (size_t)dstStride2 * h);

    for (int i = 0; i < srcStride2 * h; i++) {
        src2[i] = rand() % 256;
    }
    for (int i = 0; i < dstStride2 * h; i++) {
        dst2[i] = 0;
    }
}