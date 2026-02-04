#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)
#define STRIDE_ALIGN 32

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int C1 = 13;
int C2 = 3;
int h;
uint8_t *cm;
int i;

void init_vars() {
    const int width = 16;
    const int height = TOTAL_PIXELS / width;
    h = height;

    srcStride = width + 10; 
    dstStride = width;

    src = aligned_alloc(STRIDE_ALIGN, (size_t)srcStride * height * sizeof(uint8_t));
    dst = aligned_alloc(STRIDE_ALIGN, (size_t)dstStride * height * sizeof(uint8_t));
    cm = aligned_alloc(STRIDE_ALIGN, 256 * sizeof(uint8_t));

    for (int y = 0; y < height; y++) {
        uint8_t* src_row = &src[y * srcStride];
        for (int x = 0; x < width + 10; x++) {
            src_row[x] = rand() & 0xFF;
        }
    }

    for (int i = 0; i < 256; i++) {
        cm[i] = (uint8_t)i;
    }

    memset(dst, 0, (size_t)dstStride * height * sizeof(uint8_t));
}