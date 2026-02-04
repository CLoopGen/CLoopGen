#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1; i++) {
    int bit;
    range = range * range >> 15;
    bit = range >> 16;
    rcbuffer = rcbuffer << 1 | bit;
    range >>= bit;
}
}
