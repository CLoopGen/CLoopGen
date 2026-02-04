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
    uint8_t temp0, temp1;
    for (i = 0; i < h; i++) {
        temp0 = src[0];
        temp1 = src[1];
        dst[0] = ((((A * temp0 + B * temp1 + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6);
        dst[1] = ((((A * temp1 + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
