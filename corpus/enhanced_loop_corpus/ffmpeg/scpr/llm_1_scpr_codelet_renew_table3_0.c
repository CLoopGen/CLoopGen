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
for (int d = 0; d < nsym; d++) {
    freqs[d] = b;
    freqs1[d] = a;
    cnts[d] = c;
    int q_start = a + 128 - 1 >> 7;
    int f_end = (a + b - 1 >> 7) + 1;
    if (q_start < f_end) {
        dectab[q_start] = d; // Flatten inner loop: only assign once, simulating reduced depth
    }
    a += b;
}
}
