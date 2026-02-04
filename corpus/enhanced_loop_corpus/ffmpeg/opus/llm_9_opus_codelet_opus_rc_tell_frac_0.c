#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    int bit1, bit2;
    uint32_t temp1 = range * range >> 16;
    uint32_t temp2 = temp1 * temp1 >> 16;
    bit1 = temp1 >> 15;
    bit2 = temp2 >> 15;
    rcbuffer = rcbuffer << 2 | (bit1 << 1) | bit2;
    range = temp2 >> bit2;
}
}
