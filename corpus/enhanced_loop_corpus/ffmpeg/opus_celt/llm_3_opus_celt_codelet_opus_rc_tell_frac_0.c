#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_range[3];
    uint32_t temp_rcbuffer = rcbuffer;
    for (i = 0; i < 3; i++) {
        int bit;
        // Simulate strided memory-like behavior using array with stride of 1
        temp_range[i] = (i == 0) ? range : (temp_range[i-1] * temp_range[i-1] >> 15);
        bit = temp_range[i] >> 16;
        temp_rcbuffer = temp_rcbuffer << 1 | bit;
    }
    // Final update to global state after batch processing
    range = temp_range[2];
    rcbuffer = temp_rcbuffer;
}
