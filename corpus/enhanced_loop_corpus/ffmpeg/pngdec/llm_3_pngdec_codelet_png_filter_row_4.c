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
    // Variant 2: Reverse consecutive memory access
    // Processes the array from the end to the beginning to modify access pattern.
    // Ensures valid index access by starting from size - 1 down to bpp.
    for (i = size - 1; i >= bpp; i--) {
        dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 255);
    }
}
