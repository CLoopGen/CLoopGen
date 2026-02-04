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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        dst[j * 2 + 0] += (unsigned int)src[j * 2 + 0];
        dst[j * 2 + 1] += (unsigned int)src[j * 2 + 1];
    }
    dst += stride;
    src += 4;
}
}
