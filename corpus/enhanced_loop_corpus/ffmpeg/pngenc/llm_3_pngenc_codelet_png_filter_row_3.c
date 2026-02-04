#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *top;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access pattern
    // Iterates from the last element to the first
    for (i = bpp - 1; i >= 0; i--) {
        dst[i] = src[i] - (top[i] >> 1);
    }
}
