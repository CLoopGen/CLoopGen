#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint16_t *dst;
extern int32_t *src;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++) {
    dst[0] += (unsigned int)src[0];
    dst[1] += (unsigned int)src[1];
    dst[2] += (unsigned int)src[2];
    dst[3] += (unsigned int)src[3];
    dst += stride;
    src += 4;
}

}
