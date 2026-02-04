#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *lens;
extern unsigned int codes;
extern uint16_t *work;
extern unsigned int sym;
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int limit = (codes > 16) ? 16 : codes;
    for (sym = 0; sym < limit; sym++) {
        uint16_t current_len = lens[sym];
        uint16_t mask = (current_len != 0) ? 0xFFFF : 0x0000;
        uint16_t index = offs[current_len];
        work[index & mask] = (uint16_t)sym;
        offs[current_len] += (mask == 0xFFFF) ? 1 : 0;
    }
}
