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
        uint8_t sum0 = (uint8_t)((unsigned int)dst[0] + (unsigned int)src[0]);
        uint8_t sum1 = (uint8_t)((unsigned int)dst[1] + (unsigned int)src[1]);
        uint8_t sum2 = (uint8_t)((unsigned int)dst[2] + (unsigned int)src[2]);
        uint8_t sum3 = (uint8_t)((unsigned int)dst[3] + (unsigned int)src[3]);
        uint8_t sum4 = (uint8_t)((unsigned int)dst[4] + (unsigned int)src[4]);
        uint8_t sum5 = (uint8_t)((unsigned int)dst[5] + (unsigned int)src[5]);
        uint8_t sum6 = (uint8_t)((unsigned int)dst[6] + (unsigned int)src[6]);
        uint8_t sum7 = (uint8_t)((unsigned int)dst[7] + (unsigned int)src[7]);

        dst[7] = sum7;
        dst[6] = sum6;
        dst[5] = sum5;
        dst[4] = sum4;
        dst[3] = sum3;
        dst[2] = sum2;
        dst[1] = sum1;
        dst[0] = sum0;

        dst += stride;
        src += 8;
    }
}
