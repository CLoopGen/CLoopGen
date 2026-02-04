#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t d_offset = i * stride;
    ptrdiff_t s_offset = i * stride;
    uint8_t temp[4];
    temp[0] = src[s_offset + 0];
    temp[1] = src[s_offset + 1];
    temp[2] = src[s_offset + stride + 0];
    temp[3] = src[s_offset + stride + 1];

    dst[d_offset + 0] = (((dst[d_offset + 0]) + ((((A * temp[0] + B * temp[1] + C * temp[2] + D * temp[3])) + 32) >> 6) + 1) >> 1);
    dst[d_offset + 1] = (((dst[d_offset + 1]) + ((((A * temp[1] + B * src[s_offset + 2] + C * temp[3] + D * src[s_offset + stride + 2])) + 32) >> 6) + 1) >> 1);
}
}
