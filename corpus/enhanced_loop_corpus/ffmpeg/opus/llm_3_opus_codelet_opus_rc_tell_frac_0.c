#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t access_pattern[6] = {0}; // Strided write pattern buffer
    for (i = 0; i < 3; i++) {
        int bit;
        range = range * range >> 15;
        bit = range >> 16;
        rcbuffer = rcbuffer << 1 | bit;
        range >>= bit;
        access_pattern[2 * i] = range; // Strided access: every other element
    }
}
