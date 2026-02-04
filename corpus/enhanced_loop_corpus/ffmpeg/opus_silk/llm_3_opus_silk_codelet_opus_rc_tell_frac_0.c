#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t stride = 2;
    for (i = 0; i < 5; i += stride) { // Strided iteration (step by 2)
        int bit;
        // Simulate consistent behavior despite strided control flow
        range = range * range >> 15;
        bit = range >> 16;
        rcbuffer = (rcbuffer << 1) | bit;
        range >>= bit;
        if (i == 4) break; // Prevent overshoot due to stride
    }
}
