#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size <= 0) return;
    for (i = (bpp <= i ? i : bpp); i < size; i++) {
        dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 255);
    }
}
