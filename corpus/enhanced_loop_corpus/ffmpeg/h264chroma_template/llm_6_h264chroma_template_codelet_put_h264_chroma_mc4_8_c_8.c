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
    uint8_t temp[4];
    for (i = 0; i < h; i++) {
        temp[0] = (((A * src[0]) + 32) >> 6);
        temp[1] = (((A * src[1]) + 32) >> 6);
        temp[2] = (((A * src[2]) + 32) >> 6);
        temp[3] = (((A * src[3]) + 32) >> 6);
        dst[0] = temp[0];
        dst[1] = temp[1];
        dst[2] = temp[2];
        dst[3] = temp[3];
        dst += stride;
        src += stride;
    }
}
