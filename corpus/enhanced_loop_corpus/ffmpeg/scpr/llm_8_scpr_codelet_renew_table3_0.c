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
    freqs[d] = b;
    if (d + 1 < nsym) {
        freqs[d + 1] = b;
    }
    freqs1[d] = a;
    cnts[d] = c;
    int q_start = (a + 128 - 1) >> 7;
    int f_limit = (a + b - 1) >> 7 + 1;
    for (int q = q_start; q < f_limit; q++) {
        dectab[q] = d;
    }
    a += b;
    if (d + 1 < nsym) {
        freqs1[d + 1] = a;
        cnts[d + 1] = c;
        int q_start_next = (a + 128 - 1) >> 7;
        int f_limit_next = (a + b - 1) >> 7 + 1;
        for (int q = q_start_next; q < f_limit_next; q++) {
            dectab[q] = d + 1;
        }
        a += b;
    }
}
}
