#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t nsym;
extern uint16_t *freqs;
extern uint16_t *freqs1;
extern uint16_t *cnts;
extern uint8_t *dectab;
extern uint32_t a;
extern uint32_t b;
extern uint32_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse the iteration order (strided access in reverse)
for (int d = nsym - 1; d >= 0; d--) {
    freqs[d] = b;
    freqs1[d] = a;
    cnts[d] = c;
    int shift_start = (a + 128 - 1) >> 7;
    int shift_end = (a + b - 1 >> 7) + 1;
    // Access dectab with increasing index, but logic remains same
    for (int q = shift_start; q < shift_end; q++) {
        dectab[q] = d;  // Still writes to consecutive locations in dectab
    }
    a += b;
}
}
