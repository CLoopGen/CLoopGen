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
    dst[0] += (unsigned int)src[i];
    dst[1] += (unsigned int)src[i + 4];
    dst[2] += (unsigned int)src[i + 8];
    dst[3] += (unsigned int)src[i + 12];
    dst += stride;
}
}
