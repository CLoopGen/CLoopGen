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
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            int offset = j * 4;
            dst[0 + offset] += (unsigned int)src[0 + offset];
            dst[1 + offset] += (unsigned int)src[1 + offset];
            dst[2 + offset] += (unsigned int)src[2 + offset];
            dst[3 + offset] += (unsigned int)src[3 + offset];
        }
        dst += stride;
        src += 8;
    }
}
