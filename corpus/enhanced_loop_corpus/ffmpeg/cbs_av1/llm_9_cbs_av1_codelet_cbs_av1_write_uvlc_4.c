#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced arithmetic intensity with unrolled-like behavior using step control
    for (j = 0; j < zeroes; j += 2) {
        int pos1 = zeroes - j - 1;
        int pos2 = pos1 - 1;
        if (j < zeroes) {
            bits[i++] = (v >> pos1 & 1) ? '1' : '0';
        }
        if (j + 1 < zeroes) {
            bits[i++] = (v >> pos2 & 1) ? '1' : '0';
        }
    }
}
