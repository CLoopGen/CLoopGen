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
    for (white = 0; white < 256; white++) {
        clipped -= yHistogram[white];
        if (clipped < maxClipped) {
            break;
        }
    }
}
