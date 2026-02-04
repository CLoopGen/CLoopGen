#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
uint8_t *dst1;
int srcStride1;
int dstStride1;
int x;
int y;
int w;
int h;

void init_vars() {
    h = 4096;
    w = 32768;
    srcStride1 = w;
    dstStride1 = 2 * w;

    src1 = (uint8_t*)aligned_alloc(32, (size_t)h / 2 * srcStride1);
    dst1 = (uint8_t*)aligned_alloc(32, h * (size_t)dstStride1);

    for (int i = 0; i < h / 2 * srcStride1; i++) {
        src1[i] = rand() % 256;
    }
    for (int i = 0; i < h * dstStride1; i++) {
        dst1[i] = 0;
    }

    x = 0;
    y = 0;
}