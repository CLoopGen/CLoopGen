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
    uint64_t temp_sum = 0;
    int step = 4;
    for (white = 0; white < 256; white += step) {
        temp_sum += yHistogram[white];
        if (white + 1 < 256) temp_sum += yHistogram[white + 1];
        if (white + 2 < 256) temp_sum += yHistogram[white + 2];
        if (white + 3 < 256) temp_sum += yHistogram[white + 3];
        if (clipped - temp_sum < maxClipped) {
            break;
        }
    }
    clipped -= temp_sum;
}
