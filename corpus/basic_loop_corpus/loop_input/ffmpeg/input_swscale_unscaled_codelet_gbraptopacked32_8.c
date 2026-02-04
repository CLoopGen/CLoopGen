#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define SRC_SLICE_H 256
#define WIDTH 1024
#define DATA_SIZE (WIDTH * SRC_SLICE_H)

uint8_t *src[4];
int srcStride[4];
uint8_t *dst;
int dstStride;
int srcSliceH;
int alpha_first;
int width;
int x;
int h;
int i;

void init_vars() {
    srcSliceH = SRC_SLICE_H;
    width = WIDTH;
    alpha_first = rand() % 2; 
    dstStride = width * 4;

    for (int i = 0; i < 4; i++) {
        src[i] = (uint8_t*)aligned_alloc(32, DATA_SIZE * sizeof(uint8_t));
        if (!src[i]) abort();
        for (int j = 0; j < DATA_SIZE; j++) {
            src[i][j] = rand() % 256;
        }
        srcStride[i] = width;
    }

    dst = (uint8_t*)aligned_alloc(32, (size_t)dstStride * srcSliceH);
    if (!dst) abort();
    memset(dst, 0, (size_t)dstStride * srcSliceH);
}