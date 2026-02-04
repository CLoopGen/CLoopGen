#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *dst;
ptrdiff_t dst_linesize_32;
uint8_t *s1;
ptrdiff_t linesize1;
uint8_t *s2;
ptrdiff_t linesize2;
int w;
int h;
int x;
int y;
uint32_t *dst_top;

void init_vars() {
    w = 1024;
    h = 512;
    linesize1 = w;
    linesize2 = w;
    dst_linesize_32 = w;

    s1 = (uint8_t*)aligned_alloc(32, (size_t)h * linesize1);
    s2 = (uint8_t*)aligned_alloc(32, (size_t)h * linesize2);
    dst = (uint32_t*)aligned_alloc(32, (size_t)h * dst_linesize_32 * sizeof(uint32_t));
    dst_top = (uint32_t*)aligned_alloc(32, (size_t)h * dst_linesize_32 * sizeof(uint32_t));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            s1[i * linesize1 + j] = rand() % 256;
            s2[i * linesize2 + j] = rand() % 256;
            dst[i * dst_linesize_32 + j] = 0;
            dst_top[i * dst_linesize_32 + j] = rand() % 1000;
        }
    }
}