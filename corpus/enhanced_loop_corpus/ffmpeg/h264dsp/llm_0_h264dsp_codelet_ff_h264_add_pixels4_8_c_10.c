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
int j;
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        dst[j] += (unsigned int)src[j];
    }
    dst += stride;
    src += 4;
}
}
