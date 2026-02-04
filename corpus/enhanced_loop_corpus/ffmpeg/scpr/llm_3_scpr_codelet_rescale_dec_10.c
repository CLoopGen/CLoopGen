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
    uint16_t *f = freqs;
    for (b = a = 0; b < 256; b++) {
        *(f++) = cnts[b];
        *(f++) = a;
        a += cnts[b];
    }
}
