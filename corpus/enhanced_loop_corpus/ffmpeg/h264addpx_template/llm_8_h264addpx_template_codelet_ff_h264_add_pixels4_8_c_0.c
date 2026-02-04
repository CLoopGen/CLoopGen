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
for (i = 0; i < 8; i++) {
    dst[0] += (unsigned int)src[0];
    dst[1] += (unsigned int)src[1];
    dst[2] += (unsigned int)src[2];
    dst[3] += (unsigned int)src[3];
    dst[4] += (unsigned int)src[4];
    dst[5] += (unsigned int)src[5];
    dst[6] += (unsigned int)src[6];
    dst[7] += (unsigned int)src[7];
    dst += stride;
    src += 8;
}
}
