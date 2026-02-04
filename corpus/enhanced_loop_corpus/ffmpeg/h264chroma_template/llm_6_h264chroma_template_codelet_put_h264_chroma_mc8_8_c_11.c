#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t temp0 = (((A * src[0]) + 32) >> 6);
        uint8_t temp1 = (((A * src[1]) + 32) >> 6);
        uint8_t temp2 = (((A * src[2]) + 32) >> 6);
        uint8_t temp3 = (((A * src[3]) + 32) >> 6);
        uint8_t temp4 = (((A * src[4]) + 32) >> 6);
        uint8_t temp5 = (((A * src[5]) + 32) >> 6);
        uint8_t temp6 = (((A * src[6]) + 32) >> 6);
        uint8_t temp7 = (((A * src[7]) + 32) >> 6);

        dst[0] = temp0;
        dst[1] = temp1;
        dst[2] = temp2;
        dst[3] = temp3;
        dst[4] = temp4;
        dst[5] = temp5;
        dst[6] = temp6;
        dst[7] = temp7;

        dst += stride;
        src += stride;
    }
}
