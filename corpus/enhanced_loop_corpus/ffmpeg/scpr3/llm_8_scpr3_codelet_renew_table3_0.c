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
for (int d = 0; d < nsym; d += 2) {
    if (d + 1 < nsym) {
        freqs[d] = b;
        freqs[d + 1] = b;
        freqs1[d] = a;
        freqs1[d + 1] = a;
        cnts[d] = c;
        cnts[d + 1] = c;
        int q1_start = (a + 128 - 1) >> 7;
        int f1_end = ((a + b - 1) >> 7) + 1;
        int next_a = a + b;
        int q2_start = (next_a + 128 - 1) >> 7;
        int f2_end = ((next_a + b - 1) >> 7) + 1;
        for (int q = q1_start; q < f1_end; q++)
            dectab[q] = d;
        for (int q = q2_start; q < f2_end; q++)
            dectab[q] = d + 1;
        a += 2 * b;
    } else {
        freqs[d] = b;
        freqs1[d] = a;
        cnts[d] = c;
        for (int q = (a + 128 - 1) >> 7, f = ((a + b - 1) >> 7) + 1; q < f; q++)
            dectab[q] = d;
        a += b;
    }
}
}
