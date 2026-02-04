#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t access_pattern[6] = {0, 0, 1, 1, 2, 2}; // Strided and duplicated access pattern
    for (i = 0; i < 3; i++) {
        int bit;
        uint32_t step = access_pattern[i * 2]; // Strided read: use every other element
        range = range * range >> (15 + step);
        bit = range >> 16;
        rcbuffer = (rcbuffer << 1) | bit;
        range >>= bit;
    }
}
