#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    dst[base_dst + 0] = (((dst[base_dst + 0]) + (((A * src[base_src + 0] + B * src[base_src + 1] + C * src[base_src + stride + 0] + D * src[base_src + stride + 1] + bias)) >> 6) + 1) >> 1);
    dst[base_dst + 1] = (((dst[base_dst + 1]) + (((A * src[base_src + 1] + B * src[base_src + 2] + C * src[base_src + stride + 1] + D * src[base_src + stride + 2] + bias)) >> 6) + 1) >> 1);
    dst[base_dst + 2] = (((dst[base_dst + 2]) + (((A * src[base_src + 2] + B * src[base_src + 3] + C * src[base_src + stride + 2] + D * src[base_src + stride + 3] + bias)) >> 6) + 1) >> 1);
    dst[base_dst + 3] = (((dst[base_dst + 3]) + (((A * src[base_src + 3] + B * src[base_src + 4] + C * src[base_src + stride + 3] + D * src[base_src + stride + 4] + bias)) >> 6) + 1) >> 1);
}
}
