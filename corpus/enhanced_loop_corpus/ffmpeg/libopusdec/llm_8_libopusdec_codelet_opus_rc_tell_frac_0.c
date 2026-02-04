#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    int bit;
    range = range * range >> 14;
    range = range + (range >> 8);
    bit = range >> 17;
    rcbuffer = rcbuffer << 1 | bit;
    rcbuffer = rcbuffer ^ (bit << 2);
    range >>= bit;
}
}
