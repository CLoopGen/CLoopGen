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
for (int outer = 0; outer < 2; outer++) {
    for (int inner = 0; inner < 2; inner++) {
        int idx = inner * 2;
        dst[0] += (unsigned int)src[idx + 0];
        dst[1] += (unsigned int)src[idx + 1];
        dst[2] += (unsigned int)src[idx + 2];
        dst[3] += (unsigned int)src[idx + 3];
        dst += stride;
        src += 4;
    }
}
}
