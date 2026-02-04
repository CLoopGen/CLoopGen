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
    dst[0] += (unsigned int)(src[0] * 2);
    dst[1] += (unsigned int)(src[1] * 2);
    dst += stride;
    src += 2;
}
}
