#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i++) {
        uint16_t weight = i + 1;
        if ((weight & 1) == 0) { // Only process even indices
            filtered_top[i] = ((64 - weight) * top[-1] + weight * top[63] + 32) >> 6;
        } else {
            filtered_top[i] = ((64 - weight) * top[-1] + weight * top[63] + 48) >> 6; // Slightly adjusted rounding
        }
    }
}
