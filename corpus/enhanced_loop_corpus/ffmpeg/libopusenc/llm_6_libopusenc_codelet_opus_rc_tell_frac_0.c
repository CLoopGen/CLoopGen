#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_range = range;
    for (i = 0; i < 3; i++) {
        int bit;
        temp_range = temp_range * temp_range >> 15;
        bit = temp_range >> 16;
        rcbuffer = rcbuffer << 1 | bit;
        temp_range >>= bit;
    }
    range = temp_range;
}
