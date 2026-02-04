#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int srcStride;
int dstStride[3];
int srcSliceH;
int inc_size;
int width;
uint8_t *dest[3];
int x;
int h;

static uint8_t *src_buffer;
static uint8_t *dest_buffer0;
static uint8_t *dest_buffer1;
static uint8_t *dest_buffer2;

void init_vars() {
    width = 1920;
    srcSliceH = 1080;
    inc_size = 3;
    srcStride = width * inc_size + 64;
    dstStride[0] = width + 32;
    dstStride[1] = width + 16;
    dstStride[2] = width + 16;

    size_t src_size = (size_t)(srcSliceH * srcStride);
    size_t dest0_size = (size_t)(srcSliceH * dstStride[0]);
    size_t dest1_size = (size_t)(srcSliceH * dstStride[1]);
    size_t dest2_size = (size_t)(srcSliceH * dstStride[2]);

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dest_buffer0 = (uint8_t*)aligned_alloc(32, dest0_size);
    dest_buffer1 = (uint8_t*)aligned_alloc(32, dest1_size);
    dest_buffer2 = (uint8_t*)aligned_alloc(32, dest2_size);

    if (!src_buffer || !dest_buffer0 || !dest_buffer1 || !dest_buffer2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dest[0] = dest_buffer0;
    dest[1] = dest_buffer1;
    dest[2] = dest_buffer2;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dest0_size; i++) {
        dest_buffer0[i] = 0;
    }
    for (size_t i = 0; i < dest1_size; i++) {
        dest_buffer1[i] = 0;
    }
    for (size_t i = 0; i < dest2_size; i++) {
        dest_buffer2[i] = 0;
    }
}