#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp0, temp1, temp2, temp3;
    for (i = 0; i < h; i++) {
        temp0 = src[0];
        temp1 = src[1];
        temp2 = src[2];
        temp3 = src[3];
        dst[0] = (((A * temp0) + 32) >> 6);
        dst[1] = (((A * temp1) + 32) >> 6);
        dst[2] = (((A * temp2) + 32) >> 6);
        dst[3] = (((A * temp3) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
