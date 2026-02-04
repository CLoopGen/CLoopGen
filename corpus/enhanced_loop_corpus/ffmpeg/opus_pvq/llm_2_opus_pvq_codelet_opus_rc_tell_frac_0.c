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
    int bit;
    // Modify memory access pattern by introducing a small lookup table and strided read (stride of 2)
    static uint32_t range_table[6] = {1000, 1500, 2000, 2500, 3000, 3500};
    range = range * range_table[i * 2] >> 15;
    bit = range >> 16;
    rcbuffer = rcbuffer << 1 | bit;
    range >>= bit;
}
}
