#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src[3];
int srcStride[3];
uint8_t *dst;
int dstStride;
int srcSliceH;
int width;
int x;
int h;
int i;

static uint8_t **src_data_ptrs;
static int total_src_height;
static size_t dst_size;

void init_vars() {
    width = 1920;
    srcSliceH = 1080;
    dstStride = width * 3;
    total_src_height = srcSliceH + 10;
    dst_size = dstStride * srcSliceH;

    dst = (uint8_t*)calloc(dst_size, sizeof(uint8_t));
    if (!dst) exit(1);

    src_data_ptrs = (uint8_t**)calloc(3, sizeof(uint8_t*));
    if (!src_data_ptrs) exit(1);

    for (int idx = 0; idx < 3; idx++) {
        srcStride[idx] = width;
        src_data_ptrs[idx] = (uint8_t*)calloc(total_src_height, srcStride[idx]);
        if (!src_data_ptrs[idx]) exit(1);
        for (int row = 0; row < total_src_height; row++) {
            for (int col = 0; col < width; col++) {
                src_data_ptrs[idx][row * srcStride[idx] + col] = rand() & 0xFF;
            }
        }
        src[idx] = src_data_ptrs[idx];
    }
}