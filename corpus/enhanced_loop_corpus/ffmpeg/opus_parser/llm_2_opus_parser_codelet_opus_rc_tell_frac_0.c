#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[3] = {0, 1, 2};
    for (i = 0; i < 3; i++) {
        int bit;
        uint32_t idx = indices[i]; // Indirect access via index array
        range = range * range >> (15 + idx); // Slight data dependence on index
        bit = range >> 16;
        rcbuffer = rcbuffer << 1 | bit;
        range >>= bit;
    }
}
