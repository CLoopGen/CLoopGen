#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint16_t *dst;
extern int32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    dst[0] += (unsigned int)src[0] + (unsigned int)src[8] + (unsigned int)src[16];
    dst[1] += (unsigned int)src[1] + (unsigned int)src[9] + (unsigned int)src[17];
    dst[2] += (unsigned int)src[2] + (unsigned int)src[10] + (unsigned int)src[18];
    dst[3] += (unsigned int)src[3] + (unsigned int)src[11] + (unsigned int)src[19];
    dst[4] += (unsigned int)src[4] + (unsigned int)src[12] + (unsigned int)src[20];
    dst[5] += (unsigned int)src[5] + (unsigned int)src[13] + (unsigned int)src[21];
    dst[6] += (unsigned int)src[6] + (unsigned int)src[14] + (unsigned int)src[22];
    dst[7] += (unsigned int)src[7] + (unsigned int)src[15] + (unsigned int)src[23];
    dst += stride;
    src += 24;
}
}
