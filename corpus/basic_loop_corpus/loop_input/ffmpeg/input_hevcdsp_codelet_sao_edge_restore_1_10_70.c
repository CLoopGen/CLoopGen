#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst = 1024;
ptrdiff_t stride_src = 1024;
int y;
uint16_t *dst;
uint16_t *src;
int init_y = 0;
int height = 65536;
int save_upper_left = 1;
int save_lower_left = 1;

void init_vars() {
    dst = aligned_alloc(32, height * stride_dst * sizeof(uint16_t));
    src = aligned_alloc(32, height * stride_src * sizeof(uint16_t));

    for (int i = 0; i < height * stride_dst; i++) {
        dst[i] = 0;
    }
    for (int i = 0; i < height * stride_src; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
}