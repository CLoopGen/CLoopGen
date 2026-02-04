#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst1;
uint8_t *dst2;
int width;
int height;
int srcStride;
int dst1Stride;
int dst2Stride;
int h;

static uint8_t *src_buf;
static uint8_t *dst1_buf;
static uint8_t *dst2_buf;

void init_vars() {
    width = 1920;
    height = 1080;
    srcStride = 1920 * 2;
    dst1Stride = 1920;
    dst2Stride = 1920;

    size_t src_size = (size_t)srcStride * height;
    size_t dst_size = (size_t)dst1Stride * height;

    src_buf = aligned_alloc(32, src_size);
    dst1_buf = aligned_alloc(32, dst_size);
    dst2_buf = aligned_alloc(32, dst_size);

    src = src_buf;
    dst1 = dst1_buf;
    dst2 = dst2_buf;

    for (size_t i = 0; i < src_size; i++) {
        src_buf[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst1_buf[i] = 0;
        dst2_buf[i] = 0;
    }
}