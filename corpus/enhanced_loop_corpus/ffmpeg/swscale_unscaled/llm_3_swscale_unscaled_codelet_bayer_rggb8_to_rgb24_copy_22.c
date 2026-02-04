#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 2) {
    uint8_t s01 = src[(0) * src_stride + 1];
    uint8_t s10 = src[(1) * src_stride + 0];
    uint8_t s11 = src[(1) * src_stride + 1];
    uint8_t s00 = src[(0) * src_stride + 0];

    uint8_t avg_01_10 = ((unsigned int)s01 + (unsigned int)s10) >> 1;

    uint8_t *d0 = &dst[(0) * dst_stride];
    uint8_t *d1 = &dst[(1) * dst_stride];

    d0[2] = d0[5] = d1[5] = d1[2] = s11;
    d0[4] = s01;
    d0[1] = d1[4] = avg_01_10;
    d1[1] = s10;
    d1[0] = d0[0] = d0[3] = d1[3] = s00;

    src += 2;
    dst += 6;
}
}
