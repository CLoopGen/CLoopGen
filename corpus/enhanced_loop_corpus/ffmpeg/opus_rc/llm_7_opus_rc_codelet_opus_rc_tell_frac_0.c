#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_rcbuffer = rcbuffer;
    uint32_t local_range = range;
    for (i = 0; i < 3; i++) {
        int bit = local_range >> 16;
        local_range = local_range * local_range >> 15;
        local_rcbuffer = local_rcbuffer << 1 | bit;
        local_range >>= bit;
    }
    rcbuffer = local_rcbuffer;
    range = local_range;
}
