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
    uint64_t local_sum = 0;
    for (white = 0; white < 256; white++) {
        local_sum += yHistogram[white];
        if ((int64_t)(clipped - local_sum) < (int64_t)maxClipped)
            break;
    }
    clipped -= local_sum;
}
