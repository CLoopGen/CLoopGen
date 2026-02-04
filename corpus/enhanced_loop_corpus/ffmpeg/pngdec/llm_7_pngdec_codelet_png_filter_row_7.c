#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_dst;
    if (i > 0) prev_dst = dst[i - bpp];
    for (; i < size; i++) {
        uint8_t current_src = src[i];
        dst[i] = prev_dst + current_src;
        prev_dst = dst[i];
    }
}
