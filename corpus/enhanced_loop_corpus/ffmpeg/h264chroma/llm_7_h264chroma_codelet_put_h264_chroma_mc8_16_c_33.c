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
    ptrdiff_t offset = 0;
    dst[0] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 1;
    dst[1] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 2;
    dst[2] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 3;
    dst[3] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 4;
    dst[4] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 5;
    dst[5] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 6;
    dst[6] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    offset = 7;
    dst[7] = ((((A * src[offset] + B * src[offset + 1] + C * src[stride + offset] + D * src[stride + offset + 1])) + 32) >> 6);
    dst += stride;
    src += stride;
}
}
