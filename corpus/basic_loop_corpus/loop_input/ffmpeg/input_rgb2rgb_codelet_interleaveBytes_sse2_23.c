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

static uint8_t *src1_data;
static uint8_t *src2_data;
static uint8_t *dest_data;

void init_vars() {
    width = 1920;
    height = 1080;
    src1Stride = width;
    src2Stride = width;
    dstStride = width * 2;

    size_t src1_size = (size_t)src1Stride * height;
    size_t src2_size = (size_t)src2Stride * height;
    size_t dest_size = (size_t)dstStride * height;

    src1_data = aligned_alloc(16, src1_size);
    src2_data = aligned_alloc(16, src2_size);
    dest_data = aligned_alloc(16, dest_size);

    if (!src1_data || !src2_data || !dest_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src1_size; i++) {
        src1_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < src2_size; i++) {
        src2_data[i] = (uint8_t)((i + 33) & 0xFF);
    }
    for (size_t i = 0; i < dest_size; i++) {
        dest_data[i] = 0;
    }

    src1 = src1_data;
    src2 = src2_data;
    dest = dest_data;
}