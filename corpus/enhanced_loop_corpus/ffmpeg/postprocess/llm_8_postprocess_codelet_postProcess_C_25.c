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
    for (black = 255; black > 16; black -= 2) {
        if (clipped < maxClipped)
            break;
        clipped -= (yHistogram[black] + yHistogram[black - 1]);
    }
}
