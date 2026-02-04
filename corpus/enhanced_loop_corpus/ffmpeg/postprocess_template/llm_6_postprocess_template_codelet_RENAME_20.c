#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int white;
extern uint64_t * yHistogram;
extern uint64_t maxClipped;
extern uint64_t clipped;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_clipped = clipped;
    for (white = 0; white < 256; white++) {
        if (temp_clipped < maxClipped)
            break;
        temp_clipped -= yHistogram[white];
    }
    clipped = temp_clipped;
}
