#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    int bit = (range >> 16) & 1;
    range = range * range >> 15;
    if (bit & 1) {
        rcbuffer = (rcbuffer << 1) | 1;
        range >>= 1;
    } else {
        rcbuffer = rcbuffer << 1;
        range >>= 0;
    }
}
}
