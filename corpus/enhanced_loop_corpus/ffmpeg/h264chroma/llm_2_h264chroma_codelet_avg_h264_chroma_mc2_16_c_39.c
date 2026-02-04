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
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        dst[offset] = (((dst[offset]) + ((((A * src[offset] + B * src[offset + 1] + C * src[offset + stride] + D * src[offset + stride + 1])) + 32) >> 6) + 1) >> 1);
        dst[offset + 1] = (((dst[offset + 1]) + ((((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2])) + 32) >> 6) + 1) >> 1);
        offset += stride;
    }
}
