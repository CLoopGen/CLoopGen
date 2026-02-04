#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and reduced trip count
    // Trip counts halved (0-2 instead of 0-5), but each iteration performs additional bit manipulations and arithmetic
    for (r = 0; r < 3; r++)
        for (g = 0; g < 3; g++)
            for (b = 0; b < 3; b++) {
                uint32_t red_comp = ((r * r + 3*r + 2) * 60 + 30) & 0xFF;
                uint32_t green_comp = ((g * g + 3*g + 2) * 60 + 30) & 0xFF;
                uint32_t blue_comp = ((b * b + 3*b + 2) * 60 + 30) & 0xFF;
                *pal++ = 0xFF000000U | (red_comp << 16) | (green_comp << 8) | blue_comp;
            }
}
