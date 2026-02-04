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
    for (i = 0; i < 4; ++i) {
        unsigned int val0 = (unsigned int)src[0];
        unsigned int val1 = (unsigned int)src[1];
        unsigned int val2 = (unsigned int)src[2];
        unsigned int val3 = (unsigned int)src[3];

        if (val0 | val1 | val2 | val3) {
            dst[0] += val0;
            dst[1] += val1;
            dst[2] += val2;
            dst[3] += val3;
        }
        dst += stride;
        src += 4;
    }
}
