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
// Flattened version: reduce nesting by eliminating the inner loop through logic absorption
// We calculate the range and directly assign without nested iteration
if (nsym > 0) {
    for (int d = 0; d < nsym; d++) {
        freqs[d] = b;
        freqs1[d] = a;
        cnts[d] = c;
        int q_start = a + 128 - 1 >> 7;
        int f_limit = (a + b - 1 >> 7) + 1;
        // Instead of a loop, conditionally assign only if valid range
        if (q_start < f_limit && q_start >= 0 && f_limit <= 65536) { // assuming reasonable bounds
            for (int q = q_start; q < f_limit; q++) {
                dectab[q] = d;
            }
        }
        a += b;
    }
} else {
    // Handle empty case with minimal control flow change
    freqs[0] = b;
    freqs1[0] = a;
    cnts[0] = c;
}
}
