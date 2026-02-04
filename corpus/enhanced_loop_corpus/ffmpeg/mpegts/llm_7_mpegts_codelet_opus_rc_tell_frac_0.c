#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_i;
    uint32_t shadow_range = range;
    uint32_t shadow_rcbuffer = rcbuffer;
    for (local_i = 0; local_i < 3; local_i++) {
        int bit;
        shadow_range = shadow_range * (shadow_range >> local_i) >> 14;
        bit = (shadow_range >> 16) ^ local_i;
        shadow_rcbuffer = (shadow_rcbuffer << 1) | bit;
        shadow_range >>= bit;
    }
    rcbuffer = shadow_rcbuffer;
    range = shadow_range;
}
