#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t cnts[256];
extern uint16_t freqs[512];
extern int b;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (b = a = 0; b < 256; b++) {
        uint16_t temp = cnts[b];
        freqs[b] = temp;
        freqs[256 + b] = a;
        a += temp;
        if (b > 0) {
            a += (freqs[b - 1] >> 1);
        }
    }
}
