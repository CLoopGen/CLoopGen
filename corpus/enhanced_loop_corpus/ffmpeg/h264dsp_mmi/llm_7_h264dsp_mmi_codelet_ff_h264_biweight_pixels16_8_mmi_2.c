#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_accum = 0;
    for (y = 0; y < height; y++, dst += stride, src += stride) {
        local_accum ^= src[0];
        dst[0] = local_accum;
    }
    dst[-stride] = local_accum; // Break potential WAW by writing only once after loop
}
