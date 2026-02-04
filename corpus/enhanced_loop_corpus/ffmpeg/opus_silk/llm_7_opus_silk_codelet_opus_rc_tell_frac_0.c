#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_range[3];
    uint32_t local_rcbuffer = rcbuffer;
    local_range[0] = range;
    for (i = 0; i < 3; i++) {
        int bit;
        if (i > 0) {
            local_range[i] = local_range[i-1] * local_range[i-1] >> 15;
        }
        if (i == 0) {
            local_range[i] = local_range[i] * local_range[i] >> 15;
        }
        bit = local_range[i] >> 16;
        local_rcbuffer = local_rcbuffer << 1 | bit;
        local_range[i] >>= bit;
    }
    range = local_range[2];
    rcbuffer = local_rcbuffer;
}
