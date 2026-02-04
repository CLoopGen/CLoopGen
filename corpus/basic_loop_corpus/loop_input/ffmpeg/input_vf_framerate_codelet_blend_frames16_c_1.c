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
uint16_t *dstw;
uint16_t *src1w;
uint16_t *src2w;

void init_vars() {
    width = 1920;
    height = 1080;
    src1_linesize = width;
    src2_linesize = width;
    dst_linesize = width;
    factor1 = 128;
    factor2 = 128;
    half = 1 << 15;

    size_t src1_size = width * height * sizeof(uint16_t);
    size_t src2_size = width * height * sizeof(uint16_t);
    size_t dst_size = width * height * sizeof(uint16_t);

    src1w = aligned_alloc(32, src1_size);
    src2w = aligned_alloc(32, src2_size);
    dstw = aligned_alloc(32, dst_size);

    for (size_t i = 0; i < width * height; i++) {
        src1w[i] = rand() & 0xFFFF;
        src2w[i] = rand() & 0xFFFF;
        dstw[i] = 0;
    }
}