#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int black;
extern uint64_t * yHistogram;
extern uint64_t maxClipped;
extern uint64_t clipped;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic
    uint64_t *ptr = yHistogram + 255;  // Point to yHistogram[255]
    for (black = 255; black > 0; black--) {
        if (clipped < maxClipped)
            break;
        clipped -= *(ptr--);  // Decrement pointer, indirect access in reverse order
    }
}
