#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst[4];
extern ptrdiff_t dst_stride;
extern int planes;
extern  int stride[4];
extern int width;
extern int height;
extern int i;
extern int j;
extern int k;
extern  uint8_t *sg;
extern  uint8_t *sb;
extern  uint8_t *sr;
extern  uint8_t *sa;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use strided memory access via pointer arithmetic with step in outer dimension
    uint8_t **dst_ptrs = dst;
    ptrdiff_t dstride = dst_stride;
    int w = width;
    int h = height;
    int p = planes;
    ptrdiff_t s0 = stride[0], s1 = stride[1], s2 = stride[2];

    for (j = 0; j < h; j++) {
        uint8_t *sg_j = sg + j * s0;
        uint8_t *sb_j = sb + j * s1;
        uint8_t *sr_j = sr + j * s2;
        uint8_t *sa_j = (p == 4) ? sa + j * stride[3] : NULL;
        uint8_t *d0 = dst_ptrs[0] + j * dstride;
        uint8_t *d1 = dst_ptrs[1] + j * dstride;
        uint8_t *d2 = dst_ptrs[2] + j * dstride;
        uint8_t *d3 = (p == 4) ? dst_ptrs[3] + j * dstride : NULL;

        for (i = 0; i < w; i++) {
            g = sg_j[i];
            d0[i] = g;
            g += 128;
            d1[i] = sb_j[i] - g;
            d2[i] = sr_j[i] - g;
            if (p != 3) {
                d3[i] = sa_j[i];
            }
        }
    }

    // Update global k, sg, sb, sr, sa to maintain state consistency as in original
    k = height * dst_stride;
    sg += height * stride[0];
    sb += height * stride[1];
    sr += height * stride[2];
    if (planes != 3) sa += height * stride[3];
}
