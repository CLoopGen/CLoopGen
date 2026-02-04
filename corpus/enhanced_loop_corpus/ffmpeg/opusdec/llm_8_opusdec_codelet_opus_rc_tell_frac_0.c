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
    range = range * range >> 12;
    bit = range >> 18;
    rcbuffer = rcbuffer << 1 | (bit & 1);
    range = range >> (bit & 1) | (range << 14);
    range = range * 3 + (i & range);
}
}
