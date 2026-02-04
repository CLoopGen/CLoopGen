#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolling to maintain bounds
    for (i = 0; i < 8; i += 2) {
        if (i < 4) rgba_palette[i] = 0;
    }
}
