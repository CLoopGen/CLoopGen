#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t dither[8][8] __attribute__((aligned(8))) = {
    {  0, 32,  8, 40,  2, 34, 10, 42 },
    { 48, 16, 56, 24, 50, 18, 58, 26 },
    { 12, 44,  4, 36, 14, 46,  6, 38 },
    { 60, 28, 52, 20, 62, 30, 54, 22 },
    {  3, 35, 11, 43,  1, 33,  9, 41 },
    { 51, 19, 59, 27, 49, 17, 57, 25 },
    { 15, 47,  7, 39, 13, 45,  5, 37 },
    { 63, 31, 55, 23, 61, 29, 53, 21 }
};

uint8_t *dst;
uint16_t *src;
int dst_stride;
int src_stride;
int width;
int height;
int log2_scale;
int y;
int x;

void init_vars() {
    width = 1920;
    height = 1080;
    log2_scale = 2;

    src_stride = width;
    dst_stride = width;

    src = aligned_alloc(32, sizeof(uint16_t) * src_stride * height);
    dst = aligned_alloc(32, sizeof(uint8_t) * dst_stride * height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            src[i * src_stride + j] = (rand() % 256) << log2_scale;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            dst[i * dst_stride + j] = 0;
        }
    }
}