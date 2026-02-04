#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint8_t *dst;
extern int16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[4];
    for (i = 0; i < 4; i++) {
        temp[0] = (unsigned int)src[0];
        temp[1] = (unsigned int)src[1];
        temp[2] = (unsigned int)src[2];
        temp[3] = (unsigned int)src[3];
        dst[0] += temp[0];
        dst[1] += temp[1];
        dst[2] += temp[2];
        dst[3] += temp[3];
        dst += stride;
        src += 4;
    }
}
