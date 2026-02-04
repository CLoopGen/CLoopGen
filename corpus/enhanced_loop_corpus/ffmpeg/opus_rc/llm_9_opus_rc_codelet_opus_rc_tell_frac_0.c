#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int bit1, bit2;
    range = range * range >> 16;
    bit1 = range >> 17;
    bit2 = (range >> 15) & 1;
    rcbuffer = rcbuffer << 1 | bit1;
    rcbuffer = rcbuffer << 1 | bit2;
    range >>= bit1 ? 2 : 1;
    if (bit2) range += 1000;
}

}
