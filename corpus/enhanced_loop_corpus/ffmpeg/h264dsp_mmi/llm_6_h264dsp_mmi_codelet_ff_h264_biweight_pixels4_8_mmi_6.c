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
    uint8_t temp;
    for (y = 0; y < height; y++ , dst += stride , src += stride) {
        temp = src[0];
        dst[0] = temp + 1;
    }
}
