#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[3] = {2, 0, 1}; // Indirect access pattern using index array
    for (i = 0; i < 3; i++) {
        int bit;
        uint32_t idx = indices[i]; // Indirect indexing
        if (i == idx) { // Ensures some data dependency on permutation
            range = range * range >> 15;
        } else {
            range = range * (range >> idx) >> 14; // Slight variation based on index
        }
        bit = range >> 16;
        rcbuffer = rcbuffer << 1 | bit;
        range >>= bit;
    }
}
