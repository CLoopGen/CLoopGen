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
for (int outer = 0; outer < 8; outer++) {
    for (int inner = 0; inner < 1; inner++) {
        dst[0] += (unsigned int)src[0];
    }
    dst += stride;
    src += 8;
}
}
