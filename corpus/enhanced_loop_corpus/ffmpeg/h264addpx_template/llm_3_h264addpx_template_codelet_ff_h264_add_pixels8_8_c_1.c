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
    dst[0 * stride] += (unsigned int)src[0];
    dst[1 * stride] += (unsigned int)src[1];
    dst[2 * stride] += (unsigned int)src[2];
    dst[3 * stride] += (unsigned int)src[3];
    dst[4 * stride] += (unsigned int)src[4];
    dst[5 * stride] += (unsigned int)src[5];
    dst[6 * stride] += (unsigned int)src[6];
    dst[7 * stride] += (unsigned int)src[7];
    dst += 8 * stride;
    src += 8;
}
}
