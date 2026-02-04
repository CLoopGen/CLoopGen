#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
uint8_t *src2;
uint8_t *dest;
int width;
int height;
int src1Stride;
int src2Stride;
int dstStride;
int h;

static uint8_t *src1_buffer;
static uint8_t *src2_buffer;
static uint8_t *dest_buffer;

void init_vars() {
    width = 2048;
    height = 512;
    src1Stride = width;
    src2Stride = width;
    dstStride = 2 * width;

    size_t src1_size = (size_t)src1Stride * height;
    size_t src2_size = (size_t)src2Stride * height;
    size_t dest_size = (size_t)dstStride * height;

    src1_buffer = (uint8_t*)aligned_alloc(32, src1_size);
    src2_buffer = (uint8_t*)aligned_alloc(32, src2_size);
    dest_buffer = (uint8_t*)aligned_alloc(32, dest_size);

    src1 = src1_buffer;
    src2 = src2_buffer;
    dest = dest_buffer;

    for (size_t i = 0; i < src1_size; i++) {
        src1_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src2_size; i++) {
        src2_buffer[i] = (uint8_t)((i * 3) & 0xFF);
    }
    for (size_t i = 0; i < dest_size; i++) {
        dest_buffer[i] = 0;
    }
}