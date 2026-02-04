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
        int idx = i & 7;
        if (idx < 4) {
            dst[idx] += (unsigned int)src[idx];
        } else {
            dst[idx] += (unsigned int)src[idx];
            dst[idx - 4] += (unsigned int)src[idx - 4];
        }
        dst += stride;
        src += 8;
    }
}
