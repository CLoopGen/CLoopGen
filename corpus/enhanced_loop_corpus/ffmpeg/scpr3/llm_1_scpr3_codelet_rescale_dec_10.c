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
for (b = a = 0; b < 1; b++) {
    for (int outer = 0; outer < 256; outer++) {
        freqs[2 * outer] = cnts[outer];
        freqs[2 * outer + 1] = a;
        a += cnts[outer];
    }
}
}
