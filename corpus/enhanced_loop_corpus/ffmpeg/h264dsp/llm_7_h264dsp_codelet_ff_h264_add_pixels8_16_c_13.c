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
    for (i = 0; i < 8; i++) {
        uint32_t accum = 0;
        accum += (unsigned int)src[0]; dst[0] += (uint16_t)accum;
        accum += (unsigned int)src[1]; dst[1] += (uint16_t)accum;
        accum += (unsigned int)src[2]; dst[2] += (uint16_t)accum;
        accum += (unsigned int)src[3]; dst[3] += (uint16_t)accum;
        accum += (unsigned int)src[4]; dst[4] += (uint16_t)accum;
        accum += (unsigned int)src[5]; dst[5] += (uint16_t)accum;
        accum += (unsigned int)src[6]; dst[6] += (uint16_t)accum;
        accum += (unsigned int)src[7]; dst[7] += (uint16_t)accum;
        dst += stride;
        src += 8;
    }
}
