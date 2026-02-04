#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

    s1 = aligned_alloc(32, (size_t)h * linesize1);
    s2 = aligned_alloc(32, (size_t)h * linesize2);
    dst = aligned_alloc(32, (size_t)h * dst_linesize_32 * sizeof(uint32_t));
    dst_top = aligned_alloc(32, (size_t)h * dst_linesize_32 * sizeof(uint32_t));

    for (int i = 0; i < h * linesize1; i++) {
        s1[i] = rand() % 256;
        s2[i] = rand() % 256;
    }

    for (int i = 0; i < h * dst_linesize_32; i++) {
        dst[i] = rand() % 1000;
        dst_top[i] = rand() % 1000;
    }
}