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
        uint8_t temp0 = ((A * src[0] + B * src[1] + C * src[s + 0] + D * src[s + 1]) + 32) >> 6;
        uint8_t temp1 = ((A * src[1] + B * src[2] + C * src[s + 1] + D * src[s + 2]) + 32) >> 6;
        dst[0] = ((dst[0] + temp0 + 1) >> 1);
        dst[1] = ((dst[1] + temp1 + 1) >> 1);
        dst += s;
        src += s;
    }
}
