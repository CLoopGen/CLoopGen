#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by removing stride dependency
    // Instead of strided access, accumulate from consecutive src elements starting at index 0
    for (i = 0; i < 16; i++) {
        dc += src[i];
    }
}
