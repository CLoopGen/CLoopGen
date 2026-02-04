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
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    uint8_t s0 = src[base_src + 0];
    uint8_t s1 = src[base_src + 1];
    uint8_t s2 = src[base_src + 2];
    uint8_t s3 = src[base_src + stride + 0];
    uint8_t s4 = src[base_src + stride + 1];
    uint8_t s5 = src[base_src + stride + 2];

    dst[base_dst + 0] = (((A * s0 + B * s1 + C * s3 + D * s4) + 32) >> 6);
    dst[base_dst + 1] = (((A * s1 + B * s2 + C * s4 + D * s5) + 32) >> 6);
}
}
