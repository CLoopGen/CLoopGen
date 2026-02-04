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
    uint16_t local_offs[16];
    for (int i = 0; i < 16; i++)
        local_offs[i] = offs[i];
    for (sym = 0; sym < codes; sym++) {
        if (lens[sym] != 0) {
            uint16_t len = lens[sym];
            work[local_offs[len]++] = (uint16_t)sym;
        }
    }
    for (int i = 0; i < 16; i++)
        offs[i] = local_offs[i];
}
