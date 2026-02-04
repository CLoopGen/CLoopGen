#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t base_src = i * stride;
    dst[0] = ((((A * src[base_src + 0] + B * src[base_src + 1] + C * src[base_src + stride + 0] + D * src[base_src + stride + 1])) + 32) >> 6);
    dst[1] = ((((A * src[base_src + 1] + B * src[base_src + 2] + C * src[base_src + stride + 1] + D * src[base_src + stride + 2])) + 32) >> 6);
    dst[2] = ((((A * src[base_src + 2] + B * src[base_src + 3] + C * src[base_src + stride + 2] + D * src[base_src + stride + 3])) + 32) >> 6);
    dst[3] = ((((A * src[base_src + 3] + B * src[base_src + 4] + C * src[base_src + stride + 3] + D * src[base_src + stride + 4])) + 32) >> 6);
    dst[4] = ((((A * src[base_src + 4] + B * src[base_src + 5] + C * src[base_src + stride + 4] + D * src[base_src + stride + 5])) + 32) >> 6);
    dst[5] = ((((A * src[base_src + 5] + B * src[base_src + 6] + C * src[base_src + stride + 5] + D * src[base_src + stride + 6])) + 32) >> 6);
    dst[6] = ((((A * src[base_src + 6] + B * src[base_src + 7] + C * src[base_src + stride + 6] + D * src[base_src + stride + 7])) + 32) >> 6);
    dst[7] = ((((A * src[base_src + 7] + B * src[base_src + 8] + C * src[base_src + stride + 7] + D * src[base_src + stride + 8])) + 32) >> 6);
    dst += stride;
    src += stride;
}
}
