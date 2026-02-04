#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t src1_linesize;
ptrdiff_t src2_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
int factor1;
int factor2;
int half;
int line;
int pixel;
uint8_t *dstw;
uint8_t *src1w;
uint8_t *src2w;

static uint8_t *src1_buffer;
static uint8_t *src2_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    src1_linesize = width;
    src2_linesize = width;
    dst_linesize = width;
    factor1 = 128;
    factor2 = 64;
    half = 1 << (8 - 2);

    size_t buffer_size = width * height;

    src1_buffer = aligned_alloc(32, buffer_size);
    src2_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);

    for (size_t i = 0; i < buffer_size; i++) {
        src1_buffer[i] = rand() % 256;
        src2_buffer[i] = rand() % 256;
    }

    src1w = src1_buffer;
    src2w = src2_buffer;
    dstw = dst_buffer;
}