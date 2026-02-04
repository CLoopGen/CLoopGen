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
    uint64_t local_clipped = clipped;
    uint64_t *hist = yHistogram;
    int b = black;
    for (int i = 255; i > 0; i--) {
        if (local_clipped < maxClipped)
            break;
        local_clipped -= hist[i];
        b = i - 1;
    }
    black = b;
    clipped = local_clipped;
}
