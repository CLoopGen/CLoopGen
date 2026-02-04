#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int16_t *dst;
extern int32_t width8mult;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width8mult; cnt--;) {
        dst[0] = (int16_t)src[0];
        dst[1] = (int16_t)src[1];
        dst[2] = (int16_t)src[2];
        dst[3] = (int16_t)src[3];
        dst[4] = (int16_t)src[4];
        dst[5] = (int16_t)src[5];
        dst[6] = (int16_t)src[6];
        dst[7] = (int16_t)src[7];
        src += 8;
        dst += 8;
    }
}
