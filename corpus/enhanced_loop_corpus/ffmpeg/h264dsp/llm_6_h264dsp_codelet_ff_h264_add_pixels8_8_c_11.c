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
    uint8_t temp[8];
    for (i = 0; i < 8; i++) {
        temp[0] = (uint8_t)(src[0]);
        temp[1] = (uint8_t)(src[1]);
        temp[2] = (uint8_t)(src[2]);
        temp[3] = (uint8_t)(src[3]);
        temp[4] = (uint8_t)(src[4]);
        temp[5] = (uint8_t)(src[5]);
        temp[6] = (uint8_t)(src[6]);
        temp[7] = (uint8_t)(src[7]);

        dst[0] += temp[0];
        dst[1] += temp[1];
        dst[2] += temp[2];
        dst[3] += temp[3];
        dst[4] += temp[4];
        dst[5] += temp[5];
        dst[6] += temp[6];
        dst[7] += temp[7];

        dst += stride;
        src += 8;
    }
}
