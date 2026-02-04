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
    ptrdiff_t s = stride;
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0];
        uint8_t temp1 = src[1];
        uint8_t temp2 = src[2];
        uint8_t tempS0 = src[s + 0];
        uint8_t tempS1 = src[s + 1];
        uint8_t tempS2 = src[s + 2];

        dst[0] = (((A * temp0 + B * temp1 + C * tempS0 + D * tempS1) + 32) >> 6);
        dst[1] = (((A * temp1 + B * temp2 + C * tempS1 + D * tempS2) + 32) >> 6);

        dst += s;
        src += s;
    }
}
