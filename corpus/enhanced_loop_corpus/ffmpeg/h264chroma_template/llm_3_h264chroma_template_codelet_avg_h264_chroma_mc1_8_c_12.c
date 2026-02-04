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
    uint8_t temp[4] = {
        src[base_src],
        src[base_src + 1],
        src[base_src + stride],
        src[base_src + stride + 1]
    };
    dst[base_dst] = (((dst[base_dst]) + ((((A * temp[0] + B * temp[1] + C * temp[2] + D * temp[3])) + 32) >> 6) + 1) >> 1);
}
}
