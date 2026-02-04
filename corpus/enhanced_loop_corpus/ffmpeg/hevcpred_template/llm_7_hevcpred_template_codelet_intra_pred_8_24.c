#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    filtered_top[0] = (63 * top[-1] + 1 * top[63] + 32) >> 6;
    for (i = 1; i < 63; i++) {
        int weight_prev = 64 - i;
        int weight_curr = i;
        filtered_top[i] = (weight_prev * top[-1] + weight_curr * top[63] + 32) >> 6;
        // Introduce artificial loop-carried dependency: each result depends on prior write
        filtered_top[i] += (filtered_top[i-1] & 0x1F);  // RAW dependency introduced
    }
}
