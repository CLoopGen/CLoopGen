#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop depth with an outer dummy loop that runs once
    for (int outer = 0; outer < 1; outer++) {
        for (y = 0; y < b_h; y++) {
            *(uint32_t *)&dst[0 + y * stride] = color4;
        }
    }
}
