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
        int offset = i * stride;
        dst[offset + 0] += (unsigned int)src[i * 4 + 0];
        dst[offset + 1] += (unsigned int)src[i * 4 + 1];
        dst[offset + 2] += (unsigned int)src[i * 4 + 2];
        dst[offset + 3] += (unsigned int)src[i * 4 + 3];
    }
}
