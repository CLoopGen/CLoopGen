#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
uint8_t *src2;
uint8_t *src3;
uint8_t *dst;
int srcStride1;
int srcStride2;
int srcStride3;
int dstStride;
int x;
int y;
int w;
int h;

void init_vars() {
    h = 1024;
    w = 1024;
    srcStride1 = w * 4;
    srcStride2 = w;
    srcStride3 = w;
    dstStride = w * 8;

    size_t src1_size = srcStride1 * h;
    size_t src2_size = srcStride2 * ((h + 3) / 4);
    size_t src3_size = srcStride3 * ((h + 3) / 4);
    size_t dst_size = dstStride * h;

    src1 = (uint8_t*)malloc(src1_size);
    src2 = (uint8_t*)malloc(src2_size);
    src3 = (uint8_t*)malloc(src3_size);
    dst = (uint8_t*)malloc(dst_size);

    for (size_t i = 0; i < src1_size; i++) src1[i] = rand() % 256;
    for (size_t i = 0; i < src2_size; i++) src2[i] = rand() % 256;
    for (size_t i = 0; i < src3_size; i++) src3[i] = rand() % 256;
}