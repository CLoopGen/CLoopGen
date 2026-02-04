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
for (b = a = 0; b < 256; b += 2) {
    uint16_t temp1 = cnts[b];
    freqs[2 * b] = temp1;
    freqs[2 * b + 1] = a;
    a += temp1;
    if (b + 1 < 256) {
        uint16_t temp2 = cnts[b + 1];
        freqs[2 * (b + 1)] = temp2;
        freqs[2 * (b + 1) + 1] = a;
        a += temp2;
    }
}
}
