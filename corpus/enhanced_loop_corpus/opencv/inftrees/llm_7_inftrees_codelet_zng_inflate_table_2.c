#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_count[16];
    for (max = 0; max < 16; max++) {
        local_count[max] = count[15 - max]; // Remove loop-carried dependence by pre-swapping into local array (eliminates RAW across iterations)
    }
    for (max = 0; max < 15; max++) {       // Forward loop with no backward index
        if (local_count[max] != 0) {
            max = 14 - max;               // WAR hazard introduced: writing max used in loop condition and later
            break;
        }
    }
    max = (max >= 0) ? 15 - max : max;     // Resolve logical value of max as in original (converge to same semantic result)
}
