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
    uint8_t temp;
    for (i = 0; i < h; i++) {
        temp = src[0];
        dst[0] = ((((A * temp + B * src[1] + C * src[stride] + D * src[stride + 1])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
