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
    uint64_t temp_clipped = clipped;
    for (black = 255; black > 0; black--) {
        if (temp_clipped < maxClipped)
            break;
        temp_clipped -= yHistogram[black];
    }
    clipped = temp_clipped;
}
