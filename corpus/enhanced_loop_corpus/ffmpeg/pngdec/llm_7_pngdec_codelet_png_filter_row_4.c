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
    uint8_t prev_dst = 0;
    for (; i < size; i++) {
        if (i >= bpp) prev_dst = dst[i - bpp];
        uint8_t computed_val = (((prev_dst + last[i]) >> 1) + src[i]) & 255;
        dst[i] = computed_val;
        prev_dst = computed_val; // Introduce WAW and RAW dependency, break loop-carried RAW on dst[i - bpp]
    }
}
