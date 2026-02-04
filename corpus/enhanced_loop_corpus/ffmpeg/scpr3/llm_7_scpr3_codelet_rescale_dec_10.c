#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t cnts[256];
extern uint16_t freqs[512];
extern int b;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_accum = a;
    for (b = 0; b < 256; b++) {
        freqs[2 * b] = cnts[b];
        freqs[2 * b + 1] = local_accum;
        local_accum += cnts[b];
    }
    a = local_accum;
}
