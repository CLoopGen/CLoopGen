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
    ptrdiff_t s = stride;
    for (i = 0; i < h; i++) {
        uint16_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3], temp4 = src[4];
        uint16_t next0 = src[s + 0], next1 = src[s + 1], next2 = src[s + 2], next3 = src[s + 3], next4 = src[s + 4];

        dst[0] = (((A * temp0 + B * temp1 + C * next0 + D * next1) + 32) >> 6);
        dst[1] = (((A * temp1 + B * temp2 + C * next1 + D * next2) + 32) >> 6);
        dst[2] = (((A * temp2 + B * temp3 + C * next2 + D * next3) + 32) >> 6);
        dst[3] = (((A * temp3 + B * temp4 + C * next3 + D * next4) + 32) >> 6);

        dst += s;
        src += s;
    }
}
