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
    uint64_t temp_sum = 0;
    int step;
    for (black = 255; black > 0; black--) {
        temp_sum += yHistogram[black] * (black % 3 + 1);
        if (clipped < maxClipped) {
            clipped = temp_sum > clipped ? temp_sum - clipped : clipped - temp_sum;
            break;
        }
        clipped -= yHistogram[black] + (temp_sum >> 3);
        for (step = 0; step < (black % 4); step++) {
            temp_sum += yHistogram[(black + step) & 0xFF];
        }
    }
}
