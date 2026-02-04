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
    for (b = a = 0; b < 128; b++) {
        freqs[4 * b] = cnts[2 * b];
        freqs[4 * b + 1] = a;
        a += cnts[2 * b];
        freqs[4 * b + 2] = cnts[2 * b + 1];
        freqs[4 * b + 3] = a;
        a += cnts[2 * b + 1];
    }
}
