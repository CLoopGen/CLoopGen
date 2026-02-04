#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t i;
extern uint32_t rcbuffer;
extern uint32_t range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use consecutive array access with reversed iteration to modify access pattern
static uint32_t buffer[3] = {0x12345, 0x6789A, 0xBCDEF};
for (i = 0; i < 3; i++) {
    int bit;
    // Access buffer elements consecutively in normal order
    range = (range * buffer[i]) >> 15;
    bit = range >> 16;
    rcbuffer = (rcbuffer << 1) | bit;
    range >>= bit;
}
}
