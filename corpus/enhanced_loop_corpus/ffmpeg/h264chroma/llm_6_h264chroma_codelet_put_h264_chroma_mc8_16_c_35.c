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
    uint16_t temp[8];
    for (i = 0; i < h; i++) {
        temp[0] = (((A * src[0]) + 32) >> 6);
        temp[1] = (((A * src[1]) + 32) >> 6);
        temp[2] = (((A * src[2]) + 32) >> 6);
        temp[3] = (((A * src[3]) + 32) >> 6);
        temp[4] = (((A * src[4]) + 32) >> 6);
        temp[5] = (((A * src[5]) + 32) >> 6);
        temp[6] = (((A * src[6]) + 32) >> 6);
        temp[7] = (((A * src[7]) + 32) >> 6);
        dst[0] = temp[0];
        dst[1] = temp[1];
        dst[2] = temp[2];
        dst[3] = temp[3];
        dst[4] = temp[4];
        dst[5] = temp[5];
        dst[6] = temp[6];
        dst[7] = temp[7];
        dst += stride;
        src += stride;
    }
}
